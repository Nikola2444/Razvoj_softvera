// Copyright [2018] <nikola>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <dirent.h>
#include <unistd.h>
#include "./taster_led_funcs.h"
int main(int arcg, char **argv) {
  if(argv[1]==NULL)
    return 0;
  int port = atoi(argv[1]);

  printf ("port value is: %d", port);
  fflush(stdout);
  int led_value;
  int n;
  FILE *html_data;
  char led_val[10];
  char http_begin[100] = "<html><body>";
  char http_end[100] = "</body></html>";
  char http_full[100] = "";
  int i = 0;
  char buffer [255];

  // response
  char http_header[2048] = "HTTP/1.1 200 OK\r\nContent-Type: text/html;charset=UTF-8\r\n\r\n";
  
  strcat(http_header, http_begin);
  // create a socketx
  int server_socket;
  int client_socket;
  server_socket = socket(AF_INET, SOCK_STREAM, 0);
  // define the address
  struct sockaddr_in server_address;
  struct sockaddr_in client_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(port);
  server_address.sin_addr.s_addr = INADDR_ANY;
  

  bind(server_socket, (struct sockaddr *) &server_address,
       sizeof(server_address));
  listen(server_socket, 15);
  int clilen = sizeof(client_address);
  while (1) {
    client_socket = accept(server_socket, (struct sockaddr*)& client_address, &clilen);
    if (client_socket < 0) {
      printf("error on accept");      
      continue;
    }
    int pid = fork();
    
    if (pid < 0) {
      printf("fork didnt work");
      exit(1);
    }
    if (pid == 0) {
      close(server_socket);      
      n = 255;
      // dummy receive from browser
      while(n == 255){
        n = recv(client_socket, buffer, 255, 0);
        printf("\nrecv is: %s", buffer);
      }
      printf("\nclient is trying to connect from address:%s;port: %d", inet_ntoa(client_address.sin_addr), client_address.sin_port);      
      read_leds(led_val);   
      strcpy(http_full, http_header);
      strcat(http_full, led_val);
      strcat(http_full, http_end);      
      // writing to client      
      write(client_socket, http_full, sizeof(http_full));           
      
      close(client_socket);
      exit(0);
      
    }
    if(pid > 0){
      close(client_socket);
      continue;
    }
  }
  return 0;
}


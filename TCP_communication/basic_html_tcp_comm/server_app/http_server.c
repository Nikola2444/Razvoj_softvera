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
int main() {
  int led_value;
  FILE *html_data;
  html_data = fopen("Index.html", "w");
  char *led_val;
  char http_begin[100] = "<html><body>";
  char http_end[100] = "</body></html>";
  char http_full[100] = "";



  // response
  char http_header[2048] = "HTTP/1.1 200 OK\r\n\n";
  strcat(http_header, http_begin);
  // create a socketx
  int server_socket;
  server_socket = socket(AF_INET, SOCK_STREAM, 0);
  // define the address
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(80);
  server_address.sin_addr.s_addr = INADDR_ANY;

  bind(server_socket, (struct sockaddr *) &server_address,
       sizeof(server_address));
  listen(server_socket, 5);
  int client_socket;
  while (1) {
    client_socket = accept(server_socket, NULL, NULL);
    printf("\npage refreshed\n");    
    led_val = read_leds();
    printf("\nled_value is: %s", led_value);
    fflush(stdout);
    strcpy(http_full, http_header);
    strcat(http_full, led_val);
    strcat(http_full, http_end);
    printf("\n%s", http_full);
    fflush(stdout);
    send(client_socket, http_full, sizeof(http_full), 0);    
    close(client_socket);

  }
  return 0;
}


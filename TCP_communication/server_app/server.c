// Copyright [2018] <nikola>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <dirent.h>
#include <string.h>

int main() {
  char server_message[256] = "you have reached the server";
  int server_socket, clilen;
  server_socket = socket(AF_INET, SOCK_STREAM, 0);

  // define the server adress
  struct sockaddr_in server_address, client_addr;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(9002);
  server_address.sin_addr.s_addr = INADDR_ANY;

  // bind the socket to out specified IP and port
  bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));

  listen (server_socket, 5);

  int client_socket;
  client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &clilen);

  send (client_socket, server_message, sizeof(server_message), 0);
  close(socket);
  return 0;
}


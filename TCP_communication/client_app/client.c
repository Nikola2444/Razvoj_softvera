// Copyright [2018] <nikola>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <dirent.h>
#include <string.h>

int main() {
  int network_socket;
  network_socket = socket(AF_INET, SOCK_STREAM, 0);

  // specify an address for the socket
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(9002);
  server_address.sin_addr.s_addr = INADDR_ANY;

  int connection_status = connect(network_socket,
                                  (struct sockaddr *)&server_address,
                                  sizeof(server_address));
  if (connection_status == -1) {
    printf("something went wrong with the connection");
  }

  // receive data from the server
  char server_response[256];
  recv(network_socket, &server_response, sizeof(server_response), 0);

  // print out serve's response
  printf("The server sent the data: %s\n", server_response);
  return 0;
}



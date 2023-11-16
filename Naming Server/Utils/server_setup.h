#ifndef SERVER_SETUP_H
#define SERVER_SETUP_H

#include "utils.h"

int createServerSocket()
{
  int server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd == 0)
  {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }
  return server_fd;
}

void bindServerSocket(int server_fd, struct sockaddr_in *address)
{
  if (bind(server_fd, (struct sockaddr *)address, sizeof(*address)) < 0)
  {
    perror("bind failed");
    close(server_fd);
    exit(EXIT_FAILURE);
  }
}

void startListening(int server_fd)
{
  if (listen(server_fd, 3) < 0)
  {
    perror("listen");
    exit(EXIT_FAILURE);
  }
}

int acceptConnection(int server_fd, struct sockaddr_in *address,
                     char *ip_buffer)
{
  int addrlen = sizeof(*address);
  int new_socket =
      accept(server_fd, (struct sockaddr *)address, (socklen_t *)&addrlen);
  if (new_socket < 0)
  {
    perror("accept");
    exit(EXIT_FAILURE);
  }

  // Copy the IP address to the provided buffer
  strncpy(ip_buffer, inet_ntoa(address->sin_addr), INET_ADDRSTRLEN);
  ip_buffer[INET_ADDRSTRLEN - 1] = '\0'; // Null-terminate the string

  return new_socket;
}

void sendMessage(int socket, char *message)
{
  send(socket, message, strlen(message), 0);
  printf("Message sent!\n");
}

#endif // SERVER_SETUP_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#define GRN "\e[0;32m"
#define RED "\e[0;31m"
#define reset "\e[0m"

char *create(char *filename) {
  printf(GRN "Creating file %s" reset, filename);
  return GRN "Creating the file " reset;
}

char *delete_file(char *filename) {

  printf(GRN "Deleting file %s\n" reset, filename);
  return GRN "Deleting the file" reset;
}

char *read_file(char *filename) {
  printf(GRN "Reading file %s\n" reset, filename);
  ValueStruct *myStruct;
  if ((myStruct = find(accessible_paths_hashmap, filename)) == NULL) {
    printf(RED "File not found\n" reset);
    return RED "File not found" reset;
  }
  
  // printf("IP is: %s\n", myStruct->ip);
  // printf("Client port is: %d\n", myStruct->client_port);
  // printf("NM port is: %d\n", myStruct->nm_port);
  // printf("Num readers is: %d\n", myStruct->num_readers);
  // printf("Is writing is: %d\n", myStruct->isWriting);
  // printf(GRN"IP is: %s\n"reset, myStruct->ip);

  char response[1024];
  strcpy(response, "lookup response\nip:");
  strcat(response, myStruct->ip);
  strcat(response, "\nclient_port:");
  char client_port[20];
  sprintf(client_port, "%d", myStruct->client_port);
  strcat(response, client_port);

  char *response_final = (char *)malloc(10000 * sizeof(char));
  strcpy(response_final, response);
  return response_final;
}

char *write_file(char *filename, char *data) {
  printf(GRN "Writing '%s' to file %s\n" reset, data, filename);
  return GRN "Writing to the file" reset;
}

char *copy(char *filename1, char *filename2) {
  printf(GRN "Copying file %s to %s\n" reset, filename1, filename2);
  return GRN "Copying the file" reset;
}

char *get_info(char *filename) {
  printf(GRN "Getting info of file %s\n" reset, filename);
  return GRN "Getting info of the file" reset;
}

char *LS(char *filename) {
  printf(GRN "Listing files in directory %s\n" reset, filename);
  return GRN "Listing files in the directory" reset;
}

char *operation_handler(char **inputs, int num_inputs) {
  if (num_inputs == 2) {
    if (strcmp(inputs[0], "CREATE") == 0) {
      return create(inputs[1]);
    } else if (strcmp(inputs[0], "DELETE") == 0) {
      return delete_file(inputs[1]);
    } else if (strcmp(inputs[0], "READ") == 0) {
      return read_file(inputs[1]);
    } else if (strcmp(inputs[0], "GETINFO") == 0) {
      return get_info(inputs[1]);
    } else if (strcmp(inputs[0], "LS") == 0) {
      return LS(inputs[1]);
    } else {
      printf(RED "Encountered invalid operation\n" reset);
      return RED "Invalid operation" reset;
    }

  } else if (num_inputs == 3) {

    if (strcmp(inputs[0], "COPY") == 0) {
      return copy(inputs[1], inputs[2]);
    } else {
      printf(RED "Encountered invalid Operation\n" reset);
      return RED "Invalid operation" reset;
    }
  } else if (strcmp(inputs[0], "WRITE") == 0) {
    char *content = (char *)malloc(10000 * sizeof(char));
    for (int i = 2; i < num_inputs; i++) {
      strcat(content, inputs[i]);
      if (i != num_inputs - 1) {
        strcat(content, " ");
      }
    }
    return write_file(inputs[1], content);
  } else {
    printf(RED "Encountered invalid Operation\n" reset);
    return RED "Invalid operation" reset;
  }
}
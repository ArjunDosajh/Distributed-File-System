# DISTRIBUTED FILE SYSTEM

## Description

Distributed File System by creating a nameserver which stores the mapping of the file path to the storage server and the storage server which stores the file and the client which can access the file from the storage server.

To know more about the project refer to the [Project PDF](./Course%20Project%20Operating%20Systems%20and%20Networks.pdf) </a>

## Running the code

To run the code, run the following commands in different terminals followed by the instructions for Storage Server and the client

```
make naming_server
make storage_server
make client
```

You can find out the IP address of the naming server by running the following command (required for the Client and the Storage Server)

```
hostname -I
```

## File System

### Naming Server

- main.c
- server_setup.h
- hashmap.h
- client_handler.h
- SS_handler.h
- operation_handler.h
- utils.h

### Storage Server

- main.c
- server_setup.h
- get_accessible_paths.h
- client_handler.h
- operation_handler.h
- utils.h

### Client

- main.c
- server_setup.h
- operation_handler.h
- utils.h

## Developers

**OSN Team 05**

1. **Name**: Arjun Dosajh  
   **Roll Number**: 2021113016
2. **Name**: Hardik Mittal  
   **Roll Number**: 2021114016
3. **Name**: Mihika Sanghi  
   **Roll Number**: 2021113014

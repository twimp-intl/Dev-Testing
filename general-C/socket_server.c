#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>

#define SOCKET_PATH "/run/systemd/io.system.ManagedOOM"
#define BUFFER_SIZE 100

int main() {
    int server_sock, client_sock;
    struct sockaddr_un server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    socklen_t client_addr_len = sizeof(client_addr);

    // Create a Unix domain socket
    server_sock = socket(AF_UNIX, SOCK_STREAM, 0);
    if (server_sock == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set up the address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sun_family = AF_UNIX;
    strncpy(server_addr.sun_path, SOCKET_PATH, sizeof(server_addr.sun_path) - 1);

    // Remove the socket file if it already exists
    unlink(SOCKET_PATH);

    // Bind the socket to the address
    if (bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_sock, 1) == -1) {
        perror("listen");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on %s...\n", SOCKET_PATH);

    // Accept a connection from a client
    client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &client_addr_len);
    if (client_sock == -1) {
        perror("accept");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    // Read message from the client
    ssize_t num_bytes = read(client_sock, buffer, sizeof(buffer) - 1);
    if (num_bytes == -1) {
        perror("read");
        close(client_sock);
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    buffer[num_bytes] = '\0';  // Null-terminate the received data
    printf("Received from client: %s\n", buffer);

    // Send a response to the client
    const char *response = "hi";
    if (write(client_sock, response, strlen(response)) == -1) {
        perror("write");
        close(client_sock);
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    // Close sockets
    close(client_sock);
    close(server_sock);
    unlink(SOCKET_PATH);

    return 0;
}

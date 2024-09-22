#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>

#define SOCKET_PATH "/run/systemd/io.system.ManagedOOM"
#define BUFFER_SIZE 100

int main() {
    int sock;
    struct sockaddr_un server_addr;
    char buffer[BUFFER_SIZE];
    
    // Create a Unix domain socket
    sock = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set up the address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sun_family = AF_UNIX;
    strncpy(server_addr.sun_path, SOCKET_PATH, sizeof(server_addr.sun_path) - 1);

    // Connect to the server
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Send a message to the server
    const char *message = "hello";
    if (write(sock, message, strlen(message)) == -1) {
        perror("write");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Read the response from the server
    ssize_t num_bytes = read(sock, buffer, sizeof(buffer) - 1);
    if (num_bytes == -1) {
        perror("read");
        close(sock);
        exit(EXIT_FAILURE);
    }

    buffer[num_bytes] = '\0';  // Null-terminate the received data
    printf("Received from server: %s\n", buffer);

    // Close the socket
    close(sock);

    return 0;
}

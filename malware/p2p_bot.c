#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 12345
#define BUFFER_SIZE 1024

void execute_command(const char *command) {
    if (strcmp(command, "hello") == 0) {
        printf("Received 'hello' command.\n");
    } else {
        printf("Unknown command: %s\n", command);
    }
}

void handle_connection(int peer_sock) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_received;

    while ((bytes_received = recv(peer_sock, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0'; // Null-terminate the string
        execute_command(buffer);
    }

    if (bytes_received < 0) {
        perror("recv");
    }

    close(peer_sock);
}

int main() {
    int sockfd, peer_sock, new_sock;
    struct sockaddr_in server_addr, peer_addr;
    socklen_t peer_addr_len = sizeof(peer_addr);
    struct sockaddr_in peer_list[] = {
        {AF_INET, htons(PORT), inet_addr("127.0.0.1")}
        // Add more peers here
    };
    size_t num_peers = sizeof(peer_list) / sizeof(peer_list[0]);
    char buffer[BUFFER_SIZE];
    ssize_t bytes_sent;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind and listen
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, 5) < 0) {
        perror("listen");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Connect to peers
    for (size_t i = 0; i < num_peers; i++) {
        peer_sock = socket(AF_INET, SOCK_STREAM, 0);
        if (peer_sock < 0) {
            perror("socket");
            continue;
        }

        if (connect(peer_sock, (struct sockaddr *)&peer_list[i], sizeof(peer_list[i])) == 0) {
            strcpy(buffer, "hello\n");
            bytes_sent = send(peer_sock, buffer, strlen(buffer), 0);
            if (bytes_sent < 0) {
                perror("send");
            }
        } else {
            perror("connect");
        }

        close(peer_sock);
    }

    // Handle incoming connections
    while ((new_sock = accept(sockfd, (struct sockaddr *)&peer_addr, &peer_addr_len)) >= 0) {
        if (fork() == 0) {
            // Child process to handle connection
            close(sockfd);
            handle_connection(new_sock);
            exit(0);
        }
        close(new_sock);
    }

    if (new_sock < 0) {
        perror("accept");
    }

    close(sockfd);
    return 0;
}

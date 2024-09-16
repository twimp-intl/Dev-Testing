#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define SERVER_PORT 6667
#define BUFFER_SIZE 512

void send_message(int sockfd, const char *message) {
    send(sockfd, message, strlen(message), 0);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <server> <port> <channel>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *server = argv[1];
    const char *port = argv[2];
    const char *channel = argv[3];

    struct sockaddr_in server_addr;
    struct hostent *host_info;
    int sockfd;
    char buffer[BUFFER_SIZE];

    // Resolve server address
    host_info = gethostbyname(server);
    if (!host_info) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set up server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(port));
    memcpy(&server_addr.sin_addr, host_info->h_addr, host_info->h_length);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Send NICK and USER commands
    send_message(sockfd, "NICK myBot\r\n");
    send_message(sockfd, "USER myBot 0 * :myBot\r\n");

    // Join the channel
    char join_command[BUFFER_SIZE];
    snprintf(join_command, sizeof(join_command), "JOIN %s\r\n", channel);
    send_message(sockfd, join_command);

    // Send hello message
    send_message(sockfd, "PRIVMSG #myChannel :Hello, I am a bot!\r\n");

    // Wait for a bit before quitting
    sleep(5);

    // Quit
    send_message(sockfd, "QUIT :Goodbye!\r\n");

    // Close socket
    close(sockfd);

    return 0;
}

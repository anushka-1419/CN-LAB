
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 10242
#define BUF_SIZE 1024

#define SERVER_IP "192.168.1.10"

int main()
{
    int sock;
    struct sockaddr_in server;
    char buffer[BUF_SIZE];

    sock = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    inet_pton(AF_INET, SERVER_IP, &server.sin_addr);

    if (connect(sock, (struct sockaddr *)&server,
                sizeof(server)) < 0) {
        perror("Connection failed");
        return 1;
    }

    printf("Connected to server!\n");

    while (1)
    {
        printf("Enter message: ");

        fgets(buffer, BUF_SIZE, stdin);

        send(sock, buffer, strlen(buffer), 0);

        memset(buffer, 0, BUF_SIZE);

        int bytes = recv(sock, buffer, BUF_SIZE, 0);

        if (bytes <= 0)
            break;

        printf("Server Echo: %s", buffer);
    }

    close(sock);

    return 0;
}

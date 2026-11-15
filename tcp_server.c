#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
int main()
{
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    char buffer[1024];
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(server_fd, 5);
    printf("Server is waiting for client...\n");
    addr_size = sizeof(client_addr);
    client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &addr_size);
    printf("Client connected!\n");
    memset(buffer, 0, sizeof(buffer));
    recv(client_fd, buffer, sizeof(buffer) - 1, 0);
    printf("Client says: %s\n", buffer);
    strcpy(buffer, "Hello Client! Message received.");
    send(client_fd, buffer, strlen(buffer), 0);
    close(client_fd);
    close(server_fd);
    return 0;
}

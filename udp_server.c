#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
int main()
{
    int server_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    char buffer[1024];
    server_fd = socket(AF_INET, SOCK_DGRAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    printf("UDP Server is waiting for message...\n");
    addr_size = sizeof(client_addr);
    memset(buffer, 0, sizeof(buffer));
    recvfrom(server_fd, buffer, sizeof(buffer) - 1, 0,
             (struct sockaddr *)&client_addr, &addr_size);
    printf("Client says: %s\n", buffer);
    strcpy(buffer, "Hello Client! Message received.");
    sendto(server_fd, buffer, strlen(buffer), 0,
           (struct sockaddr *)&client_addr, addr_size);
    close(server_fd);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
int main()
{
    int sock;
    struct sockaddr_in server_addr;
    socklen_t addr_size;
    char buffer[1024];
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr_size = sizeof(server_addr);
    strcpy(buffer, "Hello Server!");
    sendto(sock, buffer, strlen(buffer), 0,
           (struct sockaddr *)&server_addr, addr_size);
    printf("Message sent to server.\n");
    memset(buffer, 0, sizeof(buffer));
    recvfrom(sock, buffer, sizeof(buffer) - 1, 0,
             (struct sockaddr *)&server_addr, &addr_size);
    printf("Server says: %s\n", buffer);
    close(sock);
    return 0;
}

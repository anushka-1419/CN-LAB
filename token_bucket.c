
#include <stdio.h>

int main()
{
    int bucket_size, token_rate;
    int tokens = 0;
    int packets, time;
    int i;

    printf("Enter bucket size: ");
    scanf("%d", &bucket_size);

    printf("Enter token generation rate: ");
    scanf("%d", &token_rate);

    printf("Enter number of time intervals: ");
    scanf("%d", &time);

    for(i = 1; i <= time; i++)
    {
        printf("\nTime interval %d\n", i);

        // Generate tokens
        tokens = tokens + token_rate;

        if(tokens > bucket_size)
        {
            tokens = bucket_size;
        }

        printf("Available tokens: %d\n", tokens);

        printf("Enter number of packets to send: ");
        scanf("%d", &packets);

        if(packets <= tokens)
        {
            tokens = tokens - packets;

            printf("Packets sent: %d\n", packets);
            printf("Remaining tokens: %d\n", tokens);
        }
        else
        {
            printf("Not enough tokens!\n");
            printf("Packets sent: %d\n", tokens);

            tokens = 0;

            printf("Remaining packets: %d\n",
                   packets - (packets - tokens));
            printf("Remaining tokens: %d\n", tokens);
        }
    }

    printf("\nToken Bucket simulation completed!\n");

    return 0;
}

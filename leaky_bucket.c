
#include <stdio.h>

int main()
{
    int bucket_size, output_rate;
    int incoming, stored = 0;
    int time, i;

    printf("Enter bucket size: ");
    scanf("%d", &bucket_size);

    printf("Enter output rate: ");
    scanf("%d", &output_rate);

    printf("Enter number of time intervals: ");
    scanf("%d", &time);

    for(i = 1; i <= time; i++)
    {
        printf("\nEnter incoming packets at time %d: ", i);
        scanf("%d", &incoming);

        if(stored + incoming <= bucket_size)
        {
            stored = stored + incoming;
            printf("Packets accepted: %d\n", incoming);
        }
        else
        {
            int accepted = bucket_size - stored;
            int dropped = incoming - accepted;

            stored = bucket_size;

            printf("Packets accepted: %d\n", accepted);
            printf("Packets dropped: %d\n", dropped);
        }

        printf("Packets in bucket: %d\n", stored);

        if(stored >= output_rate)
        {
            stored = stored - output_rate;
            printf("Packets sent: %d\n", output_rate);
        }
        else
        {
            printf("Packets sent: %d\n", stored);
            stored = 0;
        }

        printf("Packets remaining: %d\n", stored);
    }

    printf("\nLeaky Bucket simulation completed!\n");

    return 0;
}


#include <stdio.h>

#define MAX_NODES 10
#define INF 9999

struct Node {
    int dist[MAX_NODES];
    int from[MAX_NODES];
} rt[MAX_NODES];

int main() {
    int cost[MAX_NODES][MAX_NODES];
    int nodes, i, j, k;
    int updated, iteration;

    printf("Enter number of nodes: ");
    scanf("%d", &nodes);

    if (nodes < 1 || nodes > MAX_NODES) {
        printf("Invalid number of nodes!\n");
        return 1;
    }

    printf("Enter cost matrix row by row (use 999 for no connection):\n");

    for (i = 0; i < nodes; i++) {
        for (j = 0; j < nodes; j++) {
            int v;
            scanf("%d", &v);

            if (v == 999)
                cost[i][j] = INF;
            else
                cost[i][j] = v;
        }
    }

    for (i = 0; i < nodes; i++) {
        cost[i][i] = 0;

        for (j = 0; j < nodes; j++) {
            rt[i].dist[j] = cost[i][j];

            if (i != j && cost[i][j] < INF)
                rt[i].from[j] = j;
            else
                rt[i].from[j] = -1;
        }
    }

    for (iteration = 0; iteration < nodes - 1; iteration++) {
        updated = 0;

        for (i = 0; i < nodes; i++) {
            for (j = 0; j < nodes; j++) {
                for (k = 0; k < nodes; k++) {

                    if (cost[i][k] >= INF)
                        continue;

                    if (rt[k].dist[j] >= INF)
                        continue;

                    int newdist = cost[i][k] + rt[k].dist[j];

                    if (newdist < rt[i].dist[j]) {
                        rt[i].dist[j] = newdist;
                        rt[i].from[j] = k;
                        updated = 1;
                    }
                }
            }
        }

        if (!updated)
            break;
    }

    // Display routing tables
    for (i = 0; i < nodes; i++) {
        printf("\nRouting Table for Router %d\n", i + 1);
        printf("Destination\tCost\tNext Hop\n");

        for (j = 0; j < nodes; j++) {
            printf("%d\t\t", j + 1);

            if (rt[i].dist[j] >= INF)
                printf("INF\t");
            else
                printf("%d\t", rt[i].dist[j]);

            if (i == j)
                printf("-\n");
            else if (rt[i].from[j] == -1)
                printf("-\n");
            else
                printf("%d\n", rt[i].from[j] + 1);
        }
    }

    return 0;
}

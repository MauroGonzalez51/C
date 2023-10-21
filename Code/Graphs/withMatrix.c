#include <stdlib.h>
#include <stdio.h>

#define NO_NODES 5
#define INF 1410065407

void dijikstra(int adjacency[NO_NODES][NO_NODES], float weight[NO_NODES][NO_NODES], int startNode, int endNode) {

    for (int row = 0; row < NO_NODES; row++) {
        for (int column = 0; column < NO_NODES; column++) {
            if (!weight[row][column]) {
                weight[row][column] = INF;
            }
        }
    }
    
    int pred[NO_NODES];
    int visited[NO_NODES], count, nextNode, i, j;

    float distance[NO_NODES];

    for (i = 0; i < NO_NODES; i++) {
        distance[i] = weight[startNode][i];
        pred[i] = startNode;
        visited[i] = 0;
    }

    distance[startNode] = 0;
    visited[startNode] = 1;
    count = 1;
    
    while (count < NO_NODES - 1) {
        int minDistance = INF;

        for (i = 0; i < NO_NODES; i++) {
            if (distance[i] < minDistance && !visited[i]) {
                minDistance = distance[i];
                nextNode = i;
            }
        }

        visited[nextNode] = 1;
        if (nextNode == endNode) {
            printf("\n");
            printf("La distancia del nodo %d al nodo %d es %f\n", startNode, endNode, distance[endNode]);
            printf("Ruta= %d", endNode);

            j = endNode;
            do {
                j = pred[j];
                printf(" <- %d ", j);
            } while (j != startNode);
            printf("\n\n");

            break;
        }

        for (i = 0; i < NO_NODES; i++) {
            if (!visited[i]) {
                if (minDistance + weight[nextNode][i] < distance[i]) {
                    distance[i] = minDistance + weight[nextNode][i];
                    pred[i] = nextNode;
                }
            }
        }

        count++;
    }
}

int main(void) {
    int adjacencyMatrix[NO_NODES][NO_NODES] = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {0, 1, 0, 1, 0}
    };

    float weightMatrix[NO_NODES][NO_NODES] = {
        {0, 4, 3, 0, 0},
        {4, 0, 2, 8, 6},
        {3, 2, 0, 0, 0},
        {0, 8, 0, 0, 5},
        {0, 6, 0, 5, 0}
    };

    dijikstra(adjacencyMatrix, weightMatrix, 0, 4);

    return EXIT_SUCCESS;
}
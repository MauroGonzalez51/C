#include <stdio.h>
#include <stdlib.h>

#define NO_NODES 6

typedef struct Graph {
    struct Node* head[NO_NODES];
} Graph;

typedef struct Node {
    int destination;
    struct Node* next;
    float weight;
} Node;

typedef struct Edge {
    int source, destination;
    float weight;
} Edge;

Graph* createGraph(Edge edges[], int n) {
    Graph* graph = (Graph *) malloc(sizeof(Graph));

    if (!graph) { return NULL; }

    for (int i = 0; i < NO_NODES; i++) {
        graph -> head[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        int source = edges[i].source;
        int destination = edges[i].destination;
        float weight = edges[i].weight;

        Node* newNode = (Node *) malloc(sizeof(Node));

        if (!newNode) { return NULL; }

        newNode -> destination = destination;

        newNode -> next = graph -> head[source];

        newNode -> weight = weight;

        graph -> head[source] = newNode;
    }

    return graph;
}

void printGraph(Graph *graph) {
    for (int i = 0; i < NO_NODES; i++) {
        Node *current = graph -> head[i];
        while (current != NULL) {
            printf("(%d -> %d)\n", i, current -> destination);
            current = current -> next;
        }
    }
}

int main() {
    Edge edges[] = {
        {0, 1}, {1, 2}, {2, 0}, {2, 1}, {3, 2}, {4, 5}, {5, 4}
    };

    int n = sizeof(edges) / sizeof(edges[0]);

    Graph *graph = createGraph(edges, n);

    printGraph(graph);

    return EXIT_SUCCESS;
}
// Adjascency List representation in C 
// Implementation for Undirected Graph

#include <stdio.h>
#include <stdlib.h>
 
typedef struct node{
    int vertex;
    struct node *next;
} node;

typedef struct Graph{
    int V;          //No of vertices
    node **adj;     //Adjacency Lists
}Graph;

// Create a node
node *createNode(int v){
    node *newNode = malloc(sizeof(node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create a graph
Graph *createAGraph(int vertices){
    Graph *graph = malloc(sizeof(Graph));
    graph->V = vertices;
    graph->adj = malloc(vertices * sizeof(node *));

    for (int i = 0; i < vertices; i++)
        graph->adj[i] = NULL;

    return graph;
}

// Add edge
void addEdge(Graph *graph, int s, int d){
    // Add edge from s to d
    node *newNode = createNode(d);
    newNode->next = graph->adj[s];
    graph->adj[s] = newNode;

    // Add edge from d to s
    newNode = createNode(s);
    newNode->next = graph->adj[d];
    graph->adj[d] = newNode;
}

// Print the graph
void printGraph(Graph *graph){
    int v;
    for (v = 0; v < graph->V; v++){
        printf("\n%d : ", v);
        node *temp = graph->adj[v];
        while (temp){
            printf("Vertex %d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
/*
	0---- 1
    | \   |
    |  \  |
	3-----2
	 \	 /
	  \	/
	   4
	  / \
	 5   6
*/
int main(){
    Graph *graph = createAGraph(7);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);
    addEdge(graph, 4, 6);
    

    printGraph(graph);

    return 0;
}
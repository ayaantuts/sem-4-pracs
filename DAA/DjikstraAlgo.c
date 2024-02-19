#include <stdio.h>
#include <limits.h>

#define NODES 9
#define INF INT_MAX

int adj[NODES][NODES] = {
    //a, b, c, d, e, f, g, h, i
    { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
    { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
    { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
    { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
    { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
    { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
    { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
    { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
    { 0, 0, 2, 0, 0, 0, 6, 7, 0 },
};

// Graph structure
struct Graph {
    char vertices[NODES];
    int adj[NODES][NODES];
} G;

// Vertex structure
struct Vertex {
    int dist;
    int par;
    int visited;
} V[NODES];

/**
 * @brief Initialize the distance, parent and visited status of all the vertices
 * and set the distance of the start vertex to 0
 * @param start: Index of the start vertex
 */
void InitializeSingleSource(int start) {
    int i;
    for (i = 0; i < NODES; i++) {
        V[i].dist = INF;
        V[i].par = -1;
        V[i].visited = 0;
    }
    V[start].dist = 0;
}

/**
 * @brief Extract the vertex with minimum distance from the set of vertices
 * 
 * @return int: Index of the vertex with minimum distance
 */
int extractMin() {
    int i, min = INF, minIndex = -1;
    for (i = 0; i < NODES; i++) {
        if (!V[i].visited && V[i].dist < min) {
            min = V[i].dist;
            minIndex = i;
        }
    }
    return minIndex;
}

/**
 * @brief Relax the edge between the vertices u and v,
 * if the distance of v is greater than the distance of u + weight of edge (u, v)
 * @param u: Index of the source vertex
 * @param v: Index of the destination vertex
 */
void relax(int u, int v) {
    if (V[v].dist > V[u].dist + G.adj[u][v]) {
        V[v].dist = V[u].dist + G.adj[u][v];
        V[v].par = u;
    }
}

/**
 * @brief Perform Djikstra's algorithm on the graph G starting from the vertex start
 * 
 * @param G: Graph on which Djikstra's algorithm is to be performed
 * @param start: Index of the start vertex
 */
void Djikstra(struct Graph G, int start) {
    int i, u, v;
    InitializeSingleSource(start);
    for (i = 0; i < NODES; i++) {
        // Extract the vertex with minimum distance
        u = extractMin();
        // Mark the vertex as visited
        V[u].visited = 1;
        for (v = 0; v < NODES; v++) {
            // Relax the edges from the vertex u to all the adjacent vertices
            if (!V[v].visited && G.adj[u][v])
                relax(u, v);
        }
    }
    // Print the shortest path from the start vertex to all the other vertices
    for (i = 0; i < NODES; i++)
        if (V[i].par != -1) {
            printf("%c - %c: %d\n", G.vertices[start], G.vertices[i], V[i].dist);
        }
}

int main() {
    int i, j;
    for (i = 0; i < NODES; i++)
        for (j = 0; j < NODES; j++)
            G.adj[i][j] = adj[i][j];
    for (i = 0; i < NODES; i++)
        G.vertices[i] = 'A' + i;
    Djikstra(G, 0);
    return 0;
}
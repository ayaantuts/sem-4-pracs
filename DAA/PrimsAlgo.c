#include <stdio.h>
#include <conio.h>
#include <limits.h>

#define NODES 9
#define INF INT_MAX

int mst[NODES];
int adj[NODES][NODES] = {
//   a, b, c, d, e, f, g, h, i
	{0, 4, 0, 0, 0, 0, 0, 8, 0},
	{4, 0, 8, 0, 0, 0, 0, 11, 0},
	{0, 8, 0, 7, 0, 4, 0, 0, 2},
	{0, 0, 7, 0, 9, 14, 0, 0, 0},
	{0, 0, 0, 9, 0, 10, 0, 0, 0},
	{0, 0, 4, 14, 10, 0, 2, 0, 0},
	{0, 0, 0, 0, 0, 2, 0, 1, 6},
	{8, 11, 0, 0, 0, 0, 1, 0, 7},
	{0, 0, 2, 0, 0, 0, 6, 7, 0}
};

// Structure to store the distance of vertices, their parent and whether they are visited or not
struct Vertices {
	int dist;
	int parent;
	int visited;
} V[NODES];

// Structure to store the graph
struct Graph {
	char nodes[NODES];
	int adjMatrix[NODES][NODES];
} G;

/**
 * @brief This function is used to extract the vertex with minimum distance.
 * 
 * @return int: Index of the vertex with minimum distance
 */
int extractMin() {
	int min = INF;
	int minIndex = -1;
	for (int i = 0; i < NODES; i++) {
		// If the vertex is not visited and its distance is less than the minimum distance, update the minimum distance and index
		if (!V[i].visited && V[i].dist < min) {
			min = V[i].dist;
			minIndex = i;
		}
	}
	return minIndex;
}

/**
 * @brief This function is used to find the minimum spanning tree using Prim's algorithm.
 * 
 * @param start: Index of the starting vertex
 */
void Prims(int start) {
	// Initialize the distance of all vertices to infinity, parent to -1 and visited to 0
	for (int i = 0; i < NODES; i++) {
		V[i].dist = INF;
		V[i].parent = -1;
		V[i].visited = 0;
	}
	// Set the distance of the starting vertex to 0
	V[start].dist = 0;
	// Iterate through all the vertices
	for (int i = 0; i < NODES; i++) {
		// Extract the vertex with minimum distance
		int u = extractMin();
		// Mark the vertex as visited
		V[u].visited = 1;
		// Iterate through all the adjacent vertices of the extracted vertex
		for (int v = 0; v < NODES; v++) {
			// If there is an edge between the vertices, the adjacent vertex is not visited and the distance is less than the current distance, update the parent and distance
			if (G.adjMatrix[u][v] && !V[v].visited && V[v].dist > G.adjMatrix[u][v]) {
				V[v].parent = u;
				V[v].dist = G.adjMatrix[u][v];
			}
		}
	}
	// Store the parent of each vertex in the minimum spanning tree.
	for (int i = 0; i < NODES; i++) {
		mst[i] = V[i].parent;
	}
}

int main() {
	int totalCost = 0;
	for (int i = 0; i < NODES; i++) {
		for (int j = 0; j < NODES; j++) {
			G.adjMatrix[i][j] = adj[i][j];
		}
	}
	for (int i = 0; i < NODES; i++) {
		G.nodes[i] = 'a' + i;
	}
	Prims(0);
	printf("Minimum Spanning Tree: \n");
	for (int i = 0; i < NODES; i++) {
		if (mst[i] != -1) {
			printf("%c - %c: %d\n", G.nodes[mst[i]], G.nodes[i], G.adjMatrix[i][mst[i]]);
			// Calculate the total cost of the minimum spanning tree
			totalCost += G.adjMatrix[i][mst[i]];
		}
	}
	printf("Total Cost: %d\n", totalCost);
	return 0;
}
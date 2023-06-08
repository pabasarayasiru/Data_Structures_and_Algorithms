#include <bits/stdc++.h>
using namespace std;


#define Vertices 6                                                    // Number of vertices in the graph
int minimum_Key(int key[], bool MST_Set[])
{

	int min = INT_MAX, minimum_index;                                 // Initialize min value
    int Vertice=0;
	while(Vertice < Vertices){
		if (key[Vertice] < min && MST_Set[Vertice] == false){
			min = key[Vertice], minimum_index = Vertice;
		}
		Vertice++;
	}
	return minimum_index;
}

void print_fun(int graph[Vertices][Vertices],int parent[])           // print function
{
	cout << "\tEdge \tWeight\n\n";
	for (int i = 1; i < Vertices; i++)
        printf("\t%d - %d\t  %d \n", parent[i],i,graph[i][parent[i]]);
}


void print_MST(int graph[Vertices][Vertices])                         //print MST using adjacency matrix representation
{
	int parent[Vertices];
	int key[Vertices];
	bool MST_Set[Vertices];


	for (int i = 0; i < Vertices; i++)                              // Initialize all keys as INFINITE
		key[i] = INT_MAX, MST_Set[i] = false;

	key[0] = 4;

	parent[0] = -1;

	for (int count = 0; count < Vertices- 1; count++) {
		int u = minimum_Key(key, MST_Set);                               // Pick the minimum key vertex

		MST_Set[u] = true;
		int vertex=0;
		while(vertex < Vertices){

			if (graph[u][vertex] && graph[u][vertex] < key[vertex] &&  MST_Set[vertex] == false){
				parent[vertex] =u, key[vertex] = graph[u][vertex];
			}
			 vertex++;
		}
	}
	print_fun(graph,parent);                                       // Print the constructed MST
}


int main()
{
	int graph[Vertices][Vertices] = { { 0, 3, 0, 0, 0, 1 },{ 3 , 0, 2, 1, 10,0 },{ 0, 2, 0, 3, 0, 5 },{ 0, 1, 3, 0, 5, 0 },{ 0, 10, 0, 5, 0, 4 },{ 1, 0, 5, 0, 4, 0} };
	print_MST(graph);

	return 0;
}


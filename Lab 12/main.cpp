#include <limits.h>
#include <stdio.h>
#include <iostream>
using namespace std;

#define Vertices 6    //Number of vertices

int minimum_dis(int distance[], bool visited[])
{
	int min = INT_MAX, min_index;// Initialize min value
    int Vertice = 0;
	while ( Vertice < Vertices ){
		if (visited[Vertice] == false && distance[Vertice] <= min){
			min = distance[Vertice], min_index = Vertice;
		}
		Vertice++;
    }
	return min_index;
}

int print_chart(int distance[], int n)   // print function
{
    float counter=0;
	cout<<"City \t Shortest_Time"<<endl;
	for (int i = 0; i < Vertices; i++){
	    counter+=distance[i];
        cout<<" "<<i<<"\t\t"<<distance[i]<<endl;
	}
	cout<< "\n Average Time is "<< counter/(Vertices-1)<< endl;
}


int Dijkstra(int src,int graph[Vertices][Vertices])   //Dijkstra's single source shortest path algorithm using adjacency matrix representation
{
	int distance[Vertices];

	bool visited[Vertices];
	for (int i = 0; i <Vertices; i++)
		distance[i] = INT_MAX, visited[i] = false;
	distance[src] = 0;


	for (int counter = 0; counter < Vertices-1; counter++) {// Find shortest path (time) for all vertices
		int u = minimum_dis(distance, visited);

		visited[u] = true;

        int v=0;
		while (v < Vertices){    // Update the distance value
			if (!visited[v] && distance[u] + graph[u][v] < distance[v]&& graph[u][v] && distance[u] != INT_MAX){
				distance[v] =  graph[u][v] + distance[u];
				}
            v++;
		}
	}

	print_chart(distance, Vertices);
	return 0;
}

int main(){
    int start;
	int graph[Vertices][Vertices] = { { 0 ,10,0 ,0 ,15,5},{ 10,0 ,10,30,0 ,0},{ 0 ,10,0 ,12,5 ,0 },{ 0 ,30,12,0 ,0 ,20},{ 15,0 ,5 ,0 ,0 ,0},{ 5 ,0 ,0 ,20,0 ,0} };
    cout<<"Enter the source: ";
    cin>>start;
	Dijkstra(start,graph);

	return 0;
}

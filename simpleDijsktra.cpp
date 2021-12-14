#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
#include<limits>
using namespace std;

int minDistance(int distance[], bool included[], int vertices){
	int min = INT_MAX;
	int minIndex;
	for(int v=0; v<vertices; v++){
		if((distance[v] <= min) and (included[v] == false)){
			min = distance[v];
			minIndex = v;
		}
	}
	return minIndex;
}

void dijsktarsAlgo(int graph[][50], int vertices, int source){
	int distance[vertices];
	bool included[vertices];
	// make the the distance infinity except the source 
	for(int i=0; i<vertices; i++){
		distance[i] = INT_MAX;
		included[i] = false;// no vertex is included innitially
	}
	distance[source] = 0;
	for(int count=0; count<vertices-1; count++){
		int u = minDistance(distance,included,vertices);
		included[u] = true;
		for(int v=0; v<vertices; v++){
			if((included[v] == false) and 
			(graph[u][v] != 0) and  
			(distance[u] + graph[u][v] < distance[v])){
				distance[v] = distance[u] + graph[u][v];
			}
		}
	}
	// print the solution 
	cout<<"vertex \t distance from the source "<<endl;
	for(int i=0; i<vertices; i++){
		cout<<i<<"\t\t"<<distance[i]<<endl;
	}

}

int main(){
	cout<<"enter the number of vertices:  ";
	int vertices;
	cin>>vertices;
	int graph[50][50];
	cout<<"enter the graph in form of adj matrix:  "<<endl;
	for(int i=0; i<vertices; i++){
		for(int j=0; j<vertices; j++){
			cin>>graph[i][j];
		}
	}
	dijsktarsAlgo(graph,vertices,0);

	return 0;
}

/* 
0   4   0   0   0   0   0   8   0 
4   0   8   0   0   0   0   11  0 
0   8   0   7   0   4   0   0   2
0   0   7   0   9   14  0   0   0 
0   0   0   9   0   10  0   0   0 
0   0   4   14  10  0   2   0   0
0   0   0   0   0   2   0   1   6 
8   11  0   0   0   0   1   0   7 
0   0   2   0   0   0   6   7   0 
*/ 
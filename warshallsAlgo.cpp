#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int dp[50][50];

void findDistance(){
	cout<<"enter the source:  ";
	int source;
	cin>>source;
	cout<<"enter the destination:  ";
	int destination;
	cin>>destination;
	cout<<"the minimum distance between the "<<source<<" and "<<destination<<" = "<<dp[source][destination];
}

void warshallsAlgorithm(int graph[][50], int v){
	for(int i=0; i<v; i++){
		for(int j=0; j<v; j++){
			dp[i][j] = graph[i][j];
		}
	}
	for(int k=0; k<v; k++){
		for(int i=0; i<v; i++){
			for(int j=0; j<v; j++){
				if(dp[i][j] > dp[i][k] + dp[k][j]){
						dp[i][j] = dp[i][k] + dp[k][j];
				}
			}
		}
	}

	cout<<"\n\nthe minimum distance table: "<<endl;
	for(int i=0; i<v; i++){
		for(int j=0; j<v; j++){
			cout<<dp[i][j]<<"\t";
		}
		cout<<endl;
	}
}

int main(){
	cout<<"enter the number of vertices:  ";
	int v;
	cin>>v;
	cout<<"enter the graph:  "<<endl;
	int graph[50][50];
	for(int i=0; i<v; i++){
		for(int j=0; j<v; j++){
			cin>>graph[i][j];
		}
	}
	warshallsAlgorithm(graph,v);
	findDistance();

	return 0;
}

/*
0        1        43
1        0        6
-1      -1        0
*/


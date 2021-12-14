#include <iostream>
#include <list>
#include <stack>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> graph, int vertices, int source){
	vector<bool> visited(vertices, false);
	stack<int> s;
	s.push(source);
	while(!s.empty()){
		int current = s.top();
		s.pop();
		if(visited[current] == false){
			cout<<current<<" --> ";
			visited[current] = true;
		}
		
        // now we have to get all the adjacent vertices of the popped vertex current
        // If a adjacent has not been visited, then push it to the stack.
		for(int j=0; j<vertices; j++){
			if(graph[current][j] != 0 and visited[j] == false){
				s.push(j);
			}
		}
	}
}

int main(){
	cout<<"enter the number of vertices in the graph: ";
	int vertices;
	cin>>vertices;
	vector<vector<int>> graph(vertices, vector<int>(vertices));
	cout<<"enter the adj matrix:  "<<endl;

	//graph input from user
	for(int i=0; i<vertices; i++){
		for(int j=0; j<vertices; j++){
			cin>>graph[i][j];
		}
	}
	cout<<"\nthe DFS traversal is:  ";
	dfs(graph, vertices, 0);

	return 0;
}
/*
0 1 1 1 0
1 0 1 0 1
1 1 0 0 0
1 0 0 0 0
0 1 0 0 0
*/
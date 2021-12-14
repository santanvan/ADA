#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

class Edge{
public:
    int source;
    int destination;
    int weight;
};

bool compare(Edge e1, Edge e2){
    return e1.weight < e2.weight;
}

int findParent(int v, int *parent){
    if(parent[v] == v){
        return v;
    }
    return findParent(parent[v], parent);
}

void kruskalsAlgo(Edge *input, int  e, int v){
    //sort the edges in ascending order acc to the weight
    sort(input,input+e,compare); 
    Edge *output = new Edge[v-1];//No. of edges in MST should be 1 less than total number of vertices
    
    int parent[v];
    for(int i=0; i<v; i++){
        parent[i] = i;// innitially every vertex is the parent of itself
    }

    int count = 0;
    int i = 0; 
    while(count != v-1){
        Edge currentEdge = input[i];
        // we have to check that by adding this edge to the MST any cycle is not created.
        // we will use UNION FIND algorithm.
        //find the parent of the nodes connected by this edge
        int sourceParent = findParent(currentEdge.source, parent);
        int destinationParent = findParent(currentEdge.destination, parent);
        if(sourceParent != destinationParent){
            output[count] = currentEdge;
            count++;
            // acc to the algo we have to take the union so
            // now by making destination the parent of source
            parent[sourceParent] = destinationParent; 
        }
        i++;  

    }
    // print the output array
    cout<<endl<<"MST : "<<endl<<"source \tdestination \tweight"<<endl;
    for(int i=0; i<v-1; i++){
        if(output[i].source < output[i].destination){
            cout<<output[i].source<<" \t"<<output[i].destination<<" \t\t"<<output[i].weight<<endl;
        }
        else {
            cout<<output[i].destination<<" "<<output[i].source<<" "<<output[i].weight;
        }
    }
    

    cout<<"the total cost of spanning tree = ";
    int totalCost = 0;

    for( int i=0; i<v-1; i++){
        totalCost = output[i].weight + totalCost;
    }
    cout<<totalCost;
}

int main(){
    cout<<"enter the number of vertices:  ";
    int v;
    cin>>v;
    cout<<"enter the number of Edges:  ";
    int e;
    cin>>e;
    cout<<endl;
    cout<<endl;
    Edge *input = new Edge[e];
    // now take the input of graph from the user
    cout<<endl<<"enter the source node >> destination node >> weight of the edge:  "<<endl;
    for(int i=0; i<e; i++){
        int s,d,w;
        cin>>s>>d>>w;
        input[i].source = s;
        input[i].destination = d;
        input[i].weight = w;
    }

    kruskalsAlgo(input,e,v);
    return 0;
}
/*
6

11

0 2 1
1 3 6
0 2 4
2 4 9
4 5 5
3 5 7
4 3 11
2 5 10
0 3 3
2 1 8
2 3 6

*/
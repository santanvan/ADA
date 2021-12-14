#include<iostream>
#include<map>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

template<typename T>

class Graph{
    unordered_map<T, list<pair< T, int >>> m;
public:
    void addEdge(T u, T v, int distance, bool isBidrectional = true){
        m[u].push_back(make_pair(v,distance));
        if(isBidrectional){
            m[v].push_back(make_pair(u,distance));
        }
    }

    void print(){
        for(auto j:m){
            cout<<j.first<<"-->";
            for(auto l:j.second){
                cout<<"("<<l.first<<","<<l.second<<")  |  ";
            }
            cout<<endl;
        }
    }

    void dijkstrasAlgo(T source){
        unordered_map<T, int> distance;
        unordered_map<T, list<T>> path;
        //set all the distances to infinity
        for(auto j:m){
            distance[j.first] = INT_MAX;
        }
        //now we have to make a set to find out the node with the minimum distance
        set<pair<int, T >> s;
        distance[source] = 0;
        s.insert(make_pair(0,source));
        while(!s.empty()){
            auto p = *(s.begin());
            T node = p.second;
            int nodeDistance = p.first;
            s.erase(s.begin());
            path[source].push_back(node);

            // now we have to delete this node and add the neighbours of this node
            // iterate over the neighbours/children of this node
            for(auto childPair : m[node]){
                if(nodeDistance + childPair.second < distance[childPair.first]){
                    //in set the updation is not possible so we have to delete the set item and add anew item
                    //we have to delete the old pair and add the new pair
                    T destination = childPair.first;
                    auto f = s.find(make_pair(distance[destination], destination));
                    if(f!=s.end()){// that means the elemt exist inside the set
                        s.erase(f);
                    }
                    // inset the new item
                    distance[destination] = nodeDistance + childPair.second; 
                    s.insert(make_pair(distance[destination], destination));
                }
            }
        }
        // print the distance to all other nodes
        for( auto d : distance ){
            cout<<d.first<<" is located at a distance of:  "<<d.second<<" from source "<<source<<endl;
        }
        // print the path
        cout<<"The shortest Path from the node "<<source<<" is:  ";
        for(auto j:path){
            for(auto l:j.second){
                cout<<l<<"-->"<<" | ";
            }
            cout<<endl;
        }

    } 
};

int main(){

    Graph <int > g;
    g.addEdge(1,2,1);
    g.addEdge(1,3,4);
    g.addEdge(2,3,1);
    g.addEdge(3,4,2);
    g.addEdge(1,4,7);
    g.dijkstrasAlgo(1);


    // Graph <string> india;
    // india.addEdge("amritsir","delhi",10);
    // india.addEdge("kolhapur","nagpur",20);
    // india.addEdge("nagpur","bangalore",30);
    // india.addEdge("pune","chennai",40);
    // india.print();


    return 0;
}


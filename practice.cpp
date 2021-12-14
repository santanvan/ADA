#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(50,vector<int> (50,-1));

int tsp(int mask, int pos, int distance[][50], int visitedAll, int n){
    if(mask == visitedAll){
        return distance[pos][0];
    }
    //look up case
    if(dp[mask][pos] != -1){
        return dp[mask][pos];
    }
    int ans = INT_MAX;
    // try to go to unvisited cities
    for(int city=0; city<n; city++){
        if((mask&(1<<city)) == 0){
            int newAns = distance[pos][city] + tsp(mask|(1<<city), city, distance, visitedAll, n);
            ans = min(ans,newAns);

        }
    }
    return dp[mask][pos] = ans;
}

int main(){
    cout<<"enter the number of vertices:  ";
    int n; cin>>n;
    cout<<"enter the adj matrix:  "<<endl;
    int distance[50][50];
    for(int i=0; i<n; i++){
        for(int j=0;j<n; j++){
            cin>>distance[i][j];
        }
    }
    int visitedAll = (1<<n) - 1;
    cout<<"The minimum travelling cost is = "<<tsp(1,0,distance, visitedAll,n)<<endl;

    return 0;
}



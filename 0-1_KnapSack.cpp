#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <limits>
#include <map>
#include <vector>

using namespace std;

vector<vector<int>> t(100, vector<int>(100,0));

void showItems(int n, int W, vector<int> weight){
    int i = n;
    int k = W;
    while (i>0 and k>0){
        if(t[i][k] != t[i-1][k]){
            cout<<"item "<<i<<" from value array is included "<<endl;
            k = k-weight[i-1];
        }
        i = i-1;
    }
}

int knapSack(vector<int> value, vector<int> weight, int W, int n){
	for(int i=0; i<n+1; i++){
		t[i][0] = 0;
	}
	for(int j=0; j<W+1; j++){
		t[0][j] = 0;
	}

	for(int i=1; i<n+1; i++){
		for(int j=1; j<W+1; j++){
			if(weight[i-1] <= j){
				t[i][j] = max((value[i-1] + t[i-1][j-weight[i-1]]), t[i-1][j]);
			}
			else{
				t[i][j] = t[i-1][j];
			}
		}
	}
	return t[n][W];
}

int main(){
	cout<<"enter the number of items:  ";
	int n;
	cin>>n;
	cout<<"enter the value array:  ";
	vector<int> value(n);
	for(int i=0; i<n; i++){
		cin>>value[i];
	}
	cout<<"enter the weight array:  ";
	vector<int> weight(n);
	for(int i=0; i<n; i++){
		cin>>weight[i];
	} 
	cout<<"enter the Weight of the Knapsack:  ";
	int W;
	cin>>W;
	int profit = knapSack(value,weight,W,n);
	cout<<"the total profit is = "<<profit<<endl;
    showItems(n,W,weight);

	return 0;
}
/* 
0 4 0 0 0 0 0 8 0 
4 0 8 0 0 0 0 11 0 
0 8 0 7 0 4 0 0 2
0 0 7 0 9 14 0 0 0 
0 0 0 9 0 10 0 0 0 
0 0 4 14 10 0 2 0 0
0 0 0 0 0 2 0 1 6 
8 11 0 0 0 0 1 0 7 
0 0 2 0 0 0 6 7 0
*/ 
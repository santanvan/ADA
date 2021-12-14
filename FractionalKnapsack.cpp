#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int,int> &p1, pair<int,int> &p2){
    return (double(p1.first)/double(p1.second)) > double(p2.first)/double(p2.second);
}

double fractionalKnapsack(vector<pair<int,int>> v, int n, int W){
    //sort according to value/weight
    sort(v.begin(),v.end(),compare);
    
    int currentWeight = 0;
    float profit = 0;
    int count = 0;

    for(int i=0; i<n; i++){
        if(v[i].second + currentWeight <= W){
            currentWeight += v[i].second;
            profit += v[i].first;
            ++count;
            cout<<endl<<"item "<<count<<" is added completely"<<endl;
        }
        else{
            int remainingWeight = W-currentWeight;
            profit += (double(remainingWeight)/double(v[i].second))*v[i].first;
            cout<<(double(remainingWeight)/double(v[i].second))<<" part of item "<<count+1<<" is also added"<<endl;
            break;
        }
    }
    cout<<"So, the max profit is = "; 
    return profit;
}

int main(){
    vector<pair<int,int>> v;
    cout<<"enter the number of elements:  ";
    int n;
    cin>>n;
    cout<<"enter the value array:  ";
    int value[n];
    for(int i=0; i<n; i++){
        cin>>value[i];
    }
    cout<<"enter the weight array:  ";
    int weight[n];
    for(int i=0; i<n; i++){
        cin>>weight[i];
    }
    for(int i=0; i<n; i++){
        v.push_back(make_pair(value[i],weight[i]));
    }
    cout<<"enter the weight of bag:  ";
    int W;
    cin>>W;
    cout<<fractionalKnapsack(v,n,W);

    return 0;
}

//w = (5, 10, 20, 30, 40)

//v = (30, 20, 100, 90,160)
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

vector<vector<int>> dp(50,vector<int>(50));

int LCS(string &s1, string &s2){
    int l1 = s1.length();
    int l2 = s2.length();
    for(int i=0; i<l1+1; i++){
        for(int j=0; j<l2+1; j++){
            if(i==0 or j==0){
                dp[i][j] = 0;
            }
            else if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    int lengthOfSequence = dp[l1][l2];
    vector<char> sequence(lengthOfSequence);
    int i = l1;
    int j = l2;
    while(i>0 and j>0){
        if(s1[i-1] == s2[j-1]){
            sequence[lengthOfSequence-1] = s1[i-1];
            i--;
            j--;
            lengthOfSequence--; 
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    cout<<"THE LENGTH OF LCS IS "<<dp[l1][l2]<<endl;
    cout<<"THE LONGEST COMMON SUBSEQUENCE IS = ";
    for(auto i : sequence){
        cout<<i;
    }

    return dp[l1][l2];
}

int main(){
    cout<<"enter the first string:  ";
    string s1;
    cin>>s1;
    cout<<"enter the second string:  ";
    string s2;
    cin>>s2;
    LCS(s1,s2);
    return 0;
}
/*
ABCDGH
AEDFHR
ans should be 3
*/
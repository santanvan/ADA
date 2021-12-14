#include <iostream>
using namespace std;

int partition(int* a, int s, int e, int n){
    int i = s-1; //assuming that there is no element in small elements array 
    int j = s;
    int pivot = a[e];
    for( ;j<=e-1; ){
        if(a[j] < pivot){
            i = i+1;
            swap(a[i],a[j]);
        }
        j = j+1;
    }
    // now we have to place the pivot element at right place
    swap(a[i+1],a[e]);
    
    return i+1; //returning the index of pivot
}   //4 2 7 9 15 11 20

void quickSort(int* arr, int s, int e, int n){
    //base case
    if(s>=e){
        return;
    }
    //rec case
    int p = partition(arr,s,e,n);
    //call on right part
    quickSort(arr,s,p-1,n);
    //call on left part
    quickSort(arr,p+1,e,n);
}

int main(){
    
    int a[10];
    cout<<"enter the number of elemets in the array:  ";
    int n;
    cin>>n;
    cout<<"enter the array:  ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int s = 0;
    int e = n-1;
    quickSort(a,s,e,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

    return 0;
}
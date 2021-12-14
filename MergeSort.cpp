#include<iostream>
using namespace std;

void merge(int *arr,int s, int e){
    int mid = (s+e)/2;
    int i = s;
    int j = mid+1;
    int k = s;
    int temp[100];
    while(i<=mid and j<=e){
        if(arr[i]<arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }
    while(i<=mid){
        temp[k++] = arr[i++];
    }
    while(j<=e){
        temp[k++]= arr[j++];
    }
    // coppy all elemts to the original array
    for(int i=0;i<=e;i++){
        arr[i] = temp[i];
    }
}

void mergeSort(int *arr,int s,int e){
    // base case
    if(s>=e)
    return;
    // rec case
    int mid = (s+e)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    // combine the arrays
    merge(arr,s,e);
}

int main(){

    int arr[20];
    cout<<"enter the number of values in the array:  ";
    int n;
    cin>>n;
    cout<<"enter the array:  ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"the array after sorting :  ";
    mergeSort(arr, 0, n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"  ";
    }

    return 0;
}
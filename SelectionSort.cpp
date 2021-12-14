#include<iostream>
using namespace std;

void selectionSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int minIdx = i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[minIdx]){
                minIdx = j;
            }
        }
        //swap the min idx with first element of the unsorted array
        int temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }

    // display the array after sorting
    for(int k=0; k<n; k++){
        cout<<arr[k]<<" ";
    }

}

int main(){
    int arr[10];
    cout<<"Enter the number of elements:  ";
    int n;
    cin>>n;
    cout<<"Enter the elements in the array:  ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    selectionSort(arr,n);
    return 0;
}
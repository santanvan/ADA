#include<iostream>
using namespace std;

void swap(int j1,int j2, int arr[], int j){
	int temp;
	temp = j1;
	j1 = j2;
	j2 = temp;
	arr[j] = j1;
	arr[j+1] = j2;
}

void bubbleSort(int size,int a[]){
	for (int i = 0; i < size-1; ++i){
		for (int j = 0; j < size-i-1; j++){
			if(a[j]>a[j+1]){
				swap(a[j], a[j+1], a, j);
				// int temp;
				// temp = a[j+1];
				// a[j+1] = a[j];
				// a[j] = temp;
			}
		}
	}
	// display the final array
	for(int i=0; i<size; i++){
		cout<<a[i]<<" ";
	}
}

int main(){
	int a[1000];
	int size;
	cout<<"enter the size: ";
	cin>>size;
	cout<<"enter the numbers:";
	for (int i = 0; i < size; ++i){
		cin>>a[i];
	}
	bubbleSort(size,a);
}
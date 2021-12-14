#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(int arr[], int n, int key){
	int start = 0;
	int end = n-1;
	while(start<=end){
		int mid = (start+end)/2;
		if(arr[mid] == key){
			return mid;
		}
		else if(arr[mid] < key ){
			start = mid+1;
		}
		else{
			end = mid-1;
		}
	}
	return -1;
}

int binarySearchRec(int a[], int n, int key, int start, int end){
	int mid = (start+end)/2;

	//base case
	if(n==0){
		return -1;
	}

	//recursive case
	if(a[mid]==key){
		return mid;
	}
	else if(a[mid]<key){
		binarySearchRec(a, n/2, key, mid+1, end);
	}
	else if(a[mid]>key){
		binarySearchRec(a, n/2, key, start, mid-1);
	}
}

int main(){

	int arr[10];
	cout<<"enter the number of elements in the array: ";
	int n;
	cin>>n;
	cout<<"enter the numbers in the array: ";
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	cout<<"enter the key: ";
	int key;
	cin>>key;
	(sort(arr, arr+n));
	cout<<"after sorting the array: ";
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\nThe element is present at an index No. of = "<<binarySearchRec(arr, n, key,0,n-1);

	return 0;
}
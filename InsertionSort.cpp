#include <iostream>
using namespace std;

void insertionSort(int a[], int n){
	int j; int key;
	for(int i=1; i<n; i++){
		key = a[i];
		j=i-1;
		while(j>=0 and key<a[j]){
			a[j+1] = a[j];
			j=j-1;
		}
		a[j+1] = key;
		cout<<"pass"<<" "<<i<<":  ";
		for (int k = 0; k < n; k++){
			cout<<a[k]<<" ";
		}
		cout<<endl;
	}
	cout<<"final sorted array:  ";
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
}

int main(){
	int a[5];
	cout<<"enter the number of elements in the array: ";
	int n;
	cin>>n;
	cout<<"enter the elements in the array: ";
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	insertionSort(a, n);


	return 0;
}
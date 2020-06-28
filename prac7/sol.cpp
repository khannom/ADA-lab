#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int partition(int arr[], int low, int high) 
{
    int pivot = low + rand() % (high - low); 

	swap(arr[pivot], arr[high]); 

	pivot = arr[high]; 
	int i = low - 1;

	for (int j = low; j <= high - 1; ++j) { 
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]); 
        }
    } 
    swap(arr[i + 1], arr[high]); 
    return (i + 1);
} 


int quickSelect(int arr[], int low, int high, int& k) 
{ 
	if (low < high) {
		int pi = partition(arr, low, high); 
        if(pi == k)
        {
            return arr[pi];
        }
        else if(k < pi)
            quickSelect(arr, low, pi-1, k);
        else
	    	quickSelect(arr, pi + 1, high, k);
    }
    else if(low == high)
    {
        if (low == k)
            return arr[k];
    }
}

int main()
{
    int n = 8000;
    int arr[n];
    int x;
    int k = 3999;
    for (int i = 0; i < n; ++i)
    {
        cin>>x;
        for (int j = 0; j < n; ++j)
        {
            cin>>arr[j];
        }
        cout<<quickSelect(arr,0,7999,k)<<'\n';
        //Solucion ordenando el array
        //sort(arr,arr+n);
        //cout<<arr[k]<<'\n';
    }
    return 0;
}
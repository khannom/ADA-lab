#include <cstdlib> 
#include <iostream>
#include <bits/stdc++.h>

using namespace std; 


int partition(int arr[], int low, int high) 
{
    int pivot = low + rand() % (high - low); 

	swap(arr[pivot], arr[high]); 

	pivot = arr[high]; 
	int i = low - 1;

	for (int j = low; j <= high - 1; j++) { 
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]); 
        }
    } 
    swap(arr[i + 1], arr[high]); 
    return (i + 1);
} 


int quickSelect(int arr[], int low, int high, int k) 
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

void printArray(int arr[], int n) 
{ 
	for (int i = 0; i < n; i++) 
		printf("%d ", arr[i]); 
	printf("\n"); 
}

int main() 
{ 
	srand(time(NULL)); 
	int arr[] = {9,1,8,2}; 
	int n = sizeof(arr) / sizeof(arr[0]); 
    int k = (n/2)-1;
    //int val = quickSelect(arr, 0, n - 1, k);
	//cout <<"mediana : "<< val<<endl; 
    sort(arr,arr+n);
	printf("Sorted array: \n"); 
	printArray(arr, n); 
	return 0; 
} 

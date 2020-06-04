#include <bits/stdc++.h>
#include <chrono>
#include <fstream>

using namespace std; 

void fillArray(int* array, int n)
{
    srand (time(NULL));
    for(int i=0; i<n; ++i)
    {
        array[i] = (rand() % n) +1;
    }
}


void insertion_sort(int arr[], int n) 
{
	int i, key, j;
	for (i = 1; i < n; ++i) 
	{
		key = arr[i]; 
		j = i - 1; 
		while (j >= 0 && arr[j] > key) 
		{
			arr[j + 1] = arr[j]; 
			j = j - 1;
		}
		arr[j + 1] = key;
	}
} 



void printArray(int arr[], int n) 
{ 
	int i; 
	for (i = 0; i < n; i++) 
		cout << arr[i] << " "; 
	cout << endl; 
}

void merge(int arr[], int l, int m, int r) 
{
    int temp[r-l+1];
    for (int i = 0; i <= m-l; ++i)
    {
        temp[i] = arr[l+i];
    }
    for (int i = m+1; i <= r; ++i)
    {
        temp[i-l] = arr[r+m+1-i];
    }
    int i = 0;
    int j = r-l;
    for (int k = l; k <= r; ++k)
    {
        if(temp[i] <= temp[j])
        {
            arr[k] = temp[i];
            ++i;
        }
        else
        {
            arr[k] = temp[j];
            --j;
        }
    }
    
} 
  
void mergeSort(int arr[], int l, int r) 
{
    if (l < r) 
    { 
        
        int m = l+(r-l)/2;
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    }
}

int main() 
{
    fstream texto ("test.txt");
	int *array1;
    int *array2;
    int n;
    cin>>n;
    for (int i = 5; i < n; i+=5)
    {
        array1 = new int [i];
        array2 = new int [i];
        fillArray(array1,i);
        for (int j = 0; j < i; ++j)
        {
            array2[j] = array1[j];
        }
        
        //cout<<"ARREGLOS DE "<<i<<" ELEMENTOS:"<<endl;
        auto mergeStart = chrono::high_resolution_clock::now();
        mergeSort(array1, 0, i-1);
        auto mergeEnd = chrono::high_resolution_clock::now();
        int mergeTime = chrono::duration_cast<chrono::nanoseconds> (mergeEnd-mergeStart).count();
        //cout<<"Tiempo en nanosegundos del merge sort: "<< mergeTime <<endl;
        
        auto insertStart = chrono::high_resolution_clock::now();
        insertion_sort(array2, i);
        auto insertEnd = chrono::high_resolution_clock::now();
        int insertionTime = chrono::duration_cast<chrono::nanoseconds> (insertEnd-insertStart).count();
        //cout<<"Tiempo en nanosegundos del insertion sort: "<< insertionTime <<endl;
        //cout<<endl;
        texto<<mergeTime<<' '<<insertionTime<<'\n';
        delete [] array1;
        delete [] array2;
    }
    texto.close();
	return 0; 
} 

#include <bits/stdc++.h>
#include <chrono>
#include <fstream>

using namespace std; 

void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
} 

void fillArray(int* array, int n)
{
    srand (time(NULL));
    for(int i=0; i<n; ++i)
    {
        array[i] = (rand() % n) +1;
    }
}


void printArray(int arr[], int n) 
{ 
	int i; 
	for (i = 0; i < n; i++) 
		cout << arr[i] << " "; 
	cout << endl; 
}

int compCreciente(const void * a, const void * b) 
{ 
    return ( *(int*)a - *(int*)b ); 
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

int partition (int arr[], int low, int high)  
{  
    int pivot = arr[high]; // pivot  
    int i = (low - 1); // Index of smaller element  
  
    for (int j = low; j <= high - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (arr[j] < pivot)  
        {  
            i++; // increment index of smaller element  
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  

void quick_sort(int arr[], int low, int high)  
{  
    if (low < high)  
    {  
        /* pi is partitioning index, arr[p] is now  
        at right place */
        int pi = partition(arr, low, high);  
  
        // Separately sort elements before  
        // partition and after partition  
        quick_sort(arr, low, pi - 1);  
        quick_sort(arr, pi + 1, high);  
    }  
}

int main() 
{
    fstream texto("test.txt");
	int *array1;
    int *array2;
    int *array3;
    int n;
    cin>>n;
    for (int i = 1000; i <= n; i+=1000)
    {
        array1 = new int [i];
        array2 = new int [i];
        array3 = new int [i];
        fillArray(array1,i);
        for (int j = 0; j < i; ++j)
        {
            array2[j] = array1[j];
            array3[j] = array1[j];
        }
        
        auto mergeStart = chrono::high_resolution_clock::now();
        mergeSort(array1, 0, i-1);
        auto mergeEnd = chrono::high_resolution_clock::now();
        long long mergeTime = chrono::duration_cast<chrono::nanoseconds> (mergeEnd-mergeStart).count();

        auto quickStart = chrono::high_resolution_clock::now();
        qsort(array2, i, sizeof(int), compCreciente);
        auto quickEnd = chrono::high_resolution_clock::now();
        long long quickTime = chrono::duration_cast<chrono::nanoseconds> (quickEnd-quickStart).count();
        
        auto quick2Start = chrono::high_resolution_clock::now();
        quick_sort(array3,0,i-1);
        auto quick2End = chrono::high_resolution_clock::now();
        long long quick2Time = chrono::duration_cast<chrono::nanoseconds> (quick2End-quick2Start).count();

        texto<<mergeTime<<' '<<quickTime<<' '<<quick2Time<<'\n';
        
        delete [] array1;
        delete [] array2;
        delete [] array3;
    }
    texto.close();
	return 0; 
}


#include <bits/stdc++.h> 
#include <chrono>
#include <fstream>

using namespace std; 

long long contador = 0;

void fillArray(int* array, int n)
{
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

  
void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  

int partition (int arr[], int low, int high)  
{  
    int pivot = arr[high]; 
    int i = (low - 1); 
  
    for (int j = low; j <= high - 1; j++)  
    {  
        
        if (arr[j] < pivot)  
        {  
            i++; 
            swap(&arr[i], &arr[j]);
            ++contador;
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  
  
void quickSort(int arr[], int low, int high)  
{  
    if (low < high)  
    {  
        
        int pi = partition(arr, low, high);  
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}

int main()
{  
    fstream texto("test2.txt");
    srand(time(NULL));
	const int n = pow(2,20);
    for (int i = 256; i <= n; i*=2)
    {
        contador = 0;
        for(int j=0; j<200; ++j)
        {
            int *array = new int [i];
            fillArray(array, i);
            quickSort(array,0,i-1);
            delete [] array;
        }
        texto<<i<<' '<<contador/200<<' '<<i*log(i)<<'\n';
    }
    texto.close();
	return 0;
}
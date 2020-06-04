#include <bits/stdc++.h>
#include <chrono>
#include <fstream>

using namespace std;

// Se inicializa con la cantidad de variables en cada algoritmo
int memoryMerge = 3;
int memoryMerge2 = 4;

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

void merge(int arr[], int l, int m, int r) 
{
    int temp[r-l+1];
    memoryMerge += r-l+1;
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
        ++memoryMerge;
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    }
}

void merge2(int arr[], int beg, int mid, int end, int maxele) 
{
    int i = beg; 
    int j = mid + 1; 
    int k = beg;
    while (i <= mid && j <= end) { 
        if (arr[i] % maxele <= arr[j] % maxele) { 
            arr[k] = arr[k] + (arr[i] % maxele) * maxele; 
            k++; 
            i++; 
        } 
        else { 
            arr[k] = arr[k] + (arr[j] % maxele) * maxele; 
            k++; 
            j++; 
        } 
    } 
    while (i <= mid) { 
        arr[k] = arr[k] + (arr[i] % maxele) * maxele; 
        k++; 
        i++; 
    } 
    while (j <= end) { 
        arr[k] = arr[k] + (arr[j] % maxele) * maxele; 
        k++; 
        j++; 
    } 
  
    // Obtaining actual values 
    for (int i = beg; i <= end; i++) 
        arr[i] = arr[i] / maxele; 
} 
  
void mergeSort2(int arr[], int beg, int end, int maxele) 
{
    if (beg < end) { 
        int mid = (beg + end) / 2;
        mergeSort2(arr, beg, mid, maxele); 
        mergeSort2(arr, mid + 1, end, maxele); 
        merge2(arr, beg, mid, end, maxele); 
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
        
        auto merge2Start = chrono::high_resolution_clock::now();
        // Necesitamos mandar como parametro 1 numero que sea mayor que cualquier numero en el array
        // y como fillArray() solo ingresa valores entre 1 y i
        // basta con mandarle i+1 como ultimo parametros
        mergeSort2(array2, 0, i-1, i+1);
        auto merge2End = chrono::high_resolution_clock::now();
        int merge2Time = chrono::duration_cast<chrono::nanoseconds> (merge2End-merge2Start).count();
        //cout<<"Tiempo en nanosegundos del insertion sort: "<< insertionTime <<endl;
        //cout<<endl;
        texto<<mergeTime<<' '<<merge2Time<<' ';
        texto<<memoryMerge<<' '<<memoryMerge2<<'\n';
        memoryMerge = 0;
        delete [] array1;
        delete [] array2;
    }
    texto.close();
	return 0; 
}
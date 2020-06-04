#include <bits/stdc++.h>
#include "Timer.hpp"

using namespace std; 


void swap(int *xp, int *yp) 
{ 
	int temp = *xp; 
	*xp = *yp; 
	*yp = temp; 
}

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
	Timer timer;
	
	long comparaciones = 1;// comparacion final
	long asignaciones = 3;// i, key, j
	int workMemory = 3; //i, key, j
	timer.start();
	int i, key, j;
	for (i = 1; i < n; ++i) 
	{
		++asignaciones;// ++i
		++comparaciones;// i < n
		key = arr[i]; 
		j = i - 1; 
		asignaciones+=2;
		while (j >= 0 && arr[j] > key) 
		{
			comparaciones += 2;
			arr[j + 1] = arr[j]; 
			j = j - 1;
			asignaciones += 2;
		}
		arr[j + 1] = key;
		++asignaciones;
	}
	timer.stop();
	cout<<"Size del arreglo: "<<n<<endl;
	cout<<"Tiempo en milisegundos: "<<timer.elapsedMilliseconds()<<endl;
	/*cout<<"Numero de comparaciones: "<<comparaciones<<endl;
	cout<<"Numero de asignaciones: "<<asignaciones<<endl;
	cout<<"Memoria adicional: "<<workMemory<<endl;*/
	long costo = comparaciones*2 + asignaciones*8;
	cout<<"Costo adicional: " <<costo<<endl<<endl;
} 


void bubble_sort(int arr[], int n) 
{
	Timer timer;

	long asignaciones = 2; // i, j
	long comparaciones = 1;// comparacion final
	int workMemory = 2; //i, j
	timer.start();
	int i, j; 
	for (i = 0; i < n-1; i++)
	{
		++comparaciones;
		++asignaciones;
		for (j = 0; j < n-i-1; j++)
		{
			++comparaciones;
			++asignaciones;
			if (arr[j] > arr[j+1])
			{
				++comparaciones;
				swap(&arr[j], &arr[j+1]);
				asignaciones += 3;// del swap
			}
		}
	}
	timer.stop();
	cout<<"Size del arreglo: "<<n<<endl;
	cout<<"Tiempo en milisegundos: "<<timer.elapsedMilliseconds()<<endl;
	/*cout<<"Numero de comparaciones: "<<comparaciones<<endl;
	cout<<"Numero de asignaciones: "<<asignaciones<<endl;
	cout<<"Memoria adicional: "<<workMemory<<endl;*/
	long costo = comparaciones*2 + asignaciones*8;
	cout<<"Costo adicional: " <<costo<<endl<<endl;
}

void printArray(int arr[], int n) 
{ 
	int i; 
	for (i = 0; i < n; i++) 
		cout << arr[i] << " "; 
	cout << endl; 
} 

int main() 
{
	
	//solo usar un sort en cada ejecucion
	int tamanios[] = {500, 1000, 2000, 5000, 10000, 20000};
	/*for (int i = 0; i < 6; i++)
	{
		int* array = new int [tamanios[i]];
		fillArray(array,tamanios[i]);
		insertion_sort(array,tamanios[i]);
		delete [] array;
	}*/
	for (int i = 0; i < 6; i++)
	{
		int* array = new int [tamanios[i]];
		fillArray(array,tamanios[i]);
		bubble_sort(array,tamanios[i]);
		delete [] array;
	}
	//bubble_sort(array,n);
    //printArray(array,n);
	return 0; 
} 

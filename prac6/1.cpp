#include <bits/stdc++.h>
#include <chrono>
#include <fstream>

using namespace std; 

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

int main() 
{
    fstream texto("test.txt");
    srand(time(NULL));
	const int n = pow(2,20);
    for (int i = 256; i <= n; i*=2)
    {
        float veces = 0;
        for(int j=0; j<200; ++j)
        {
            int *array = new int [i];
            fillArray(array, i);
            int max = array[0];
            for(int k = 1; k < i; ++k)
            {
                if (array[k] > max)
                {
                    max = array[k];
                    ++veces;
                }
            }
            delete [] array;
        }
        texto<<i<<' '<<veces/200.0<<' '<<1+log(i)<<'\n';
    }
    texto.close();
	return 0; 
}
#include <iostream>
#include <fstream>
using namespace std;

int insertion_sort(int arr[], int n) 
{	
	int swaps = 0;
	int i, key, j;
	for (i = 1; i < n; ++i) 
	{
		key = arr[i]; 
		j = i - 1; 
		while (j >= 0 && arr[j] > key) 
		{
            ++swaps;
			arr[j + 1] = arr[j]; 
			j = j - 1;
		}
		arr[j + 1] = key;
	}
    return swaps;
}

int main()
{
    ofstream txt("output.txt");
    int casos;
    cin>>casos;
    for (int i = 0; i < casos; i++)
    {
        int n;
        cin>>n;
        int* vag = new int [n];
        for (int i = 0; i < n; i++)
        {
            cin>>vag[i];
        }
        int swaps = insertion_sort(vag,n);
        cout<<"La mejor cantidad de swaps de trenes es "<<swaps <<" swaps."<<endl;
        txt << "La mejor cantidad de swaps de trenes es "<< swaps <<" swaps.\n";
    }
}
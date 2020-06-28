#include <iostream>
#include <fstream>
using namespace std;


int swaps = 0;

int partition(int arr[], int low, int high) 
{
    int pivot = arr[high]; 
	int i = low - 1;

	for (int j = low; j <= high - 1; ++j) { 
        if (arr[j] <= pivot) {
            ++i;
            for (int k = j; j > i; --k)
            {
                swap(arr[k],arr[k-1]);
                ++swaps;
            }
        }
    }
    for (int k = high; k > i+1; --k)
    {
        swap(arr[k],arr[k-1]);
        ++swaps;
    }
    return (i + 1);
}

int quickSort(int arr[], int low, int high) 
{ 
	if (low < high) {
		int pi = partition(arr, low, high); 
        quickSort(arr, low, pi-1);
	    quickSort(arr, pi + 1, high);
    }
}

int main()
{
    ofstream txt("tren_out.txt");
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
        quickSort(vag, 0, n-1);
        cout<<"La mejor cantidad de swaps de trenes es "<< swaps <<" swaps."<<endl;
        txt << "La mejor cantidad de swaps de trenes es "<< swaps <<" swaps.\n";
        for (int i = 0; i < n; ++i)
        {
            cout << vag[i]<< ' ';
        }
        cout<<endl;
        swaps = 0;
    }
}
#include<iostream>
#include<math.h>
using namespace std;

//Nombre: Diego Armando Portocarrero Espirilla

// Suma maxima del subarray orden lineal
long long maxSubArraySum(long long a[], int size, int& p, int& q) 
{ 
    long long max_so_far = 0;
    long long max_ending_here = 0; 

    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];

        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
            q = i;
        }

        if (max_ending_here < 0)
        {
            max_ending_here = 0;
            p = i+1;
        }
    } 
    return max_so_far; 
}

// Suma maxima del subarray divide y venceras
long long maxSum(long long a[], int p, int r, int& idx1, int& idx2)
{
    if(p == r) return (a[p]<0?0:a[p]);
    int q = (p+r)/2;

    long long maxIzq = maxSum(a,p,q,idx1,idx2);
    long long maxDer = maxSum(a,q+1,r,idx1,idx2);

    long long maxIzq2 = a[q];
    long long suma = a[q];
    idx1 = q;
    for (int i = q-1; i >= p ; --i)
    {
        suma += a[i];
        if (suma > maxIzq2)
        {
            maxIzq2 = suma;
            idx1 = i;
        }
    }
    long long maxDer2 = a[q+1];
    suma = a[q+1];
    idx2 = q+1;
    for (int i = q+2; i <= r ; ++i)
    {
        suma += a[i];
        if (suma > maxDer2)
        {
            maxDer2 = suma;
            idx2 = i;
        }
    }
    long long maxCruz = maxIzq2 + maxDer2;
    long long maxArray[] = {maxDer2, maxIzq2, maxCruz};
    long long max = 0;
    for (int i = 0; i < 3; ++i)
    {
        if (maxArray[i]>max)
        {
            max = maxArray[i];
        }
    }
    return max;
}


int main()
{
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        int nCalles;
        cin>>nCalles;
        long long costos[nCalles-1];
        for (int j = 0; j < nCalles-1; ++j)
        {
            cin>>costos[j];
        }
        int idx1 = -1;
        int idx2 = -1;
        //long long maxSubSum = maxSubArraySum(costos, nCalles-1, idx1, idx2);
        long long maxSubSum = maxSum(costos, 0, nCalles-2, idx1, idx2);
        if(!maxSubSum)
            cout<<"La ruta "<<i+1<<" no tiene calles interesantes."<<endl;
        else
            cout<<"La mejor parte de la ruta "<<i+1<<" es entre las calles "<<idx1+1<<" y "<<idx2+2<<" max: "<<maxSubSum<<endl;
    }
    return 0;
}
#include <iostream>

using namespace std;

int acumulated(int &fs, int &cs, int &fi, int &ci, int** A, int** ac)
{
    if (fs == 0 && cs == 0)
        return ac[fi][ci];
    else if (fs == 0)
        return ac[fi][ci] - ac[fi][cs-1];
    else if (cs == 0)
        return ac[fi][ci] - ac[fs-1][ci];
    else
        return ac[fi][ci] - ac[fi][cs] - ac[fs][ci] + ac[fs-1][cs-1];
}



int main()
{
    int n;
    cin>>n;
    int **A = new int* [n];
    for (int i = 0; i < n; i++)
    {
        A[i] = new int [n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>A[i][j];
        }
    }
    
    int **ac = new int* [n];
    for (int i = 0; i < n; i++)
    {
        ac[i] = new int [n];
    }



    //Matriz de valores acumulados
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == 0 && j == 0)
            {
                ac[i][j] = A[i][j];
            }
            else if(i == 0)
            {
                ac[i][j] = A[i][j] + ac[i][j-1];
            }
            else if (j == 0)
            {
                ac[i][j] = A[i][j] + ac[i-1][j];
            }
            else
            {
                ac[i][j] = A[i][j] + ac[i-1][j] + ac[i][j-1] - ac[i-1][j-1];
            }
        }
    }


    int subMax = INT32_MIN;

    for (int fs = 0; fs < n; fs++)
    {
        for (int cs = 0; cs < n; cs++)
        {
            for (int fi = fs; fi < n; fi++)
            {
                for (int ci = cs; ci < n; ci++)
                {
                    subMax = max(subMax, acumulated(fs, cs, fi, ci, A, ac));
                }
            }
        }
    }
    
    cout<<subMax<<endl;

    return 0;
}
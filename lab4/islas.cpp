#include<iostream>
#include<string>
#include<vector>
using namespace std;

void mapear(vector<string>& mapa, int n, int i, int j)
{
    if(i < 0 || j < 0 || i == n || j == n || mapa[i][j] == '0') return;
    mapa[i][j] = '0';
    mapear(mapa, n, i-1, j);
    mapear(mapa, n, i+1, j);
    mapear(mapa, n, i, j-1);
    mapear(mapa, n, i, j+1);


    mapear(mapa, n, i+1, j-1);
    mapear(mapa, n, i+1, j+1);
    mapear(mapa, n, i-1, j-1);
    mapear(mapa, n, i-1, j+1);

}

int main()
{
    int casos = 0;
    int n;
    while (cin>>n)
    {
        ++casos;
        vector<string> mapa;
        string linea;
        for (int i = 0; i < n; i++)
        {
            cin>>linea;
            mapa.push_back(linea);
        }
        int islas = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mapa[i][j] == '1')
                {
                    ++islas;
                    mapear(mapa,n,i,j);
                }
            }
            
        }
        cout<<islas<<endl;
    }
    return 0;
}
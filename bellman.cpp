#include <bits/stdc++.h>

using namespace std;

void bford(vector<vector<int>> &adj, int N)
{
    vector<int> dist(N, INT_MAX);
    dist[0] = 0;
    for(int k = 0; k<N-1; k++)
    {
        for(int i = 0; i<N; i++)
        {
            for(int j = 0; j<N; j++)
            {
                if(adj[i][j]!=INT_MAX)
                {
                    if(dist[j]>dist[i]+adj[i][j])
                        dist[j] = dist[i]+adj[i][j];
                }
            }
        }
    }

    for(int i = 0; i<N; i++)
    {
        cout<<i<<"\t"<<dist[i]<<endl;
    }
}

int main()
{
    int N = 6;
    int a[N][N] = {
        {0, 8, 0, 0, 0, 10},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, -1, 0, -4},
        {0, 0, 0, 0, -2, 2},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 2, 0, 0}
        };
    

    vector<vector<int>> adj(N, vector<int>(N));

    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<N; j++)
        {
            if(a[i][j]==0)
                adj[i][j] = INT_MAX;
            else
                adj[i][j] = a[i][j];
        }
    }
    bford(adj, N);

    return 0;
}
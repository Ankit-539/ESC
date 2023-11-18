#include <bits/stdc++.h>

using namespace std;

void floyd(vector<vector<int>> &adj, int N)
{
    vector<vector<int>> dist(N, vector<int>(N, INT_MAX));

    for(int i = 0; i<N; i++)
    {
        dist[i][i] = 0;
    }

    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<N; j++)
        {
            if(adj[i][j]!=INT_MAX)
                dist[i][j] = adj[i][j];
        }
    }
    
    for(int k = 0; k<N; k++)
    {
        for(int i = 0; i<N; i++)
        {
            for(int j = 0; j<N; j++)
            {
                if(dist[i][k]==INT_MAX || dist[k][j]==INT_MAX)
                    continue;
                else if(dist[i][j]>dist[i][k]+dist[k][j])
                    dist[i][j] = dist[i][k]+dist[k][j];
            }
        }
    }

    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<N; j++)
        {
            cout<<dist[i][j]<<"\t";
        }
        cout<<endl;
    }
}

int main()
{
    int N = 4;
    int a[N][N] = {
        {0, 0, 0, -2},
        {4, 0, 0, 3},
        {0, -1, 0, 0},
        {0, 0, 2, 0}
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
    floyd(adj, N);

    return 0;
}
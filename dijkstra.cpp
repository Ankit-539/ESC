#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> iPair;

void Dk(vector<vector<int>> adj, int N)
{
    vector<int> dist(N, INT_MAX);
    vector<bool> check(N);
    
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    dist[0] = 0;
    pq.push({0 , 0});
    while(!pq.empty())
    {
        // /cout<<i;
        int u = pq.top().second;
        pq.pop();

        if(check[u])
            continue;

        check[u] = true;

        for(int v = 0; v<N; v++)
        {
            if(adj[u][v] && !check[v] && dist[v]>(dist[u]+adj[u][v]))
            {
                dist[v] = dist[u]+adj[u][v];
                pq.push({dist[v], v});
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
    int a[6][6] = {
        {0, 3, 0, 0, 10, 0},
        {0, 0, 2, 8, 4, 0},
        {0, 0, 0, 9, 0, 0},
        {0, 0, 7, 0, 0, 0},
        {0, 1, 0, 2, 0, 0},
        {0 ,0, 0, 0, 0, 0}};
    
    vector<vector<int>> adj(N, vector<int>(N));

    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<N; j++)
        {
            adj[i][j] = a[i][j];
        }
    }
    Dk(adj, N);

    return 0;
}
#include <bits/stdc++.h>
#include <queue>

using namespace std;

typedef pair<int, int> iPair;

void primMST(vector<vector<int>> &adj, int N)
{
    vector<bool> mst(N);
    vector<int> parent(N);
    vector<int> key(N, INT_MAX);

    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    pq.push({0, 0});
    key[0] = 0;

    while(!pq.empty())
    {
        int u = pq.top().second;
        //cout<<u<<endl;
        pq.pop();

        mst[u] = true;
        //cout<<1;

        for(int v = 0; v<N; v++)
        {
            if(adj[u][v] && !mst[v] && key[v]>adj[u][v])
            {
                key[v]=adj[u][v];
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    for(int i = 1; i<N; i++)
    {
        cout<<parent[i]<<"--"<<i<<"\t"<<adj[i][parent[i]]<<endl;
    }
}

int main()
{
    int N = 5;
    int a[5][5] = {
        {0, 1, 4, 0, 2},
        {1, 0, 0, 3,  0},
        {4, 0, 0, 6, 7},
        {0, 3, 6, 0, 0},
        {2, 0, 7, 0, 0}};
    

    vector<vector<int>> adj(5, vector<int>(5));

    for(int i = 0; i<5; i++)
    {
        for(int j = 0; j<5; j++)
        {
            adj[i][j] = a[i][j];
        }
    }
    primMST(adj, N);

    return 0;
}
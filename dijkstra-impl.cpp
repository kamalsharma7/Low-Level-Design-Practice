#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<pair<int,int>>> &adj, int src)
{
    vector<int> vis(V , 0);
    vector<int> dist(V , INT_MAX);
    dist[src] = 0;
    vis[src]=1;

    priority_queue<pair<int,int> , vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,src});

    while(!pq.empty()){
        int node = pq.top().second;
        int curr_dist = pq.top().first;
        vis[node]=1;
        pq.pop();

        for(auto it : adj[node]){
            if(!vis[it.first]){
                if(curr_dist + it.second  < dist[it.first]){
                    dist[it.first] = curr_dist + it.second;
                    pq.push({dist[it.first] , it.first});
                }
            }
        }
    }
    return dist;
}

int main()
{
    int V = 5;

    vector<vector<pair<int,int>>> adj(V);

    auto addEdge = [&](int u, int v, int wt)
    {
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});      // Undirected graph
    };

    addEdge(0, 1, 4);
    addEdge(0, 2, 2);
    addEdge(1, 3, 3);
    addEdge(2, 3, 1);
    addEdge(2, 4, 5);
    addEdge(3, 4, 1);

    int source = 0;

    vector<int> dist = dijkstra(V, adj, source);

    cout << "Shortest Distance from Node " << source << ":\n";

    for(int i = 0; i < V; i++)
    {
        cout << "Node " << i << " -> " << dist[i] << endl;
    }

    return 0;
}
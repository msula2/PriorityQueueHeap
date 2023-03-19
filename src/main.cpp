#include <iostream>
#include <vector>
#include <queue>
#include <heap.hpp>

using namespace std;

const int INF = 1e9; // infinity

void Dijkstra(int start, vector<pair<int, int>> adj[], int V, int dist[], vector<int> prev[])
{
    Heap pq{};
    pq.StartHeap(V);
    dist[start] = 0;
    for (int i = 0; i < V; i++)
    {
        if (i != start)
        {
            dist[i] = INF;
        }
        HeapNode node;
        node.data = i;
        node.priority = dist[i];
        pq.Insert(node, dist[i]);
    }
    while (pq.getHeapSize() > 0)
    {
        HeapNode min = pq.FindMin();
        pq.ExtractMin();
        int u = min.data;
        for (auto v : adj[u])
        {
            int neighbor = v.first;
            int weight = v.second;

            if (dist[neighbor] > dist[u] + weight)
            {
                dist[neighbor] = dist[u] + weight;
                prev[neighbor].clear();
                prev[neighbor].push_back(u);
                HeapNode n;
                n.data = neighbor;
                n.priority = dist[neighbor];
                pq.ChangeKey(n, dist[neighbor]);
            }
            else if (dist[u] + weight == dist[neighbor])
            {
                prev[neighbor].push_back(u);
            }
        }
    }
}
void bfsDelete(vector<pair<int, int>> adj[], vector<int> prev[], int start, int end, int V)
{
    bool discovered[V] = {false};
    bool deleted[V] = {false};
    discovered[end] = true;
    vector<int> queue;
    int u = 0, index = 0;
    queue.push_back(end);
    while (queue.size() > 0)
    {
        u = queue.front();
        for (auto &edge : prev[u])
        {
            index = 0;
            for (auto &v : adj[edge])
            {
                if (v.first == u)
                {
                    adj[edge].erase(adj[edge].begin() + index);
                }
                index += 1;
            }
            queue.push_back(edge);
        }
        queue.erase(queue.begin());
    }
}
int main()
{
    int V = 0, E = 0, start = 0, end = 0;
    FILE *fptr;
    if ((fptr = fopen("./include/tests/test-35.txt", "r")) == NULL)
    {
        printf("Error in opening file\n");
        exit(1);
    }
    int v1 = 0, v2 = 0, distance = 0, z1 = 0, z2 = 0;
    fscanf(fptr, "%d %d\n", &V, &E);
    fscanf(fptr, "%d %d\n", &start, &end);
    vector<pair<int, int>> adj[V];
    for (int i = 0; i < E; i++)
    {
        fscanf(fptr, "%d %d %d\n", &v1, &v2, &distance);
        if (v1 != v2)
        {
            adj[v1].push_back(make_pair(v2, distance));
        }
    }
    fscanf(fptr, "%d %d\n", &z1, &z2);
    fclose(fptr);
    int dist[V];
    vector<int> prev[V];
    Dijkstra(start, adj, V, dist, prev);
    bfsDelete(adj, prev, start, end, V);
    Dijkstra(start, adj, V, dist, prev);

    if (dist[end] != INF){
        cout << dist[end] << "\n";
    }
    else{
        cout << "-1" << "\n";
    }
    

    return 0;
}

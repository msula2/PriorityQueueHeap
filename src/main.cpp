#include <iostream>
#include <vector>
#include <queue>
#include <heap.hpp>

using namespace std;

const int INF = 1e9; // infinity

void Dijkstra(int start, vector<pair<int, int>> adj[], int V, int * dist)
{
    // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // pq.push(make_pair(0, start)); // push the starting vertex with distance 0
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
        // int u = pq.top().second;
        // pq.pop();
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
                // pq.push(make_pair(dist[neighbor], neighbor));
                HeapNode n;
                n.data = neighbor;
                n.priority = dist[neighbor];
                pq.ChangeKey(n, dist[neighbor]);
            }
        }
    }
}

int main()
{
    int V = 0, E = 0, start = 0, end = 0;
    FILE *fptr;
    if ((fptr = fopen("./include/tests/test-18.txt", "r")) == NULL)
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
    int * dist = new int[V];
    Dijkstra(start, adj, V, dist);

    for (int i = 0; i < V; i++)
    {
        cout << "Shortest distance from " << start << " to " << i << " is " << dist[i] << endl;
    }

    return 0;
}

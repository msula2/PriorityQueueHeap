#include <iostream>
#include <stdio.h>
#include <vector>
#include <heap.hpp>

#define INFINITY 1000000
using namespace std;

struct Edge
{

    int vertex;
    int distance;
};
vector<Edge> *createGraph(int &start, int &end, int &V, int &E)
{
    int lines = 0;
    vector<Edge> *adj;

    FILE *fptr;
    if ((fptr = fopen("./include/tests/test-49.txt", "r")) == NULL)
    {
        printf("Error in opening file\n");
        exit(1);
    }
    else
    {
        int v1 = 0, v2 = 0, distance = 0;

        while (!feof(fptr))
        {
            if (lines == 0)
            {
                fscanf(fptr, "%d %d\n", &V, &E);
                lines += 1;
                adj = new vector<Edge>[V];
            }
            else if (lines == 1)
            {
                fscanf(fptr, "%d %d\n", &start, &end);
                lines += 1;
            }
            else
            {
                fscanf(fptr, "%d %d %d\n", &v1, &v2, &distance);
                lines += 1;
                if (v1 != v2)
                {
                    Edge e;
                    e.vertex = v2;
                    e.distance = distance;
                    adj[v1].push_back(e);
                }
            }
        }
        fclose(fptr);
    }

    return adj;
}
void printGraph(vector<Edge> *adj, int V)
{
    cout << "\nGraph Contents... \n";
    int v = 0;
    for (int x = 0; x < V; x++)
    {
        cout << "\n----------------------\n";
        cout << "Vertex: " << x << "\n";
        cout << "Neighbors: ";
        for (int y = 0; y < adj[x].size(); y++)
        {
            cout << adj[x][y].vertex
                 << "(" << adj[x][y].distance
                 << ")"
                 << ",";
        }
        cout << "\n----------------------\n";
    }
}
void printShortestPath(int start, int V, int *dist, vector<int> *prev)
{
    cout << "\nShortest Distance from " << start << " to: \n";
    for (int t = 0; t < V; t++)
    {
        if (t != start)
        {
            cout << "Node " << t << " = " << dist[t] << " | Previous = ";
            for (auto &previous : prev[t])
            {
                cout << previous << ",";
            }
            cout << "\n";
        }
    }
}
void Dijkstra(vector<Edge> *adj,
              int *dist, vector<int> *prev, int start, int V)
{
    cout << "\nDijkstra... \n";
    dist[start] = 0;
    Heap Q{};
    Q.StartHeap(V);
    for (int v = 0; v < V; v++)
    {
        if (v != start)
        {
            dist[v] = INFINITY;
        }
        HeapNode node;
        node.data = v;
        node.priority = dist[v];
        Q.Insert(node, dist[v]);
    }

    while (Q.getHeapSize() > 0)
    {
        HeapNode u = Q.FindMin();
        Q.ExtractMin();
        for (auto &neigh : adj[u.data])
        {
            int alt = dist[u.data] + neigh.distance;
            if (alt < dist[neigh.vertex])
            {
                dist[neigh.vertex] = alt;
                prev[neigh.vertex].clear();
                prev[neigh.vertex].push_back(u.data);
                HeapNode n;
                n.data = neigh.vertex;
                n.priority = alt;
                Q.ChangeKey(n, alt);
            }
            else if (alt == dist[neigh.vertex])
            {
                dist[neigh.vertex] = alt;
                prev[neigh.vertex].push_back(u.data);
            }
        }
    }
}
void almostShortestPath(vector<Edge> *adj, vector<int> *prev, int start, int end, int V)
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
                if (v.vertex == u)
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
/*
while (queue.size() > 0)
    {
        u = queue.front();
        cout << "Front Queue: " << u << "\n";
        for (auto &edge : prev[u])
        {
            index = 0;
            for (auto &v : adj[edge])
            {
                if (v.vertex == u)
                {
                    adj[edge].erase(adj[edge].begin() + index);
                    cout << "Erased edge: "
                         << "(" << edge << "," << v.vertex << ")"
                         << "\n";
                }
                index += 1;
            }
            queue.push_back(edge);
        }
        queue.erase(queue.begin());
    }

*/
int main()
{
    int V = 0, E = 0, start = 0, end = 0;
    vector<Edge> *adj = createGraph(start, end, V, E);
    // printGraph(adj);
    int *dist = new int(V);
    vector<int> *prev = new vector<int>[V];
    Dijkstra(adj, dist, prev, start, V);
    // printShortestPath(start, V, dist, prev);
    almostShortestPath(adj, prev, start, end, V);
    printGraph(adj, V);
}
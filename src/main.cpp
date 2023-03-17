
#include <heap.hpp>
#include <iostream>
#include <stdlib.h>
#include <map>
#include <list>

using namespace std;
#define INFINITY 1000000
#define UNDEFINED -1
struct Edge
{

    int vertex;
    int distance;
};

class Graph
{
public:
    Graph() = default;
    ~Graph(){
        delete[] dist;
    }
    void createGraph()
    {
        int lines = 0;

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
                    dist = new int(V);
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
                        adj[v1][v2] = distance;
                    }
                }
            }
            fclose(fptr);
        }

        return;
    }

    void dijkstra()
    {
        cout << "\nDijkstra... \n";
        dist[start] = 0;
        Heap Q{};
        Q.StartHeap(V);
        prev = new vector<vector<int>>(V);

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
                int alt = dist[u.data] + neigh.second;
                if (alt < dist[neigh.first])
                {
                    dist[neigh.first] = alt;
                    prev->at(neigh.first).clear();
                    prev->at(neigh.first).push_back(u.data);
                    HeapNode n;
                    n.data = neigh.first;
                    n.priority = alt;
                    Q.ChangeKey(n, alt);
                }
                else if (alt == dist[neigh.first])
                {
                    dist[neigh.first] = alt;
                    prev->at(neigh.first).push_back(u.data);
                }
            }
        }
    }
    void almostShortestPath()
    {
        dijkstra();
    }
    void printShortestPath()
    {
        cout << "Shortest Distance from " << start << " to: \n";
        for (int t = 0; t < V; t++)
        {
            if (t != start)
            {
                cout << "Node " << t << " = " << dist[t] << " | Previous = ";
                for (auto &previous : prev->at(t))
                {
                    cout << previous << ",";
                }
                cout << "\n";
            }
        }
    }

    void printGraph()
    {
        cout << "\nGraph Contents... \n";
        for (auto &u : adj)
        {
            cout << "\n----------------------\n";
            cout << "Vertex: " << u.first << "\n";
            cout << "Neighbors: ";
            for (auto &v : u.second)
            {
                cout << v.first << "(" << v.second << ")"
                     << ",";
            }
            cout << "\n----------------------\n";
        }
    }

private:
    int V;
    int E;
    int start;
    int end;
    map<int, map<int, int>> adj;
    int *dist;
    vector<vector<int>> *prev;
};

int main()
{
    Graph G = Graph{};
    G.createGraph();
    G.printGraph();
    G.dijkstra();
    // G.almostShortestPath();
    G.printShortestPath();
    return 0;
}


#include <heap.hpp>
#include <iostream>
#include <stdlib.h>

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
                    adj = new vector<vector<Edge>>(V);
                    dist = new int(V);
                    prev = new int(V);
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
                        adj->at(v1).push_back(e);
                    }
                }
            }
            fclose(fptr);
        }

        return;
    }
    void Dijkstra()
    {
        cout << "\nDijkstra... \n";
        dist[start] = 0;
        Heap Q{};
        Q.StartHeap(V);

        for (int v = 0; v < adj->size(); v++)
        {
            if (v != start)
            {
                dist[v] = INFINITY;
                prev[v] = UNDEFINED;
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
            for (auto &neigh : adj->at(u.data))
            {
                int alt = dist[u.data] + neigh.distance;
                if (alt < dist[neigh.vertex])
                {
                    dist[neigh.vertex] = alt;
                    prev[neigh.vertex] = u.data;
                    HeapNode n;
                    n.data = neigh.vertex;
                    n.priority = alt;
                    Q.ChangeKey(n, alt);
                }
            }
        }
        cout << "Shortest Distance from " << start << " to: \n";
        for (int t = 0; t < V; t++)
        {
            if (t != start)
            {
                cout << "Node " << t << " = "
                     << dist[t] << " | "
                                   "Prev "
                     << prev[t] << "\n";
            }
        }
    }
    void printGraph()
    {
        cout << "\nGraph Contents... \n";
        int v = 0;
        for (int x = 0; x < adj->size(); x++)
        {
            cout << "\n----------------------\n";
            cout << "Vertex: " << x << "\n";
            cout << "Neighbors: ";
            for (int y = 0; y < adj->at(x).size(); y++)
            {
                cout << adj->at(x).at(y).vertex
                     << "(" << adj->at(x).at(y).distance
                     << ")"
                     << ",";
            }
            cout << "\n----------------------\n";
        }
    }

    void deleteGraph()
    {

        //vector<vector<Edge>>().swap(*adj);
        delete[] dist;
        delete[] prev;
    }

private:
    int V;
    int E;
    int start;
    int end;
    vector<vector<Edge>> *adj;
    int *dist;
    int *prev;
};

int main()
{
    Graph G = Graph{};
    G.createGraph();
    G.printGraph();
    G.Dijkstra();
    //G.deleteGraph();
    return 0;
}


#include <heap.hpp>
#include <iostream>
#include <stdlib.h>

using namespace std;
struct Edge
{

    int vertex;
    int distance;
};

class Graph
{
public:
    // Constructor
    Graph() = default;
    void createGraph()
    {
        int lines = 0;

        FILE *fptr;
        if ((fptr = fopen("./include/tests/test-1.txt", "r")) == NULL)
        {
            printf("Error in opening file\n");
            exit(1);
        }
        else
        {
            int v1 = 0, v2 = 0, dist = 0;
            while (!feof(fptr))
            {
                if (lines == 0)
                {
                    fscanf(fptr, "%d %d\n", &V, &E);
                    lines += 1;
                    adj.resize(V);
                }
                else if (lines == 1)
                {
                    fscanf(fptr, "%d %d\n", &start, &end);
                    lines += 1;
                }
                else
                {
                    fscanf(fptr, "%d %d %d\n", &v1, &v2, &dist);
                    lines += 1;
                    if (v1 != v2)
                    {
                        Edge e;
                        e.vertex = v2;
                        e.distance = dist;
                        adj[v1].push_back(e);
                    }
                }
            }
            fclose(fptr);
        }

        return;
    }
    void printGraph()
    {
        int v = 0;
        for (auto &vertex : adj)
        {
            cout << "Vertex: " << v << "\n";
            cout << "Neighbors: ";
            for (auto &edges : vertex)
            {
                cout << edges.vertex << "(" << edges.distance << ")"
                     << ",";
            }
            v += 1;
            cout << "\n";
        }
    }

private:
    int V;
    int E;
    int start;
    int end;
    vector<vector<Edge>> adj;
};

int main()
{
    Graph G = Graph();
    G.createGraph();
    G.printGraph();
    return 0;
}

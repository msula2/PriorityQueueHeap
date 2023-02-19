#include <heap.hpp>
#include <iostream>

using namespace std;

int main()
{
    int N = 0;
    cout << "Enter the number of elements to be stored in heap: ";
    cin >> N;
    Heap H{};
    H.StartHeap(N);
    int data = 0;
    int priority = 0;

    for (int i = 0; i < N; i++)
    {
        cout << "Enter <data,priority> for node: ";
        scanf("%d,%d", &data, &priority);
        H.Insert(data, priority);
    }
    std::vector<HeapNode> heap = H.getHeap();
    for (int z = 0; z < heap.size(); z++)
    {
        if (z != 0)
        {
            cout << "Data: " << heap[z].data
                 << " Priority: " << heap[z].priority
                 << "\n";
        }
    }
    return 0;
}
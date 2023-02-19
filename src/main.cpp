#include <heap.hpp>
#include <iostream>

using namespace std;

int main()
{
    int N = 0;
    cout << "\nEnter the number of elements to be stored in heap: ";
    cin >> N;
    Heap H{};
    H.StartHeap(N);
    int data = 0;
    int priority = 0;
    cout << "\n";

    for (int i = 0; i < N; i++)
    {
        cout << "Enter <data,priority> for node: ";
        scanf("%d,%d", &data, &priority);
        HeapNode node;
        node.data = data;
        node.priority = priority;
        H.Insert(node, priority);
    }
    cout << "\nAfter insertion...\n";
    H.Print();

    HeapNode toDelete;
    cout << "\nEnter <data value> of node to delete: ";
    cin >> toDelete.data;
    H.Delete(toDelete);
    cout << "\nAfter deletion of node with data " <<  toDelete.data << " ...\n";
    H.Print();

    HeapNode min;
    min = H.FindMin();
    cout << "\nFinding minimum...\n";
    cout << "Minimum Node: "
         << "priority = " << min.priority
         << " | data = " << min.data
         << "\n";

    H.ExtractMin();
    cout << "\nAfter Extraction of minimum...\n";
    H.Print();

    return 0;
}
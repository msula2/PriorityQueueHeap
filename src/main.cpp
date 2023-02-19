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
        //cout << "Enter <data,priority> for node: ";
        //scanf("%d,%d", &data, &priority);
        cout << "Enter <priority> for node: ";
        cin >> priority;
        H.Insert(data, priority);
    }
    cout << "After inserting\n";
    H.printHeap();
    H.Delete(2);
    cout << "After deleting\n";
    H.printHeap();

    return 0;
}
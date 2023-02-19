#include <heap.hpp>
#include <iostream>

// Constructor
Heap::Heap() = default;
// Initializes an empty that is set to store at most N elements
void Heap::StartHeap(int n)
{
    std::vector<HeapNode> heap(n + 1); //vector of n HeapNodes
    H = heap;
    sizeHeap = 0;
    N = n;
}
void Heap::SwapNodes(int parentIndex, int childIndex)
{

    HeapNode temp = H[parentIndex];
    H[parentIndex] = H[childIndex];
    H[childIndex] = temp;

}
// Moves an element located at the specified index upwards in the heap to correctly reposition it so that the element's prioirty is higher than parents
void Heap::HeapifyUp(int index)
{
    // Not root node
    if (index > 1)
    {
        int parent = index / 2;
        if (H[index].priority < H[parent].priority)
        {
            SwapNodes(parent, index);
            HeapifyUp(parent);
        }
        
    }
}
// Inserts the item with an ordering value (priority) into the heap at its end
// After inserting uses HeapifyUp to position the item so it maintains the heap order
// If the heap currently has n elements, the method takes O(logn) time
void Heap::Insert(int item, int value)
{

    HeapNode node;
    node.data = item;
    node.priority = value;
    if (sizeHeap < N)
    {
        H[sizeHeap + 1] = node; // H[0] is kept empty, element is inserted at end of array
        sizeHeap += 1;
        HeapifyUp(sizeHeap);
    }
}
std::vector<HeapNode> Heap::getHeap(){
    return H;
}

#include <heap.hpp>
#include <iostream>

// Constructor
Heap::Heap() = default;
// Initializes an empty that is set to store at most N elements
void Heap::StartHeap(int n)
{
    std::vector<HeapNode> heap(n + 1); // vector of n HeapNodes
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
void Heap::Heapify_Up(int index)
{
    // Not root node
    if (index > 1)
    {
        int parent = index / 2;
        // A lower value of H[index].priority indicates that the element is more important and should be moved up
        if (H[index].priority < H[parent].priority)
        {
            SwapNodes(parent, index);
            Heapify_Up(parent);
        }
    }
}
// Inserts the item with an ordering value (priority) into the heap at its end
// After inserting uses Heapify_Up to position the item so it maintains the heap order
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
        Heapify_Up(sizeHeap);
    }
}
void Heap::Heapify_Down(int index)
{

    int childIndex = 0;
    int leftIndex = 2 * index;
    int rightIndex = 2 * index + 1;
    std::cout << "Left index = " << H[leftIndex].priority << " and " << "Right Index = " << H[rightIndex].priority << "\n";
    if (leftIndex > sizeHeap)
    {
        // No left child exists
        return;
    }
    else if (leftIndex < sizeHeap)
    {
        // Get mimimum of the two children if H[index]
        childIndex = H[leftIndex].priority < H[rightIndex].priority ? leftIndex : rightIndex;
        std::cout << "Child = " << H[childIndex].priority << "\n";
    }
    else if (leftIndex = sizeHeap)
    {
        // Child is last element
        childIndex = sizeHeap;
    }
    // A Higher value of H[index].priority indicates that the element is less important and should be moved down
    if (H[index].priority > H[childIndex].priority)
    {
        SwapNodes(index, childIndex);
        // Moving the element down, causes damaged site to move downwards, hence we call Heapify_Down again to fix it
        std::cout << "After HeapifyDown " << H[index].priority << " and " << H[childIndex].priority << "\n";
        printHeap();
        Heapify_Down(childIndex);
    }
}
void Heap::Delete(int index)
{

    std::cout << "After Delete " << H[index].priority << " and swap with " << H[sizeHeap].priority << "\n";
    SwapNodes(index, sizeHeap);
    H.erase(H.begin() + sizeHeap); // delete the element
    sizeHeap -= 1;                 // decrease size of heap
    printHeap();
    Heapify_Down(index);
}
std::vector<HeapNode> Heap::getHeap()
{
    return H;
}
void Heap::printHeap()
{
    for (int z = 0; z < H.size(); z++)
    {
        if (z != 0)
        {
            std::cout << " Priority: " << H[z].priority << "\n";
        }
    }
}

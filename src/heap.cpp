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

    // Update position of elements in Position array
    Position[H[parentIndex].data] = childIndex;
    Position[H[childIndex].data] = parentIndex;

    // Swap parent with child and vice versa
    HeapNode tempNode = H[parentIndex];
    H[parentIndex] = H[childIndex];
    H[childIndex] = tempNode;
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
void Heap::Insert(HeapNode item, int value)
{

    if (sizeHeap < N)
    {
        H[sizeHeap + 1] = item; // H[0] is kept empty, element is inserted at end of array
        sizeHeap += 1;
        Position[item.data] = sizeHeap;
        Heapify_Up(sizeHeap);
    }
}
void Heap::Heapify_Down(int index)
{

    int childIndex = 0;
    int leftIndex = 2 * index;
    int rightIndex = 2 * index + 1;
    if (leftIndex > sizeHeap)
    {
        // No left child exists
        return;
    }
    else if (leftIndex < sizeHeap)
    {
        // Get mimimum of the two children if H[index]
        childIndex = H[leftIndex].priority < H[rightIndex].priority ? leftIndex : rightIndex;
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
        Heapify_Down(childIndex);
    }
}
void Heap::Delete(int index)
{
    SwapNodes(index, sizeHeap);
    H.erase(H.begin() + sizeHeap); // delete the element
    sizeHeap -= 1;                 // decrease size of heap
    Heapify_Down(index);
}
void Heap::Delete(HeapNode item){
    int deleteIndex = Position[item.data]; //find index of element to delete using map
    Delete(deleteIndex); //remove element from heap
    Position.erase(item.data);  //remove the element from map
}
HeapNode Heap::FindMin()
{
    int front = 1;
    return H[front];
}
void Heap::ExtractMin()
{

    HeapNode min = FindMin();
    int front = 1;
    Delete(front);
    Position.erase(min.data);
}
void Heap::Print()
{
    std::cout << "Min Heap: |";
    for (int z = 0; z < H.size(); z++)
    {
        if (z != 0)
        {
            std::cout << H[z].priority << "|";
        }
    }
    
    std::cout << "\nPosition: |";
    for (auto& element : Position){
        std::cout << element.first << "-" << element.second << "|";
    }
    std::cout << "\n";
}

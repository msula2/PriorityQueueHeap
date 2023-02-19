#ifndef HEAP_HPP
#define HEAP_HPP
#include <vector>

//Represents an individual node in the heap
struct HeapNode{
    
    int data;
    int priority;
};

class Heap{
    public:
        Heap();
        void StartHeap(int N);
        void Insert(int item, int value);
        void HeapifyUp(int index);
        void SwapNodes(int parent, int child);
        std::vector<HeapNode> getHeap();
    
    private:
        std::vector<HeapNode> H;
        int N; //number of elements for which space was allocated
        int sizeHeap; //number of elements in the heap at any time, not the size of array
};
#endif
#ifndef HEAP_HPP
#define HEAP_HPP
#include <cstdlib>

//Represents an individual node in the heap
struct HeapNode{
    
    int data;
    int priority;
};

class Heap{
    public:
        Heap();
        void StartHeap(int N);
        void FreeHeap();
        void Insert(int item, int value);
        void HeapifyUp(int index);
        void SwapNodes(int parent, int child);
        HeapNode * getHeap();
    
    private:
        HeapNode * H;
        int N; //number of elements for which space was allocated
        int sizeHeap; //number of elements in the heap at any time, not the size of array
};
#endif
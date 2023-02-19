#ifndef HEAP_HPP
#define HEAP_HPP
#include <vector>
#include <map>
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
        void Heapify_Up(int index);
        void SwapNodes(int parent, int child);
        void Delete(int index);
        void Heapify_Down(int index);
        HeapNode FindMin();
        void ExtractMin();
        void Print();
    
    private:
        std::vector<HeapNode> H; //heap containing HeapNodes
        int N; //number of elements for which space was allocated
        int sizeHeap; //number of elements in the heap at any time, not the size of array
        std::map<int,int> Position; //map for maintaining position of elements in heap
};
#endif
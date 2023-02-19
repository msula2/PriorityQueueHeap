#ifndef HEAP_HPP
#define HEAP_HPP
#include <vector>
#include <map>
enum Methods
{
    Exit = 0,
    Insert = 1,
    Delete = 2,
    FindMin = 3,
    ExtractMin = 4,
    ChangeKey = 5,
    Print = 6
};
//Represents an individual node in the heap
struct HeapNode{
    
    int data;
    int priority;
};

class Heap{
    public:
        Heap();
        void StartHeap(int N);
        void Insert(HeapNode item, int value);
        void Heapify_Up(int index);
        void SwapNodes(int parent, int child);
        void Delete(int index);
        void Delete(HeapNode item);
        void Heapify_Down(int index);
        HeapNode FindMin();
        void ExtractMin();
        void ChangeKey(HeapNode item, int newValue);
        void Print();
        void DisplayOptions();
    
    private:
        std::vector<HeapNode> H; //heap containing HeapNodes
        int N; //number of elements for which space was allocated
        int sizeHeap; //number of elements in the heap at any time, not the size of array
        std::map<int,int> Position; //map for maintaining position of elements in heap
};
#endif
#include <heap.hpp>

Heap::Heap(){

}
//Initializes an empty that is set to store at most N elements
void Heap::StartHeap(int n){
    
    H = (HeapNode*) malloc((N + 1) * sizeof(HeapNode));
    sizeHeap = 0;
    N = n;
}
void Heap::Insert(int item, int value){
    
    HeapNode node;
    node.data = item;
    node.priority = value;
    if (sizeHeap < N){
        H[sizeHeap + 1] = node; //H[0] is kept empty, element is inserted at end of array
        sizeHeap += 1;
    }
    
}
HeapNode * Heap::getHeap(){
    return H;
}
void Heap::FreeHeap(){
    free(H);
}
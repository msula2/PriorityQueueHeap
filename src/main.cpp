#include <heap.hpp>
#include <iostream>

using namespace std;

int main()
{
    cout << "Priorty Queue Implementation Using Min Heap\n";
    cout << "............................................\n";
    int N = 0;
    cout << "Enter the number of elements to be stored in heap: ";
    cin >> N;
    Heap H{};
    H.StartHeap(N);
    H.DisplayOptions();
    return 0;
}
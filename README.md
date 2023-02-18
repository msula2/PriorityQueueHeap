***
## Priority Queue using a Heap
***

### Purpose: 
 - Demonstrate the usage of the heap data structure for implementing a priority queue. 

***

### Why other methods prove inefficient: 
 
 - A natural approach to implementing a priority queue would be to have elements in a list, or have a pointer labeled `Min` to the element with highest priority. While this may allow extraction in _O(1)_, after removing the minimum we will have to update our pointer , hence scan all elements thus _O(n)_. 
 
 - Maybe we could maintain elements in a sorted order, hence using binary search we could find the position to insert the element in _O(logn)_ but to insert the element into the array we would have to move existing elements one position to the right, this would take _O(n)_ time. 
 
 - Another approach could be to use a doubly linked list, we could insert in _O(1)_ time into any position, but the dpubly linked list wouldn't support binary search, hence we would need upto _O(n)_ time to search for the position for a new element to be inserted.   

***

### Benefits of using Heap: 

- The heap data structure combines the benefits of a sorted array and list for purposes of this application. 

- The tree will have a root, and each node can have up to two children, a left and a right child. The keys in such a binary tree are said to be in heap order if the key of any element is at least as large as the key of the element at its parent node in the tree. Hence the parents will always be less than their children. 

- Heaps can be maintained in an array, `H` indexed by _i = 1....N_, with the `root = H[1]`, `leftChild(i) = 2i`, `rightChild(i) = 2i + 1`, `parent(i) = floor(i/2)` 

***
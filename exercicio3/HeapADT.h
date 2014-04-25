// Heap class
template <typename E> class HeapADT {
private:
    virtual void heapfy(int pos) = 0;
public:
    int n;               // Number of elements now in the heap
    int maxsize;         // Maximum size of the content
    E* content;          // Pointer to the heap array
    virtual int size() const = 0;// Return current heap size
    virtual bool isLeaf(int pos) const = 0; // True if pos is a leaf
    virtual int left(int pos) const = 0; // Return left child position
    virtual int righ(int pos) const = 0;// Return right child position
    virtual int parent(int pos) const = 0; // Return parent position
    virtual void buildMaxHeap() = 0; // Heapify contents of Heap
    virtual void insert(const E& it) = 0; // Insert "it" into the heap
    virtual E removefirst() = 0; // Remove first value
    virtual E remove(int pos) = 0; // Remove and return element at specified position
};

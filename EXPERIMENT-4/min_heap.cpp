#include<bits/stdc++.h>
using namespace std;

#define MAX 100

int heap[MAX];
int heapSize = 0;

void heapifyDown(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < heapSize && heap[smallest] > heap[left])
        smallest = left;
    if (right < heapSize && heap[smallest] > heap[right])
        smallest = right;
    
    if (smallest != i) {
        swap(heap[smallest], heap[i]);
        heapifyDown(smallest);
    }
}

void heapifyUp(int i) {
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(heap[(i - 1) / 2], heap[i]);
        i = (i - 1) / 2;
    }
}

void insert(int val) {
    if (heapSize == MAX) {
        cout << "Heap overflow!" << endl;
        return;
    }
    
    heap[heapSize] = val;
    heapSize++;
    heapifyUp(heapSize - 1);
}

void deleteRoot() {
    if (heapSize == 0) {
        cout << "Heap underflow!" << endl;
        return;
    }
    
    heap[0] = heap[heapSize - 1];
    heapSize--;
    heapifyDown(0);
}

int search(int val) {
    for (int i = 0; i < heapSize; i++) {
        if (heap[i] == val) {
            cout << "Found " << val << " at position " << i << endl;
            return i;
        }
    }
    cout << val << " not found!" << endl;
    return -1;
}

void deleteElement(int val) {
    int index = search(val);
    if (index == -1) return;
    
    heap[index] = heap[heapSize - 1];
    heapSize--;
    
    heapifyUp(index);
    heapifyDown(index);
    cout << val << " deleted successfully!" << endl;
}

void display() {
    cout << "Min Heap: ";
    for (int i = 0; i < heapSize; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main() {
    cout << "=== Min Heap Operations ===" << endl;
    
    insert(10);
    insert(20);
    insert(30);
    insert(1);
    insert(15);
    insert(5);
    
    cout << "\nAfter insertions:" << endl;
    display();
    
    cout << "\nSearching for 15:" << endl;
    search(15);
    
    cout << "\nSearching for 100:" << endl;
    search(100);
    
    cout << "\nDeleting element 20:" << endl;
    deleteElement(20);
    display();
    
    cout << "\nDelete root (min element):" << endl;
    deleteRoot();
    display();
    
    cout << "\nDelete another element 30:" << endl;
    deleteElement(30);
    display();
    
    return 0;
}

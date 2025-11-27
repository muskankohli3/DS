#include <iostream>
using namespace std;

class PriorityQueue {
private:
  int* heap;
  int size;
  int capacity;
  bool maxHeap;

  void heapp(int i) {
    int root = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (maxHeap) {
    if (left < size && heap[left] > heap[root])
      root = left;
    if (right < size && heap[right] > heap[root])
      root = right;
    } else {
    if (left < size && heap[left] < heap[root])
      root = left;
    if (right < size && heap[right] < heap[root])
      root = right;
    }

    if (root != i) {
    swap(heap[i], heap[root]);
    heapp(root);
    }
  }

  public:
  PriorityQueue(int cap, bool isMax = true) {
    heap = new int[cap];
    capacity = cap;
    size = 0;
    maxHeap = isMax;
  }

  void insert(int val) {
    if (size == capacity) return;
    heap[size++] = val;
    int i = size - 1;
    while (i != 0 && ((maxHeap && heap[i] > heap[(i - 1) / 2]) || (!maxHeap && heap[i] < heap[(i - 1) / 2]))) {
    swap(heap[i], heap[(i - 1) / 2]);
    i = (i - 1) / 2;
    }
  }

  int extractTop() {
    if (size <= 0) return -1;
    if (size == 1) {
    size--;
    return heap[0];
    }

    int root = heap[0];
    heap[0] = heap[--size];
    heapp(0);
    return root;
  }

  void print() {
    for (int i = 0; i < size; i++)
    cout << heap[i] << " ";
    cout << endl;
  }

  ~PriorityQueue() {
    delete[] heap;
  }
};

int main() {
  PriorityQueue pq(10, true); // Max heap

  pq.insert(10);
  pq.insert(20);
  pq.insert(15);
  cout << "Priority Queue (max): ";
  pq.print();
  cout << "Extracted: " << pq.extractTop() << endl;
  cout << "After extraction: ";
  pq.print();

  return 0;
}

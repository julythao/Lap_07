#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    void heapify(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < heap.size() && heap[left] > heap[largest]) {
            largest = left;
        }

        if (right < heap.size() && heap[right] > heap[largest]) {
            largest = right;
        }

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapify(largest);
        }
    }

public:
    MaxHeap() {}

    void insert(int value) {
        heap.push_back(value);

        int index = heap.size() - 1;
        int parent = (index - 1) / 2;

        while (index > 0 && heap[index] > heap[parent]) {
            swap(heap[index], heap[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    void remove(int value) {
        int index = -1;
        for (int i = 0; i < heap.size(); i++) {
            if (heap[i] == value) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            cout << "ko co phan tu heap." << endl;
            return;
        }

        heap[index] = heap.back();
        heap.pop_back();
        heapify(index);
    }

    void heapSort() {
        int n = heap.size();

        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(i);
        }

        for (int i = n - 1; i > 0; i--) {
            swap(heap[0], heap[i]);
            heapify(0);
        }
    }

    void display() {
        for (int i = 0; i < heap.size(); i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeap heap;


    heap.insert(45);
    heap.insert(36);
    heap.insert(54);
    heap.insert(27);
    heap.insert(63);
    heap.insert(72);
    heap.insert(61);
    heap.insert(18);

    cout << "Max Heap: ";
    heap.display();

   
    heap.insert(50);
    cout << "them pt: 50: ";
    heap.display();

    heap.remove(63);
    cout << "xoa pt: 63: ";
    heap.display();

    heap.heapSort();
    cout << "Sx giam danr: ";
    heap.display();

    return 0;
}

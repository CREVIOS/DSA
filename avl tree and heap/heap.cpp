#include <iostream>

struct Heap {
    int arr[100000];
    int size = 0;

    void insert(int val) {
        arr[size] = val;
        size++;
        int current = size - 1;
        while (current > 0 && arr[current] > arr[(current - 1) / 2]) {
            int temp = arr[current];
            arr[current] = arr[(current - 1) / 2];
            arr[(current - 1) / 2] = temp;
            current = (current - 1) / 2;
        }
    }

    int extract_max() {
        if (size == 0) return -1; // or throw an exception

        int ret = arr[0];
        arr[0] = arr[size - 1];
        size--;
        heapify(0);
        return ret;
    }

    void heapify(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < size && arr[left] > arr[largest]) {
            largest = left;
        }
        if (right < size && arr[right] > arr[largest]) {
            largest = right;
        }
        if (largest != index) {
            int swap = arr[index];
            arr[index] = arr[largest];
            arr[largest] = swap;
            heapify(largest);
        }
    }

    void buildHeap() {
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(i);
        }
    }

    void heapSort() {
        buildHeap();
        int currentSize = size;
        for (int i = size - 1; i > 0; i--) {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            size--;
            heapify(0);
        }
        size = currentSize;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Heap myHeap;

    myHeap.insert(30);
    myHeap.insert(10);
    myHeap.insert(20);
    myHeap.insert(50);
    myHeap.insert(40);

    std::cout << "Heap after inserts: ";
    myHeap.display();

    std::cout << "Extracted max: " << myHeap.extract_max() << std::endl;

    std::cout << "Heap after extracting max: ";
    myHeap.display();

    myHeap.insert(60);
    myHeap.insert(70);
    myHeap.insert(80);

    std::cout << "Heap before sort: ";
    myHeap.display();

    myHeap.heapSort();

    std::cout << "Heap after heapSort: ";
    myHeap.display();

    return 0;
}

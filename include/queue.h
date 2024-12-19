#include <iostream>

template <typename T>
class Queue {
private:
    T* data;
    int capacity;
    int size;

    void repack() {
        int cap = capacity * 2;
        int* data2 = new int[cap];
        for (int i = 0; i < size; i++) data2[i] = data[i];
        delete[] data;
        data = data2;
        capacity = cap;
    }

public:
    Queue(int cap = 2) : capacity(cap), size(0) {
        data = new int[capacity];
    }

    ~Queue() { delete[] data; }

    int get_size() const { return size; }

    int is_empty() const { return size == 0; }

    void push(int val) {
        if (size == capacity) repack();
        data[size++] = val;
    }

    T pop() {
        if (is_empty()) return 0;
        T val = data[0];
        for (int i = 1; i < size; i++) data[i - 1] = data[i];
        size--;
        return val;
    }

    void clear() {
        data = new int[0];
        size = 0;
    }
};

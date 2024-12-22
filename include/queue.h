#include <iostream>

template <typename T>
class Queue {
private:
    T* data;
    int capacity;
    int size;
    int start;
    int end;

    void repack() {
        int cap = capacity * 2;
        T* data2 = new T[cap];
        for (int i = 0; i < size; i++) data2[i] = data[(i + start) % capacity];
        delete[] data;
        data = data2;
        capacity = cap;
        start = 0;
        end = size;
    }

public:
    Queue(int cap = 2) : capacity(cap), size(0), start(0), end(0) {
        data = new int[capacity];
    }

    ~Queue() { delete[] data; }

    int get_size() const { return size; }

    int is_empty() const { return size == 0; }

    void push(const T& val) {
        if (size == capacity) repack();
        data[end] = val;
        end = (end + 1) % capacity;
        size++;
    }

    T pop() {
        if (is_empty()) throw "Queue is empty";
        T val = data[0];
        start++;
        size--;
        return val;
    }

    void clear() {
        data = new T[0];
        size = 0;
    }
};

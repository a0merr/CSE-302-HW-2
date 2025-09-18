#ifndef QUETYPE_H
#define QUETYPE_H

#include <iostream>
#include <cassert>

template <class ItemType>
class QueType {
private:
    static const int maxQue = 100;
    ItemType items[maxQue];
    int front;
    int rear;

public:
    QueType();
    bool IsEmpty() const;
    bool IsFull() const;
    void Enqueue(ItemType item);
    void Dequeue(ItemType& item);
};

template <class ItemType>
QueType<ItemType>::QueType() {
    front = 0;
    rear = -1;
}

template <class ItemType>
bool QueType<ItemType>::IsEmpty() const {
    return (rear < front);
}

template <class ItemType>
bool QueType<ItemType>::IsFull() const {
    return (rear == maxQue - 1);
}

template <class ItemType>
void QueType<ItemType>::Enqueue(ItemType item) {
    if (IsFull()) {
        std::cerr << "Queue is full. Cannot enqueue.\n";
        return;
    }
    rear++;
    items[rear] = item;
}

template <class ItemType>
void QueType<ItemType>::Dequeue(ItemType& item) {
    assert(!IsEmpty());  
    item = items[front];
    front++;
}

#endif

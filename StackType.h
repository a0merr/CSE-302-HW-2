#ifndef STACKTYPE_H
#define STACKTYPE_H

#include <iostream>
#include <cassert>

template <class ItemType>
class StackType {
private:
    static const int maxStack = 100;
    ItemType items[maxStack];
    int top;

public:
    StackType();
    bool IsEmpty() const;
    bool IsFull() const;
    void Push(ItemType item);
    ItemType Pop();
};

template <class ItemType>
StackType<ItemType>::StackType() {
    top = -1;
}

template <class ItemType>
bool StackType<ItemType>::IsEmpty() const {
    return (top == -1);
}

template <class ItemType>
bool StackType<ItemType>::IsFull() const {
    return (top == maxStack - 1);
}

template <class ItemType>
void StackType<ItemType>::Push(ItemType item) {
    if (IsFull()) {
        std::cerr << "Stack is full. Cannot push.\n";
        return;
    }
    top++;
    items[top] = item;
}

template <class ItemType>
ItemType StackType<ItemType>::Pop() {
    assert(!IsEmpty());  // Make sure stack is not empty
    ItemType item = items[top];
    top--;
    return item;
}

#endif


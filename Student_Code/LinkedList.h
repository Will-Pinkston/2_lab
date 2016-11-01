#pragma once

#include "LinkedListInterface.h"

using namespace std;

template<class T>
class LinkedList : public LinkedListInterface<T> {

public:
    
    class Node {
    private:
        T data;
        Node* next;
    };
    
    Node* _Head;
    Node* _Tail;
    
    LinkedList(void);
    ~LinkedList(void);
    void insertHead(T value);
    void insertTail(T value);
    void insertAfter(T value, T insertionNode);
    void remove(T value);
    void clear();
    T at(int index);
    int size();
};

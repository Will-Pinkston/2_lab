
#include "LinkedList.h"

//-----------------------------------------------
//-----------------------------------------------

template<class T>
LinkedList<T>::LinkedList() {
    _Head = new Node;
    _Tail = NULL;
}

template<class T>
LinkedList<T>::~LinkedList() {
    delete _Head;
    delete _Tail;
}

//-----------------------------------------------
//-----------------------------------------------

template<class T>
void LinkedList<T>::insertHead(T value) {
    _Head->Node::data = value;
    _Head->Node::next = NULL;
}

template<class T>
void LinkedList<T>::insertTail(T value) {
    _Tail = new Node;
    _Tail->Node::data = value;
    _Tail->Node::next = NULL;
}

template<class T>
void LinkedList<T>::insertAfter(T value, T insertionNode) {
    
}

template<class T>
void LinkedList<T>::remove(T value) {
    
}

template<class T>
void LinkedList<T>::clear() {
    
}

template<class T>
T LinkedList<T>::at(int index) {
    T ret;
    return ret;
}

template<class T>
int LinkedList<T>::size() {
    return -1;
}


//-----------------------------------------------
//-----------------------------------------------




#pragma once

#include <iostream>
#include <stdexcept>
#include "LinkedListInterface.h"

using namespace std;

template<class T>
class LinkedList : public LinkedListInterface<T> {
private:
    class Node {
    public:
        Node(){next = NULL;}
        T data;
        Node* next;
    };
    
    Node* _Head;
    Node* _Tail;
public:
    LinkedList();
    ~LinkedList();
    void insertHead(T value);
    void insertTail(T value);
    void insertAfter(T value, T insertionNode);
    void remove(T value);
    void clear();
    T at(int index);
    int size();
    
    // functions I added
    bool checkVal(T val, Node*);
};


//-----------------------------------------------
//-----------------------------------------------
// constructor and destructor

template <class T>
LinkedList<T>::LinkedList() {
    _Head = NULL;
    _Tail = NULL;
}

template <class T>
LinkedList<T>::~LinkedList() {
    clear();
}

//-----------------------------------------------
//-----------------------------------------------
// insert functions

template<class T>
void LinkedList<T>::insertHead(T value) {
    cout << "insertHead(" << value << ")" << endl;
    if (_Head == NULL)
    {
        _Head = new Node;
        _Head->data = value;
        _Head->next = NULL;
        _Tail = _Head;
    }
    else
    {
        if (!checkVal(value, _Head))
        {
            return;
        }
        else
        {
            Node* insert = new Node;
            insert->next = _Head;
            insert->data = value;
            _Head = insert;
        }
    }
}

template<class T>
void LinkedList<T>::insertTail(T value) {
    cout << "insertTail(" << value << ")" << endl;
    if (_Tail == NULL)
    {
        _Head = new Node;
        _Head->data = value;
        _Head->next = NULL;
        _Tail = _Head;
    }
    else
    {
        if (!checkVal(value, _Head))
        {
            return;
        }
        else
        {
            Node* insert = new Node;
            insert->data = value;
            _Tail->next = insert;
            insert->next = NULL;
            _Tail = insert;
        }
    }
}

template<class T>
void LinkedList<T>::insertAfter(T value, T insertionNode) {
    cout << "insertAfter(" << value << ", " << insertionNode << ")" << endl;
    if (_Head == NULL) return;
    
    Node* check = _Head;
    if (!checkVal(value,check)) return;
    
    bool found = false;
    while (!found)
    {
        if (check->data == insertionNode) found = true;
        else
        {
            check = check->next;
        }
    }
    Node* insert = new Node;
    insert->data = value;
    insert->next = check->next;
    check->next = insert;
    if (check == _Tail) _Tail = insert;
}

//------------------------------------------------------------
//------------------------------------------------------------

template<class T>
void LinkedList<T>::remove(T value) {
    cout << "remove(" << value << ")" << endl;
    Node* find = _Head;
    if (checkVal(value, find)) return;
    
    bool found = false;
    bool isHead = false;
    while (!found)
    {
        if (find->data == value) {found = true; isHead = true;}
        else if (find->next->data == value) found = true;
        else find = find->next;
    }
    if (isHead)
    {
        _Head = find->next;
        delete find;
        find = NULL;
    }
    else
    {
        Node* kickIt = find->next;
        find->next = find->next->next;
        delete kickIt; //double check this later
        kickIt = NULL;
    }
}

template<class T>
void LinkedList<T>::clear() {
    int size_index = size();
    Node* spec;
    for (int i = --size_index; i >= 0; i--)
    {
        spec = _Head;
        for (int j = 0; j < i; j++)
        {
            spec = spec->next;
        }
        delete spec;
        spec = NULL;
    }
    _Head = NULL;
    _Tail = NULL;
}

template<class T>
T LinkedList<T>::at(int index) {
    int checkSize = size();
    if (checkSize != 0)
    {
        if (index < 0 || index > checkSize - 1) throw out_of_range("at()");
    }
    
    Node* find = _Head;
    for (int i = 0; i < index; i++)
    {
        if (find->next == NULL) throw out_of_range("at()"); //what string am i supposed to pass in?
        find = find->next;
    }
    return find->data;
}

template<class T>
int LinkedList<T>::size() {
    if (_Head == NULL) return 0;
    
    int num = 1;
    Node* count = _Head;
    while(count->next != NULL)
    {
        num++;
        count = count->next;
    }
    return num;
}


//-----------------------------------------------
//-----------------------------------------------
//helper functions - I added these

template<class T>
bool LinkedList<T>::checkVal(T val, Node* check)
{
    if (check->data != val && check->next == NULL)
    {
        return true;
    }
    else
    {
        if (check->data == val) return false;
        else
        {
            return checkVal(val, check->next);
        }
    }
}

//check through the list for a value
//if the value is found in the list, return true
//if the value is not found in the list, return false
//end checkVal()

//-----------------------------------------------
//-----------------------------------------------




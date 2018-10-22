#pragma once

template<class T> class LinkedList
{
public:
    LinkedList()
    {

    }

    LinkedList(int size_)
    {
         
    }

    void appendNode(const T& addThis);

    void insertNode(const T& addThis, int pos);

    void deleteNode(int pos);

    T* getNode(int pos) const;

    T* findNode(T findThis) const;

    ~LinkedList();

private:
    T node;
    T* next;
    T* prev;

    int size;

};
#pragma once

#include "Computer.hpp"

struct CompuNode
{
    CompuNode* next;
    CompuNode* prev;

    Computer node;
};

class LinkedList
{
public:
    LinkedList()
    {
        size = 0;

        head->next = nullptr;
        head->prev = nullptr;
    }

    void appendNode(const Computer& addThis)
    {
        CompuNode* newNode = new CompuNode;
        newNode->node = addThis;
        head->next;
        
    }

    void insertNode(const Computer& addThis, int pos)
    {

    }

    void deleteNode(int pos);

    Computer* getNode(int pos) const;

    Computer* findNode(Computer findThis) const;

    ~LinkedList();

    int size;
    CompuNode* head;

};
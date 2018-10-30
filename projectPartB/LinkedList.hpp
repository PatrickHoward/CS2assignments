#pragma once

#include "Computer.hpp"

struct CompuNode
{
    CompuNode(CompuNode* next_, Computer data_)
        : next(next_),
        data(data_)
    {
    
    }

    CompuNode* next;
    Computer data;
};

class LinkedList
{
public:
    LinkedList()
    {
        size = 0;

        head = nullptr;
        tail = nullptr;
    }

    void appendNode(Computer addThis)
    {
        size++;

        CompuNode newNode(nullptr, addThis);

        if(!head)
        {
            head = &newNode;
        }
        
        
        


    }

    Computer* getNode(int pos) const;
        
    Computer* findNode(Computer findThis) const;

    ~LinkedList();

    int size;
    CompuNode* head;
    CompuNode* tail;

};
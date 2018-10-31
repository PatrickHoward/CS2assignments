#pragma once

#include "Computer.hpp"

struct CompuNode
{
    Computer data;
    CompuNode* next;
};

class LinkedList
{
public:
    LinkedList()
    {
        size = 0;

        head = NULL;
        tail = NULL;
    }

    void appendNode(Computer addThis)
    {
        size++;

        CompuNode* tempNode = new CompuNode;
        tempNode->data = addThis;
        tempNode->next = NULL;

        if(head == NULL)
        {
            head = tempNode;
            tail = tempNode; 

            tempNode = NULL;
        }
        else
        {
            tail->next = tempNode;
            tail = tempNode;
        }

    }

    CompuNode* getNNode(int pos)
    {
        CompuNode* tempNode = new CompuNode;
        tempNode = head;

        for(int i = 0; i < pos || tempNode != NULL; ++i)
        {
            tempNode = tempNode->next;
        }

        return tempNode;

    }

    int size;
    CompuNode* head;
    CompuNode* tail;


};
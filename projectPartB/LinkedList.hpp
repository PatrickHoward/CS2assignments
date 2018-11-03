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

    CompuNode* goToNComp(int n)
    {
        CompuNode* tmp = head;

        for (int i = 0; i < n-1; ++i)
        {
            tmp = tmp->next;
            std::cout << this << '\n';
        }

        return tmp;
    }

    int size;
    CompuNode* head;
    CompuNode* tail;


};
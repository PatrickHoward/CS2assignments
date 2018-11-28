#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "Computer.hpp"
#include <iostream>

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

        tail->data.assignSeatLocation(size);

    }

    CompuNode* goToNComp(int n)
    {
        CompuNode* tmp = head;

        for (int i = 0; i < n-1; ++i)
        {
            tmp = tmp->next;
        }

        return tmp;
    }

    CompuNode* findComputerByID(int userID)
    {
        CompuNode* tmp = head;
        while(tmp->data.getID() != userID && tmp->next != NULL)
        {
            tmp = tmp->next;

        }

        return tmp;
    }

    void displayEach(CompuNode* current, int index)
    {

        if(current->next == NULL)
        {
            return;
        }

        std::cout
            << current->data.getID()
            << " - "
            << current->data.getStudentName()
            << ", ";
        
        if(index % 5 == 0)
        {
            std::cout << "\n";
        }

        displayEach(current->next, index + 1);

    }



    int size;
    CompuNode* head;
    CompuNode* tail;

};

#endif
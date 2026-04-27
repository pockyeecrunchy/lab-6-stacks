#ifndef STACK_H
#define STACK_H

//------------------------------------------------------------------------------------------------
// File Name: Stack.h
// Written by: Oscar Lan
//------------------------------------------------------------------------------------------------
// Contents:
//
// This file defines the data structures and class used to implement a stack using a linked list.
// Includes the record structure for storing symbols and numerical values, the node structure for 
// linking elements, and the stackType class which provides stack operations such as push, pop, 
// and checking if the stack is empty. The class also maintains a counter to track the number of 
// elements in the stack.
//
//------------------------------------------------------------------------------------------------

// Structure: record
struct record
{
    char symbol;
    double number; //doing this for the extra credit. 
};

// Structure: node
struct node
{
    record data;
    node* pNext;
};

class stackType 

{
private:
    node* pTop;
    //Note: The counter should always reflect the number of nodes currently in the stack.
    int _counter;

    void InitializeStack();
    void ResetCounter();
    void SetTop(node* newTop);

public:
    stackType(); //Constructor
    ~stackType(); //Destructor

    bool StackIsEmpty();
    node* GetTop();

    void IncrementCounter();
    void DecrementCounter();
    int GetCounter();

    void Push(node* pNewNode);
    void Pop();

};

#endif 
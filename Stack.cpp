//------------------------------------------------------------------------------------------------
// File Name: Stack.cpp
// Written by: Oscar Lan
//------------------------------------------------------------------------------------------------
// Contents:
//
// Implements the stackType class using a linked list. Contains all core stack operations
// including constructor, destructor, push, pop, and utility functions for managing the
// stack. The class maintains a top pointer and a counter to track the number of nodes,
// and makes sure that the proper dynamic memory management and LIFO (Last-In-First-Out) behavior
// throughout the program.
//
//------------------------------------------------------------------------------------------------

#include "Stack.h"
#include "Standard.h"

//------------------------------------------------------------------------------------------------
// Method Name: Constructor (stackType)
// Description:
//
// Initializes the stack by calling InitializeStack to set the top pointer to nullptr,
// and ResetCounter to ensure the node counter starts at zero.
//------------------------------------------------------------------------------------------------
stackType::stackType()
{
    InitializeStack();
    ResetCounter();
}

//------------------------------------------------------------------------------------------------
// Method Name: Destructor (~stackType)
// Description:
//
// Deallocates all nodes in the stack by repeatedly popping elements until the stack
// is empty. This prevents memory leaks and ensures proper cleanup.
//------------------------------------------------------------------------------------------------
stackType::~stackType()
{
    //pop the stack while the stack is NOT empty
    while (!StackIsEmpty())
    {
        Pop();
    }
}

//------------------------------------------------------------------------------------------------
// Method Name: InitializeStack
// Description:
//
// Sets the top pointer of the stack to nullptr, effectively initializing the stack
// to an empty state.
//------------------------------------------------------------------------------------------------
void stackType::InitializeStack()
{
    // Set top pointer to NULL
    pTop = nullptr;
}

//------------------------------------------------------------------------------------------------
// Method Name: ResetCounter
// Description:
//
// Resets the internal node counter to 0. This is typically used during initialization to ensure 
// accurate tracking of the number of elements in the stack.
//------------------------------------------------------------------------------------------------
void stackType::ResetCounter()
{
    // Set counter to 0
    _counter = 0;
}

//------------------------------------------------------------------------------------------------
// Method Name: IncrementCounter
// Description:
//
// Increases the node counter by 1 to reflect the addition of a new node to the stack.
//------------------------------------------------------------------------------------------------
void stackType::IncrementCounter()
{
    //Add one to _counter
    _counter++;
}

//------------------------------------------------------------------------------------------------
// Method Name: DecrementCounter
// Description:
//
// Decreases the node counter by 1 to reflect the removal of a node from the stack.
//------------------------------------------------------------------------------------------------
void stackType::DecrementCounter()
{
    //Subtract one from _counter
    _counter--;
}

//------------------------------------------------------------------------------------------------
// Method Name: GetCounter
// Description:
//
// Returns the current number of nodes in the stack.
//------------------------------------------------------------------------------------------------
int stackType::GetCounter()
{
    //returning _counter
    return _counter;
}

//------------------------------------------------------------------------------------------------
// Method Name: SetTop
// Description:
//
// Assigns the top pointer of the stack to the provided node pointer. This method allows
// controlled modification of the stack's top element.
//------------------------------------------------------------------------------------------------
void stackType::SetTop(node* newTop)
{
    //Assign pTop to NewTop
    pTop = newTop;
}

bool stackType::StackIsEmpty()
{
    //it is TRUE if pTop is NULL
    return (pTop == nullptr);
}

//------------------------------------------------------------------------------------------------
// Method Name: GetTop
// Description:
//
// Returns the pointer to the top node of the stack without removing it.
//------------------------------------------------------------------------------------------------
node* stackType::GetTop()
{
    return pTop;
}

//------------------------------------------------------------------------------------------------
// Method Name: Push
// Description:
//
// Adds a new node to the top of the stack. The new node is linked to the current top,
// then becomes the new top. The node counter is incremented. Defensive coding ensures
// the node is not null before insertion.
//------------------------------------------------------------------------------------------------
void stackType::Push(node* pNewNode)
{
    // Defensive coding
    if (pNewNode == nullptr)
        return;

    // Link new node to current top
    pNewNode->pNext = pTop;

    // Move top to new node
    pTop = pNewNode;

    // Update counter
    IncrementCounter();
}

//------------------------------------------------------------------------------------------------
// Method Name: Pop
// Description:
//
// Removes the top node from the stack if it is not empty. The top pointer is updated
// to the next node, the node counter is decremented, and the removed node is deleted
// to prevent memory leaks.
//------------------------------------------------------------------------------------------------
void stackType::Pop()
{
    //if the stack is not empty
    if (!StackIsEmpty())
    {
        //assign a temp variable to the top
        node* temp = pTop;

        //move the top pointer to the next node
        pTop = pTop->pNext;

        //Decrement the node counter
        DecrementCounter();

        //delete the temp node
        delete temp;
    }
}
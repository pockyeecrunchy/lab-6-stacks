#ifndef FUNCTIONS_H
#define FUNCTIONS_H

//------------------------------------------------------------------------------------------------
// File Name: Functions.h
// Written by: Oscar Lan
//------------------------------------------------------------------------------------------------
// Contents:
//
// Declares helper functions used throughout the program. Includes functions for performing 
// mathematical operations, determining operator precedence, and managing file input and output. 
// These functions support the stack-based processing of infix to postfix conversion and expression
//  evaluation.
//
//------------------------------------------------------------------------------------------------

#include "Standard.h"

// Performs math operation (+, -, *, /)
double PerformMath(char operation, double valueA, double valueB);

// Returns operator priority
int ReturnPriority(char symbol);

// Close input and output files
void CloseFiles(ifstream& fin, ofstream& fout);

// Overloaded version for extra credit
void CloseFiles(ifstream& extraCredit, ifstream& fin, ofstream& fout);

#endif 



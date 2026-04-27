//------------------------------------------------------------------------------------------------
// File Name: Functions.cpp
// Written by: Oscar Lan
//------------------------------------------------------------------------------------------------
// Contents:
//
// This file contains helper functions used by the program. Includes functions for performing
// mathematical operations (addition, subtraction, multiplication, division), determining
// operator precedence for infix-to-postfix conversion, and managing file input/output
// through file-closing utilities. These functions support both the postfix conversion
// process and the extra credit evaluation of expressions.
//
//------------------------------------------------------------------------------------------------

#include "Standard.h"
#include "Functions.h"

//------------------------------------------------------------------------------------------------
// Function Name: PerformMath
// Description:
//
// Performs a mathematical operation based on the provided operator character.
// Supports addition, subtraction, multiplication, and division. Returns the
// computed result. If the operator is invalid, a special hexadecimal value is returned to 
// indicate an error.
//------------------------------------------------------------------------------------------------

double PerformMath(char operation, double valueA, double valueB)
{
    //perform the switch statement on the operation character
    switch (operation)
    {

    //addition
    case '+':
        return valueA + valueB;

    //subtraction
    case '-':
        return valueA - valueB;

    //multiplication
    case '*':
        return valueA * valueB;

    //division
    case '/':
        return valueA / valueB;

    default:
        return 0xFFFFFFFFFFFF; // invalid result
    }
}

//------------------------------------------------------------------------------------------------
// Function Name: ReturnPriority
// Description:
//
// Determines the precedence level of an operator symbol. Returns 0 for '(',  1 for addition and 
// subtraction, and 2 for multiplication and division.
//------------------------------------------------------------------------------------------------
int ReturnPriority(char symbol)
{
    if (symbol == '(')
        return 0;

    if (symbol == '+' || symbol == '-')
        return 1;

    if (symbol == '*' || symbol == '/')
        return 2;
}

//------------------------------------------------------------------------------------------------
// Function Name: CloseFiles
// Description:
//
// Closes the input and output file streams passed by reference. Ensures that file resources are 
// properly released after processing.
//------------------------------------------------------------------------------------------------

void CloseFiles(ifstream& fin, ofstream& fout)
{
    fin.close();
    fout.close();
}

//------------------------------------------------------------------------------------------------
// Function Name: CloseFiles (for the extra credit)
// Description:
//
// Closes all file streams used in the extra credit portion, including the extra credit input file, 
// the main input file, and the output file.
//------------------------------------------------------------------------------------------------
void CloseFiles(ifstream& extraCredit, ifstream& fin, ofstream& fout)
{
    extraCredit.close();
    fin.close();
    fout.close();
}


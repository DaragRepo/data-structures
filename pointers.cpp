#include <iostream>
#include <string>

using namespace std;

/*
    Memory in C++: For a C++ program, the memory of a computer is like a succession of memory cells, each one byte in size, and each with a unique address.
                   These single-byte memory cells are ordered in a way that allows data representations larger than one byte to occupy memory cells that have consecutive addresses.
                   This way, each cell can be easily located in the memory by means of its unique address.
                   For example, the memory cell with the address 1776 always follows immediately after the cell with address 1775 and precedes the one with 1777,
                   and is exactly one thousand cells after 776 and exactly one thousand cells before 2776.

    Real world examples :
        o in the university in order to reach a doctor or a TA you need to know their room number right and the room number must be unique.
        o when you call out someone's name in class it must be unique to him/her to avoid other people with the same name answering you. 

    why pointers ? 

     o Pointers allow you to refer to the same space in memory from multiple locations. This means that you can update memory in one location and the change can be seen from another location in your program. You will also save space by being able to share components in your data structures.
     o think of it like you can return many variables from a function.
     o remember that when you need to bypass the scope of the main memory(meaning that you can make a function edit in the main function variables) or another function you'll use pointers. 


    Pointers in C++: Pointer is a variable in C++ that holds the address of another variable. They have data type just like variables.
                     for example an integer type pointer can hold the address of an integer variable and an character type pointer can hold the address of char variable.

    How to access a variable address in the memory ?
        add & operator before the variable name.
        C++ syntax:
            int x;
            cout << &x << endl;

    How to declare a pointer ?
        type * name; (the type of the pointer must be of the same as the type of the variable which we point to because the type describes the kind of data that you will find at that memory address and remember that int behaves differently than double , etc..)
        C++ syntax:
            int x;
            int xPointer = &x;
*/

/*
    Tracing Examples
*/

// int main()
// {
//     int x = 5;
//     int y = 2;

//     // int xPointer = &x; // (error)
//     // int yPointer = &y; // (error)

//     int *xPointer = &x;
//     int *yPointer = &y;

//     // xPointer = *yPointer; // what is the output? justify your answer.
//     // *xPointer = yPointer; // what is the output? justify your answer.
//     // xPointer = &yPointer; // what is the output? justify your answer.
//     // &xPointer = &yPointer; // what is the output? justify your answer.

//     // *xPointer = *yPointer; // what is the output? justify your answer.
//     // xPointer = yPointer; // what is the output? justify your answer.
// }

/* Pointers and Arrays */

// int main()
// {
//     int array[5];
//     array[4] = 40;

//     int *pointer = array; // int *pointer = &array[0];

//     /* Take care we are moving the pointer */
//     // *pointer = 10;
//     // pointer = pointer + 1;
//     // *pointer = 20;

//     /* here we don't move the pointer */
//     *pointer = 10;
//     *(pointer + 1) = 20;

//     for (int i = 0; i < 5; i++)
//     {
//         cout << array[i] << endl;
//     }
// }

/* Passing by value vs passing by reference */

// pass by value
void swapV(int firstNumber, int secondNumber)
{
    int temp = firstNumber;
    firstNumber = secondNumber;
    secondNumber = temp;
}

/*

    Difference in Reference variable and pointer variable
        o A pointer can be re-assigned while reference cannot, and must be assigned at initialization only.
        o Pointer can be assigned NULL directly, whereas reference cannot.
        o A pointer is a variable that holds a memory address. A reference has the same memory address as the item it references.
        o A pointer needs to be dereferenced with * to access the memory location it points to, whereas a reference can be used directly.

*/

// pass by reference 
void swapR(int &firstNumber, int &secondNumber) 
{
    int temp = firstNumber;
    firstNumber = secondNumber;
    secondNumber = temp;
}

// using pointers instead of references
void swapP(int *firstNumber, int *secondNumber)
{
    int temp = *firstNumber;
    *firstNumber = *secondNumber;
    *secondNumber = temp;
}

int main()
{

    int x = 2 ;
    int y = 3;


/*
    // pass by value

    swapV(x, y);

    cout << x << " " << y  << endl;

*/


/*
    // pass by reference 

    swapR(x, y);

    cout << x << " " << y  << endl;
*/

/*
    // with pointers

    swapP(&x, &y);

    cout << x << " " << y  << endl;
*/


}


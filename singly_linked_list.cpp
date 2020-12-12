#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

/* 

-------------------------------------------------------------------------------
|                                      |                                       | 
|            Array                     |             Linked list               | 
|                                      |                                       | 
--------------------------------------------------------------------------------
|  Fixed size                          |   Dynamic size                        | 
|                                      |                                       |     
|------------------------------------------------------------------------------|                                           
|  Insertions and deletions are        |  Insertions and deletions are         |
|  inefficient elements are usually    |  efficient.                           |             
|  shifted.                            |                                       | 
|------------------------------------------------------------------------------|                                       
| Random access i.e., efficient        |  No random access : not suitable for  |         
| indexing                             |  operations requiring accessing       |     
|                                      |  elements by index                    |     
|------------------------------------------------------------------------------|                                                                                  
| No memory waste if the array is full |  since memory is allocated dynamically|              
| or almost full; otherwise may result |   (to our need) there's no waste of   |                                          
| in much memory waste                 |   memory(better utilization of memory)|
|------------------------------------------------------------------------------|                                                                                  
| Sequential access is faster          | Sequential access is slow             | 
| (Reason : Elements in contiguous     | (Reason : Elements not in contiguous  | 
| memory locations)                    |  memory locations)                    |
|                                      |                                       |
|------------------------------------------------------------------------------|
| Array reserves less memory           |  Linked list reserves more memory     |
|                                      |  cause it has the next plus the data  | 
|                                      |                                       | 
|------------------------------------------------------------------------------|



    What's the concept of a linked list ? 
        o a train. 
        o a teasure hunt where each clue leads you to the next stop(in games also).

    Applications of linked list in the real world :
        o Image viewer – Previous and next images are linked, hence can be accessed by next and previous button.
        o Previous and next page in web browser – We can access previous and next url searched in web browser by pressing back and next button since, they are linked as linked list.
        o Music Player – Songs in music player are linked to previous and next song. you can play songs either from starting or ending of the list.

*/

struct Node
{

    int data;
    Node *next;
};

Node *head = NULL;

void insertToFront(int newData)
{
    Node *pNode = new Node;

    pNode->data = newData;

    if (head)
    { // if not null
        cout << "welcome new element " << newData << endl;
        pNode->next = head;
    }
    else
    { // if this is the first element in the list
        cout << "welcome first element " << newData << endl;
        pNode->next = NULL;
    }

    head = pNode;
}

void insertToBack(int newData)
{

    /* if head is NULL */
    if (!head)
    {
        cout << "the list is empty" << endl;
    }
    else
    {
        Node *pNode = new Node;

        pNode->data = newData;

        /* in here i created a temp pointer to point to the same node as the head (because i don't want to lose the head pointer) */
        Node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = pNode;
    }
}

/* 

in this example i wanted to show you that can technically make a function return more than one variable by using pointers 
in here i search for a number and i return the index which i found the number in it.
*/
void isFound(int key, bool *found, int *index)
{

    *found = false;

    int count = 0;

    /* if head is NULL */
    if (!head)
    {
        cout << "the list is empty" << endl;
    }
    else
    {

        Node *temp = head;

        do
        {

            if (temp->data == key)
            {
                *found = true;
                *index = count;
                break;
            }

            temp = temp->next;

            count++;

        } while (temp != NULL);
    }
}

int insertAfterIndex(int index, int dataToInsert)
{

    int count = 0;
    bool foundIndex = false;

    /* if head is NULL */
    if (!head)
    {
        return 0; // 0 means the list is empty
    }
    else
    {

        Node *temp = head;

        do
        {

            if (count == index)
            {
                foundIndex = true;
                break;
            }

            temp = temp->next;

            count++;

        } while (temp != NULL);

        if (foundIndex)
        {
            Node *newNode = new Node;

            newNode->data = dataToInsert;

            newNode->next = temp->next;

            temp->next = newNode;

            return 1;
        }
        else
        {
            return -1; // -1 means that the index you have provided is not in the list
        }
    }
}

int insertAfterData(int data, int dataToInsert)
{

    int count = 0;
    bool foundData = false;

    /* if head is NULL */
    if (!head)
    {
        return 0; // 0 means that list is empty
    }
    else
    {

        Node *temp = head;

        do
        {

            if (temp->data == data)
            {
                foundData = true;
                break;
            }

            temp = temp->next;

            count++;

        } while (temp != NULL);

        if (foundData)
        {
            Node *newNode = new Node;
            newNode->data = dataToInsert;
            newNode->next = temp->next;
            temp->next = newNode;
            return 1; // 1 means that i have successfully inserted the data
        }
        else
        {
            return -1; // -1 means that i  couldn't find the data
        }
    }
}

void printNodes()
{

    /* if head is NULL */
    if (!head)
    {
        cout << "the list is empty" << endl;
    }
    else
    {

        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << endl;
            // this_thread::sleep_for(std::chrono::milliseconds(1000)); // in the case of circular there's no to the list end that's why i delay the printing each time for 1 second
            temp = temp->next;
        }
    }
}

void deleteFirst()
{

    // Node* tempHead = head;

    head = head->next;
    // delete tempHead;
}

void deleteLast()
{

    Node *temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    // Node* tempNext = temp->next;

    temp->next = NULL;

    // delete tempNext;
}

void deleteMiddle(int key)
{

    Node *temp = head;
    bool foundKey = false;

    while (temp->next != NULL)
    {

        if (temp->next->data == key)
        {
            foundKey = true;
            break;
        }

        temp = temp->next;
    }

    if (foundKey)
    {

        // Node* tempNext = temp->next;

        temp->next = temp->next->next;

        // delete tempNext;
    }
    else
    {
        cout << "search key not found" << endl;
    }
}

/*

    When to use circular linked list ? 
        o Circular lists are useful in applications to repeatedly go around the list. For example, when multiple applications are running on a PC, 
        it is common for the operating system to put the running applications on a list and then to cycle through them, giving each of them a slice 
        of time to execute, and then making them wait while the CPU is given to another application. It is convenient for the operating system to use
        circular list so that when it reaches the end of the list it can cycle around to the front of the list.

        o when you press alt + tab isn't the applications in a circular manner ?.

        o repeatedly play a specific music.

*/

void convertToCircular()
{

    Node *temp = head;

    while (temp->next != NULL)
    {

        temp = temp->next;
    }

    temp->next = head;
}

int main()
{

    insertToFront(5);
    insertToFront(6);
    insertToFront(9);
    insertToBack(8);

    // deleteFirst();

    // deleteLast();

    // deleteMiddle(5);
    // printNodes();

    // convertToCircular();

    // printNodes();

    // cout << insertAfterIndex(0, 88) << endl;
    // cout << insertAfterData(5, 80) << endl;
    printNodes();

    // bool x;
    // int index;

    // isFound(8, &x, &index);

    // cout << x << " " << index << endl;
}

#include <iostream>

using namespace std;

/*
    Advantages of doubly linked list ? 
        o A doubly linked list can be traversed in both forward and backward direction.
        o We can quickly insert a new node before a given node.
           In singly linked list, to delete a node, pointer to the previous node is needed. To get this previous node, sometimes the list is traversed. 
           In doubly linked list, we can get the previous node using previous pointer.



    Disadvantages over singly linked list
        o Every node of doubly linked list Require extra space for an previous pointer. It is possible to implement doubly linked list with single pointer though (See this and this).
        o All operations require an extra pointer previous to be maintained. For example, in insertion, we need to modify previous pointers together with 
           next pointers.

*/

struct Node
{

    int data;

    Node *previous;

    Node *next;
};

Node *head = NULL;

Node *tail = NULL;

void insertToFront(int data)
{

    Node *newNode = new Node;

    newNode->data = data;

    if (!head)
    { /* head is empty first element */
        newNode->next = NULL;
        newNode->previous = NULL;
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        newNode->previous = NULL;
        head->previous = newNode;
        head = newNode;
    }
}


void insertToEnd(int data)
{

    Node *newNode = new Node;

    newNode->data = data;

    if (!head)
    { /* head is empty first element */
       cout << "list in empty cannot insert at the back of an empty list";
    }
    else
    {
        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
    }
}

void printForward()
{

    /* if head is NULL */
    if (!head)
    {
        cout << "the list is empty" << endl;
    }
    else
    {

        Node *temp = head;

        while (temp->next != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }

        cout << temp->data << endl;
    }
}


void printBackward () {

    Node* temp = tail;

    while(temp != NULL){

        cout << temp->data << endl;
        temp = temp->previous;
    }


}
 
int main()
{

    insertToFront(5);
    insertToFront(6);
    insertToFront(7);

    // cout << head->next->next->previous->data << endl;


    insertToEnd(10);

    insertToFront(2);

    insertToEnd(12);

    printForward();
    // printBackward();

}

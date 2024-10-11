#include <iostream>

using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

// function prototypes
void output(Node*);
Node* addHead(Node* head, float value);
Node* addTail(Node* head, float value);
Node* insertNode(Node* head, int position, float value);
Node* deleteNode(Node* head, int position);
void deleteList(Node* &head);

int main() 
{
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) 
    {
        int tmp_val = rand() % 100;
        head = addHead(head, temp_val);
    } 
    output(head);

    // deleting a node
    int entry;
    cout << "Which node to delete? " << endl;
    output(head);
    cout << "Choice --> ";
    cin >> entry;
    head = deleteNode(head, entry);
    output(head);

    // add tail
    head = addTail(head, 100);
    output(head);

    // insert a node
    current = head;
    cout << "After which node to insert 10000? " << endl;
    count = 1;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    current = head;
    prev = head;
    for (int i = 0; i < (entry); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    output(head);

    // deleting the linked list
    deleteList(head)
    output(head);

    return 0;
}

void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

Node* addHead(Node* head, float value)
{
    // adds node at head
    Node *newVal = new Node;
    newVal->value = value;
    // assigns the passed in value as the new head
    newVal->next = head;
    // returns the new head
    return newValue;
}

Node* addTail(Node* head, float value)
{
    Node *newVal = new Node;
    newVal->value = value;
    newVal->next = nullptr;

    if (!head) 
    {
        return newVal;
    }
    
    Node *current = head;

    //while the next node is valid not nullptr
    while(current->next)
    {
        current = current->next;
    }
    // once u get current to the last node assign next value as newVal
    current->next = newVal;

    return head;
}

Node* insertNode(Node* head, int position, float value)
{
    Node* newNode = new Node;
    newNode->value = value;

    // invalid position 0
    if(position <= 0)
    {
        return head;
    }
    // head position
    else if(position == 1)
    {
        newNode->next = head;
        return newNode;
    }
  
    Node *current = head;
    Node *prev = nullptr;

    for (int i = 0; current && i < position - 1; i++)
    {
       prev = current;
       current = current->next;
    }

    //insert the newNode
    newNode->next = current;
    prev->next = newNode;

    return head;
}

Node* deleteNode(Node* head, int position)
{
    Node *current = head;

    if (position == 1)
    {
       
        head = current->next;
       
        delete current;
       
        return head;
    }

    Node *prev = head;

    for (int i = 0; i < position - 1; i++)
    {
        if(i == 0)
        {
            current = current->next;
        }
        // else if we are past the 0th position
        else
        {
            current = current->next;
            prev = prev->next;
        }
    }
    // if current is valid not nullptr
    if(current)
    {
        delete current;
        prev->next = current->next;
    }

    return head;
}

void deleteList(Node* &head)
{
    Node* current = head;
    while (current) 
    {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
}
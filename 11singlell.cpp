#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    //destructor
    ~Node() {
        int value = this -> data;
        //memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL; 
        }
        cout << " memory is free for node with data " << value << endl;
    }
};
void insertAthead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}
void insertAttail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

// insert at position
void insertAtposition(Node *&head, Node *&tail, int position, int d)
{

    if (position == 1)
    {
        insertAthead(head, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp->next == NULL)
    {
        insertAttail(tail, d);
        return;
    }
    Node *nodeToinsert = new Node(d);
    nodeToinsert->next = temp->next;
    temp->next = nodeToinsert;
}

void print(Node *&head)
{

    if (head == NULL)
    {
        cout << "list is Empty!" << endl;
    }
    Node *temp = head;

    while (temp != NULL)
    {

        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteNode(Node *&head,Node *&tail, int position)
{ 
    //delete at start
    Node *temp = head;
    if (position == 1)
    {

        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    //delete at middle
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;

         if (prev->next == NULL)
        {
            tail = prev;
        }
    }

}

int main()
{
    Node *node1 = new Node(10);

    // cout << node1->data << endl;
    // cout << node1->next << endl;

    Node *head = node1;
    Node *tail = node1;
    print(head);

    insertAttail(tail, 11);
    print(head);

    insertAttail(tail, 12);
    print(head);

    insertAttail(tail, 13);
    print(head);

    // insertAtposition(head, tail, 4, 77);
    // print(head);
    // cout << "head " << head->data << endl;
    // cout << "tail " << tail->data << endl;

    cout << "deleting Node " << endl;

    deleteNode(head,tail, 4);
    print(head);

     cout << "head " << head->data << endl;
     cout << "tail " << tail->data << endl;

    return 0;
}
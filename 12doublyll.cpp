#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    // constructor
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
    //destructor

    ~Node(){
        int value=this->data;
        if(next!=NULL){
            delete next;
            next=NULL;
        }
        cout << "memory  free for node with data " << value << endl;
    }
};

void insertAthead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAttail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertAtposition(Node *&head, Node *&tail, int position, int d)
{
        // node insertion at first or start
    if (position == 1)
    {

        insertAthead(head, d);
        return;
    }
    //node insertion at any position at middle
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
    temp->next->prev = nodeToinsert;
    temp->next = nodeToinsert;
    nodeToinsert->prev = temp;
}

void deleteposition(Node *&head, Node *&tail, int position)
{

    // deleting first or start node
    if (position == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    // deleting any  middle node
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
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
        if (prev->next == NULL)
        {
            tail = prev;
        }
    }
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
// gives lenght of DLL
int getLenght(Node *head)
{
    Node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

int main()
{

    Node *node1 = new Node(20);
    Node *head = node1;
    Node *tail = node1;
    print(head);
    cout << "lenght of DDL : " << getLenght(head) << endl;

    insertAthead(head, 69);
    print(head);

    insertAthead(head, 19);
    print(head);

    insertAthead(head, 74);
    print(head);

    insertAttail(tail, 45);
    print(head);

    insertAttail(tail, 46);
    print(head);

    insertAttail(tail, 47);
    print(head);

    insertAttail(tail, 48);
    print(head);

    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;

    insertAtposition(head, tail, 2, 100);
    print(head);
    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;

    insertAtposition(head, tail, 1, 101);
    print(head);

    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;

    insertAtposition(head, tail, 7, 10254);
    print(head);
    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;

    deleteposition(head,tail,2);
    print(head);
    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;

     deleteposition(head,tail,1);
    print(head);
    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;

     deleteposition(head,tail,9);
    print(head);
    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;

    return 0;
}
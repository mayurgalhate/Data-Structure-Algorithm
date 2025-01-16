#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    // constructor
    node(int d)
    {

        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{
    cout << "enter data: " << endl;
    int data;
    cin >> data;
    root = new node(data);

    // recursion
    if (data == -1)
    {
        return NULL;
    }
    cout << "enter data for left : " << endl;
    root->left = buildTree(root->left);
    cout << "enter data for right: " << endl;
    root->right = buildTree(root->right);

    return root;
}

node *levelOrderTraversal(node *root)
{

    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;

            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void buildFromlevelorder(node* &root)
{
    queue<node *> q;
    cout << "enter data: " << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << "enter data for left: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if (leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout << "enter data for right: " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}
int main()
{

    node *root = NULL;

    
    buildFromlevelorder(root);
    levelOrderTraversal(root);

    /*
     root = buildTree(root);
     // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
     // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
     cout << "Printing level Order Traversal: " << endl;
     levelOrderTraversal(root);
     cout << "Inorder: " ;
     inorder(root);
     cout<<endl;
     cout << "preOrder: " ;
     preOrder(root);
     cout<<endl;
     cout << "postOrder: ";
     postOrder(root);
     cout<<endl;

 */
    return 0;
}
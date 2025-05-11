#include<iostream>
#include<queue>
using namespace std;
class Node{

    public:
        int data;
        Node* left;
        Node* right;

        Node(int d){
            this->data = d;
            this->left = NULL;
            this->right = NULL;
        }

};
pair<bool,int> isBalanced(Node* root){
if(root == NULL){

pair<bool,int>p = make_pair(true,0);
return p;

}
pair<int,int> left = isBalanced(root->left);
pair<int,int> right = isBalanced(root->right);

bool leftAns = left.first;
bool rightAns = right.first;

bool diff = abs(left.second - right.second) <=1;

pair<bool,int> ans ;
ans.second = max(left.second,right.second) + 1;

if(leftAns && rightAns && diff){
    ans.first = true;
}
else{
    ans.first = false;
}
return ans;
}
Node *levelOrderTraversal(Node *root)
{

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
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

Node* insertInBST(Node* root , int d){
    //base case 
    if(root == NULL){
        root = new Node(d);
        return root;
    }
    // for right
    if(d > root->data){
        root->right = insertInBST(root->right , d);
    }
    // for left
    if(d < root->data){
        root->left = insertInBST(root->left , d);
    }
    return root;
}

Node* minVal(Node* root){
    Node* temp = root;
    while(temp->left != NULL){

        temp = temp->left;

    }
    return temp;
}

Node* maxVal(Node* root){
    Node* temp = root;
    while(temp->right != NULL){
        
        temp = temp->right;

    }
    return temp;
}

Node* deletefromBST(Node* root , int val){
    if(root == NULL){
        return root;
    }
    
    if(root->data == val){
        //0
    if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
    }
    //1
    //left
    if(root->left != NULL && root->right == NULL){
        Node* temp = root->left;
        delete root;
        return temp;
    }
    //right
    if(root->left == NULL && root->right != NULL){
        Node* temp = root->right;
        delete root;
        return temp;
    }
    //2
    if(root->left != NULL && root->right != NULL){
        //find min val from right 'or' max value from left
        int mini = minVal(root->right)->data;
        //copy data in root data
        root->data = mini;
        //delete mini
        root->right = deletefromBST(root->right , mini);
        return root;
     }
    }
    else if(root->data > val){
        root->left = deletefromBST(root->left , val);
        return root;
    }
    else{
        root->right = deletefromBST(root->right , val);
        return root;
    }
}

void takeInput(Node* &root ){
    int data;
    cin>>data;
    while(data != -1){
        root = insertInBST(root , data);
        cin>>data;
    }
}



int main(){
    Node* root = NULL;
    
    cout << "Enter data to create BST:" << endl;
    takeInput(root);
    
    cout << "Printing BST" << endl;
    levelOrderTraversal(root);

    cout << "Min val data: " << minVal(root)->data <<endl;
    cout << "Max val data: " << maxVal(root)->data <<endl;

    root = deletefromBST(root , 110);
     cout << "Printing BST" << endl;
     levelOrderTraversal(root);
      cout << "Min val data: " << minVal(root)->data <<endl;
    cout << "Max val data: " << maxVal(root)->data <<endl;
    
     

    return 0;
}
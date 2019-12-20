#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};
void printLevelOrder(node * root)
{
    if(root!=NULL)
    {
        queue<node*> Q;
        node* temp;
        Q.push(root);
        while(!Q.empty())
        {
            temp = Q.front();
            Q.pop();
            cout<< temp->data <<" ";
            if(temp->left)
                Q.push(temp->left);
            if(temp->right)
                Q.push(temp->right);
        }
    }
}
node* newNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    printLevelOrder(root);
    return 0;
}

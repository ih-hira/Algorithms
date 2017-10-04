#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <stack>
using namespace std;

#define MAX INT_MAX
#define MIN INT_MIN

int mAX = MIN, mIN = MAX;
struct node
{
    int data;
    node *left;
    node *right;
};
#define P pair<node*,int>
node* FindMin(node *root)
{
    node* current = root;

    while (current->left != NULL)
        current = current->left;

    return current;
}
node* Delete(node *root, int z)
{
    if (root == NULL)
    {
        return root;
    }
    if (z < root->data)    // data is in the left sub tree.
    {
        root->left = Delete(root->left, z);
    }
    else if (z > root->data)     // data is in the right sub tree.
    {
        root->right = Delete(root->right, z);
    }
    else
    {
        // case 1: no children
        if (root->left == NULL && root->right == NULL)
        {
            free(root); // wipe out the memory, in C, use free function
            root = NULL;
        }
        // case 2: one child (right)
        else if (root->left == NULL)
        {
            node *temp = root->right; // save current node as a backup
            free(root);
            return temp;
        }
        // case 3: one child (left)
        else if (root->right == NULL)
        {
            node *temp = root->left; // save current node as a backup
            free(root);
            return temp;
        }
        // case 4: two children
        else
        {
            node *temp = FindMin(root->right); // find minimal value of right sub tree
            root->data = temp->data; // duplicate the node
            root->right = Delete(root->right, temp->data); // delete the duplicate node
        }
    }
    return root; // parent node can update reference
}
void inorderPredecessor(node *root,int z)
{
    int t = MIN;
    stack<P> ss;
    ss.push(P(root,1));
    while(!ss.empty())
    {
        node *p = ss.top().first;
        int i = ss.top().second;
        ss.pop();
        if(p!=NULL)
        {
            if(i==1)
            {
                ss.push(P(p,2));
                ss.push(P(p->left,1));
            }
            else
            {
                if(p->data==z)
                {
                    if(t==MIN)
                    {
                        cout<<"There is no Predecessor"<<endl;
                    }
                    else
                    {
                        cout<<t<<endl;
                    }
                    return;
                }
                else
                {
                    t = p->data;
                }
                ss.push(P(p->right,1));
            }
        }
    }
}
void inorderSuccessor(node *root,int z)
{
    stack<P> ss;
    ss.push(P(root,1));
    while(!ss.empty())
    {
        node *p = ss.top().first;
        int i = ss.top().second;
        ss.pop();
        if(p!=NULL)
        {
            if(i==1)
            {
                ss.push(P(p,2));
                ss.push(P(p->left,1));
            }
            else
            {
                if(p->data>z)
                {
                    cout<<p->data<<endl;
                    return;
                }
                ss.push(P(p->right,1));
            }
        }
    }
    cout<<"There is no Successor"<<endl;
}
void printValues(node *root)
{
    queue <node*> qq;
    qq.push(root);
    while(!qq.empty())
    {
        node *p = qq.front();
        qq.pop();
        if(p!=NULL)
        {
            cout<<p->data<<" ";
            qq.push(p->left);
            qq.push(p->right);
        }
    }
}
void printValuesInOrder(node *root)
{
    stack<P> ss;
    ss.push(P(root,1));
    while(!ss.empty())
    {
        node *p = ss.top().first;
        int i = ss.top().second;
        ss.pop();
        if(p!=NULL)
        {
            if(i==1)
            {
                ss.push(P(p,2));
                ss.push(P(p->left,1));
            }
            else
            {
                cout<<p->data<<" ";
                mAX = p->data > mAX ? p->data : mAX;
                mIN = p->data < mIN ? p->data : mIN;
                ss.push(P(p->right,1));
            }
        }
    }
}
void findParent(node *t,int z)
{
    node *p =t;
    node *temp;
    bool found = false;
    if(p->data==z)
    {
        cout<<"This is Root"<<endl;
        return;
    }
    else
    {
        while(p!=NULL && found==false)
        {
            if(z < p->data)
            {
                temp = p;
                p = p->left;
            }

            else if( z > p->data)
            {
                temp = p;
                p = p->right;
            }

            else found = true;
        }
        if(found) cout<<"Parent of "<<z<<" is "<<temp->data<<endl;
        else cout<<"This value not in tree"<<endl;
    }
}
void searchValue(node *t,int z)
{
    node *p =t;
    bool found = false;
    while(p!=NULL && found==false)
    {
        if(z < p->data) p = p->left;

        else if( z > p->data) p = p->right;

        else found = true;
    }
    if(found) cout<<"Found "<<z<<endl;
    else cout<<"This value not in tree"<<endl;
}
void insertData(node *root, int val)
{
    if(root->data==(int)NULL)
    {
        root->data=val;
    }
    else
    {
        node *newnode = (node*)malloc(sizeof(node));
        newnode->data=val;
        newnode->left=NULL;
        newnode->right=NULL;
        if(val<root->data && root->left!=NULL)
        {
            root=root->left;
            while(1)
            {
                if(root->data > val)
                {
                    if(root->left==NULL) break;

                    else root=root->left;
                }
                else
                {
                    if(root->right==NULL) break;

                    else root=root->right;
                }
            }
        }
        else if(val>root->data && root->right!=NULL)
        {
            root=root->right;
            while(1)
            {
                if(root->data > val)
                {
                    if(root->left==NULL) break;

                    else root=root->left;
                }
                else
                {
                    if(root->right==NULL) break;

                    else root=root->right;
                }
            }
        }
        if(root->data>val)
        {
            root->left=newnode;
        }
        else
        {
            root->right=newnode;
        }
    }
}
int main()
{
    node *root = (node*)malloc(sizeof(node));
    root->left=NULL;
    root->right=NULL;
    root->data=(int)NULL;
    int node,val,z;
    //freopen("input.txt","r",stdin);
    cin>>node;
    for(int i=0; i<node; i++)
    {
        cin>>val;
        insertData(root,val);
    }
    cin>>z;
    cout<<"Binary Search Tree: ";
    printValues(root);
    cout<<endl;
    cout<<endl;
    cout<<"Values In-order: ";
    printValuesInOrder(root);
    cout<<endl;
    cout<<endl;
    searchValue(root,z);
    findParent(root,z);
    cout<<endl;
    cout<<"Min Value: "<<mIN<<endl;
    cout<<"Max Value: "<<mAX<<endl;
    cout<<endl;
    cout<<"In-order Successor: ";
    inorderSuccessor(root,z);
    cout<<"In-order Predecessor: ";
    inorderPredecessor(root,z);

    root = Delete(root,z);
    cout<<endl;
    cout<<"After Delete "<<z<<" : ";
    printValuesInOrder(root);
    return 0;
}


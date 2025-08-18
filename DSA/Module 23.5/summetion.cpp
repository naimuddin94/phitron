#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insert_tree()
{
    int val;
    cin >> val;
    Node *root = new Node(val);

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();

        Node *leftNode = NULL, *rightNode = NULL;

        int l, r;
        cin >> l >> r;

        if (l != -1)
        {
            leftNode = new Node(l);
            q.push(leftNode);
        }

        if (r != -1)
        {
            rightNode = new Node(r);
            q.push(rightNode);
        }

        p->left = leftNode;
        p->right = rightNode;
    }

    return root;
}


void print_cousin(Node* root){
    if(!root) return;

    if()
}

int main()
{

    Node *root = insert_tree();

    print_cousin(root);

    return 0;
}
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

Node *input_tree()
{
    int f;
    cin >> f;
    if (f == -1)
        return NULL;

    Node *root = new Node(f);
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;
        Node *left = NULL, *right = NULL;

        if (l != -1)
        {
            left = new Node(l);
        }

        if (r != -1)
        {
            right = new Node(r);
        }

        p->left = left;
        p->right = right;

        if (p->left)
            q.push(p->left);

        if (p->right)
            q.push(p->right);
    }

    return root;
}

void print_left(Node *n)
{
    if (n == NULL)
        return;

    if (n->left)
    {
        print_left(n->left);
    }
    else if (n->right)
    {
        print_left(n->right);
    }

    cout << n->val << " ";
}

void print_right(Node *n)
{
    if (n == NULL)
        return;

    cout << n->val << " ";
    

    if (n->right)
    {
        print_right(n->right);
    }
    else if (n->left)
    {
        print_right(n->left);
    }
}

int main()
{
    Node *root = input_tree();

    print_left(root->left);
    cout << root->val << " ";
    print_right(root->right);

    return 0;
}
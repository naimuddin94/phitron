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
    int val;
    cin >> val;

    if (val == -1)
        return NULL;
    Node *root = new Node(val);

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;
        Node *leftNode = NULL, *rightNode = NULL;

        if (l != -1)
            leftNode = new Node(l);

        if (r != -1)
            rightNode = new Node(r);

        f->left = leftNode;
        f->right = rightNode;

        if (f->left)
            q.push(f->left);

        if (f->right)
            q.push(f->right);
    }

    return root;
}

int main()
{
    Node *root = input_tree();

    queue<Node *> q;

    if (root)
        q.push(root);

    bool is_perfect = true;

    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();

        if ((p->left && !p->right) || (!p->left && p->right))
        {
            is_perfect = false;
            break;
        }

        if (p->left)
        {
            q.push(p->left);
        }

        if (p->right)
        {
            q.push(p->right);
        }
    }

    if (is_perfect)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
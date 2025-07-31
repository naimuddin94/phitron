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
    {
        return NULL;
    }

    Node *root = new Node(f);

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        Node *leftNode = NULL, *rightNode = NULL;

        if (l != -1)
        {
            leftNode = new Node(l);
        }

        if (r != -1)
        {
            rightNode = new Node(r);
        }

        p->left = leftNode;
        p->right = rightNode;

        if (p->left)
        {
            q.push(p->left);
        }
        if (p->right)
        {
            q.push(p->right);
        }
    }

    return root;
}

int sum_without_leaf(Node *root)
{
    if(!root) return 0;

    queue<Node *> q;
    q.push(root);
    int sum = 0;

    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();
        
        if(f->left || f->right){
            sum+=f->val;
        }


        if (f->left)
        {
            q.push(f->left);
        }
        if (f->right)
        {
            q.push(f->right);
        }
    }

    return sum;
}

int main()
{
    Node *root = input_tree();

    int ans = sum_without_leaf(root);

    cout << ans << endl;

    return 0;
}
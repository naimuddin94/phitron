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
            q.push(p->left);

        if (p->right)
            q.push(p->right);
    }

    return root;
}


int main()
{
    Node *root = input_tree();

    queue<Node*> q;
    vector<int> ans;

    if(root) q.push(root);

    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();

        if(!f->left && !f->right) ans.push_back(f->val);

        if(f->left) q.push(f->left);

        if(f->right) q.push(f->right);
    }

    sort(ans.begin(), ans.end(), greater<int>());

    for (int it : ans)
    {
       cout << it << " ";
    }
     

    return 0;
}
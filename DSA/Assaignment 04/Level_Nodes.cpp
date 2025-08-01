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

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int l = height(root->left);
    int r = height(root->right);
    return max(l, r) + 1;
}

void print_target_nodes(Node *root, int tar)
{
    queue<pair<Node *, int>> my_queue;

    if (root)
    {
        my_queue.push({root, 0});
    }

    while (!my_queue.empty())
    {
        pair<Node *, int> f = my_queue.front();
        my_queue.pop();

        Node *p = f.first;
        int level = f.second;

        if (level == tar)
        {
            cout << p->val << " ";
        }

        if(tar < level){
            break;
        }

        if (p->left)
        {
            my_queue.push({p->left, level + 1});
        }

        if (p->right)
        {
            my_queue.push({p->right, level + 1});
        }
    }
}

int main()
{
    Node *root = input_tree();

    int target;
    cin >> target;

    int level = height(root);

    if (target >= level)
    {
        cout << "Invalid" << endl;
        return 0;
    }

    print_target_nodes(root, target);

    return 0;
}
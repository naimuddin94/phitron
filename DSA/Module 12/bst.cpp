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
        Node *p = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;
        Node *leftNode = NULL, *rightNode = NULL;

        if (l != -1)
            leftNode = new Node(l);

        if (r != -1)
            rightNode = new Node(r);

        p->left = leftNode;

        p->right = rightNode;

        if (p->left)
            q.push(p->left);

        if (p->right)
            q.push(p->right);
    }

    return root;
}

bool search(Node *root, int x){
    if(root == NULL) return false;

    if(root->val == x) return true;

    if(root->val > x){
         return search(root->left, x);
    }else{
        return search(root->right, x);
    }
}

int main()
{
    Node *root = input_tree();
    int tar;
    cin >> tar;

    if(search(root, tar)){
        cout << "Found" << endl;
    }else{
        cout << "Not Found" << endl;
    }

    return 0;
}
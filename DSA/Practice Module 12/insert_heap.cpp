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

Node *convertToBST(vector<int> v, int l, int r)
{
    if (v.empty())
    {
        return NULL;
    }

    if (l > r)
    {
        return NULL;
    }

    int mid = (l + r) / 2;
    Node *root = new Node(v[mid]);
    Node *leftNode = convertToBST(v, l, mid - 1);
    Node *rightNode = convertToBST(v, mid + 1, r);
    root->left = leftNode;
    root->right = rightNode;
    return root;
}

int main()
{
    int n;
    cin >> n;

    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    Node *root = convertToBST(v, 0, n-1);

    return 0;
}
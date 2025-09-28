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
    Node *root;
    if (val == -1)
        root = NULL;
    else
    {
        root = new Node(val);
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();
        int l, r;
        cin >> l >> r;
        Node *left, *right;
        if (l == -1)
            left = NULL;
        else
            left = new Node(l);
        if (r == -1)
            right = NULL;
        else
            right = new Node(r);

        f->left = left;
        f->right = right;

        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
    return root;
}
void level_order(Node *root)
{
    queue<Node *> q;
    if (root)
        q.push(root);
    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();

        cout << f->val << " ";

        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
}
void outer_tree(Node *root)
{
    if (!root)
        return;

    outer_tree(root->left);
    outer_tree(root->right);
}

void printLeft(Node *root)
{
    if (!root)
        return;
    // if (!root->left && !root->right)
    //     return;
    printLeft(root->left);
    cout << root->val << " ";
}
void printRight(Node *root, int l = 0)
{
    if (!root)
        return;
    // if (!root->left && !root->right)
    //     return;
    // if (l != 0)
    cout << root->val << " ";
    printRight(root->right, l + 1);
}

int main()
{

    Node *root = input_tree();
    int val;
    cin >> val;
    // level_order(root);
    printLeft(root);
    printRight(root);

    return 0;
}

// 10 20 30 40 70 -1 50 90 110 -1 -1 80 60 -1 -1 -1 -1 100 -1 -1 -1 -1 -1
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

void printLeft(Node *root, vector<int> &l)
{
    if (!root)
        return;
    if (root->left)
    {
        printLeft(root->left, l);
        l.push_back(root->val);
    }
    else if (root->right)
    {
        printLeft(root->right, l);
        l.push_back(root->val);
    }
    else
    {
        l.push_back(root->val);
    }
}
void printRight(Node *root, vector<int> &r)
{
    if (!root)
        return;
    if (root->right)
    {
        r.push_back(root->val);
        printRight(root->right, r);
    }
    else if (root->left)
    {
        r.push_back(root->val);
        printRight(root->left, r);
    }
    else
    {
        r.push_back(root->val);
    }
}

int main()
{

    Node *root = input_tree();
    // int val;
    // cin >> val;
    // level_order(root);
    vector<int> l, r;
    printLeft(root->left, l);
    printRight(root->right, r);

    for (int i : l)
    {
        cout << i << " ";
    }
    cout << root->val << " ";
    for (int i : r)
    {
        cout << i << " ";
    }

    return 0;
}

// 10 20 30 40 70 -1 50 90 110 -1 -1 80 60 -1 -1 -1 -1 100 -1 -1 -1 -1 -1
// 10 -1 20 -1 50 80 -1 -1 -1
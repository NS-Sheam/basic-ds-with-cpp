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

    queue<Node *> q;
    Node *root;

    if (val == -1)
        root = NULL;
    else
        root = new Node(val);
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

void getLeaves(Node *root, vector<int> &leaves)
{
    if (!root)
        return;
    if (!root->left && !root->right)
    {
        leaves.push_back(root->val);
    }
    getLeaves(root->left, leaves);
    getLeaves(root->left, leaves);
}
bool leafSimilar(Node *root1, Node *root2)
{

    vector<int> leaf1, leaf2;
    getLeaves(root1, leaf1);
    getLeaves(root2, leaf2);

    return leaf1 == leaf2;
}
int main()
{
    Node *root1 = input_tree();
    Node *root2 = input_tree();
    bool isSim = leafSimilar(root1, root2);
    cout << isSim << endl;
    return 0;
}
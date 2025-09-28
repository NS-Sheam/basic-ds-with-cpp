
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T val;
    bool isOriginal;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

TreeNode<int> *input_tree()
{
    int val;
    cin >> val;

    queue<TreeNode<int> *> q;
    TreeNode<int> *root;
    if (val == -1)
        root = NULL;
    else
        root = new TreeNode<int>(val);
    q.push(root);

    while (!q.empty())
    {
        TreeNode<int> *f = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;
        TreeNode<int> *left, *right;

        if (l == -1)
            left = NULL;
        else
            left = new TreeNode<int>(l);
        if (r == -1)
            right = NULL;
        else
            right = new TreeNode<int>(r);

        f->left = left;
        f->right = right;

        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
    return root;
};
void print_level_order(TreeNode<int> *root)
{
    if (!root)
        return;
    queue<TreeNode<int> *> q;

    q.push(root);

    while (!q.empty())
    {
        TreeNode<int> *f = q.front();
        q.pop();

        cout << f->val << " ";

        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
};

vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    vector<int> ans;
    bool fre[3005] = {false};
    queue<pair<TreeNode<int> *, int>> q;
    if (root)
        q.push({root, 1});

    while (!q.empty())
    {
        pair<TreeNode<int> *, int> parent = q.front();

        q.pop();

        TreeNode<int> *node = parent.first;
        int level = parent.second;

        if (!fre[level])
        {
            ans.push_back(node->val);
            fre[level] = true;
        }

        if (node->left)
            q.push({node->left, level + 1});

        if (node->right)
            q.push({node->right, level + 1});
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    while (n--)
    {

        TreeNode<int> *root = input_tree();
        vector<int> v = getLeftView(root);
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }

        // print_level_order(root);
        cout << endl;
    }
    return 0;
}

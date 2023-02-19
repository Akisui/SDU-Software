#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct binaryTreeNode
{
    char element;
    binaryTreeNode *left, *right;
    binaryTreeNode(char val)
    {
        this->element = val;
        this->left = this->right = NULL;
    }
};

binaryTreeNode* levelBuild(const string &level, int idx)
{
    binaryTreeNode* p = new binaryTreeNode(level[idx]);
    if (2 * idx < level.size())
        p->left = levelBuild(level, 2 * idx);
    if (2 * idx + 1 < level.size())
        p->right = levelBuild(level, 2 * idx + 1);
    return p;
}

binaryTreeNode* preinBuild(const string &pre, const string &in, int pl, int pr, int il, int ir)
{
    binaryTreeNode* p = new binaryTreeNode(pre[pl]);
    int tmp = -1;
    for (int i = il; i <= ir; ++i)
    {
        if (in[i] == pre[pl])
        {
            tmp = i;
            break;
        }
    }
    if (tmp > il)
        p->left = preinBuild(pre, in, pl + 1, pl + tmp - il, il, tmp - 1);
    if (tmp < ir)
        p->right = preinBuild(pre, in, pl + tmp - il + 1, pr, tmp + 1, ir);
    return p;
}

vector<char> ans;

void preOrder(binaryTreeNode* root)
{
    if (root != NULL)
    {
        ans.push_back(root->element);
        preOrder(root->left);
        preOrder(root->right);
        return;
    }
}

void inOrder(binaryTreeNode* root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        ans.push_back(root->element);
        inOrder(root->right);
    }
    return;
}

void postOrder(binaryTreeNode* root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        ans.push_back(root->element);
    }
    return;
}

void levelOrder(binaryTreeNode* root)
{
    queue<binaryTreeNode*> q;
    q.push(root);
    while (q.size())
    {
        binaryTreeNode* tmp = q.front();
        q.pop();
        ans.push_back(tmp->element);
        if (tmp->left != NULL) q.push(tmp->left);
        if (tmp->right != NULL) q.push(tmp->right);
    }
    return;
}

int height(binaryTreeNode* root)
{
    if (root->left == NULL && root->right == NULL) return 1;
    int tmp = max(height(root->left), height(root->right));
    tmp++;
    return tmp;
}

void print()
{
    for (int i = 0; i < ans.size(); ++i)
    {
        if (i == 0)
        {
            cout << ans[i];
            continue;
        }
        cout << "," << ans[i];
    }
    cout << endl;
    return;
}

void solve()
{
    cout << "Input1" << endl; // ABCDEFGHIJKLMNO
    string level;
    cin >> level;
    level = "0" + level;
    binaryTreeNode* tree1 = levelBuild(level, 1);

    cout << "Output1" << endl;
    ans.clear();
    preOrder(tree1);
    print();
    ans.clear();
    inOrder(tree1);
    print();
    ans.clear();
    postOrder(tree1);
    print();
    cout << ans.size() << endl;
    cout << height(tree1) << endl;
    
    cout << "Input2" << endl;
    string pre;
    string in;
    cin >> pre >> in;
    pre = "0" + pre;
    in = "0" + in;
    binaryTreeNode* tree2 = preinBuild(pre, in, 1, pre.size() - 1, 1, in.size() - 1);
    
    cout << "Output2" << endl; // ABDEC DBEAC
    ans.clear();
    postOrder(tree2);
    print();
    ans.clear();
    levelOrder(tree2);
    print();
    
    cout << "End0" << endl;
    return;
    
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

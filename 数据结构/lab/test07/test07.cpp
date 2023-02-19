#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

struct binaryTreeNode
{
    int element;
    binaryTreeNode *left, *right;
    binaryTreeNode(int val)
    {
        this->element = val;
        this->left = this->right = NULL;
    }
};

bool check(vector<int> level, int idx)
{
    int size = level.size() - 1;
    if (idx * 2 > size && idx * 2 + 1 > size)
        return true;
    else if (idx * 2 + 1 > size)
        return (level[idx] >= level[idx * 2]);
    return (level[idx] >= level[2 * idx] && level[idx] >= level[2 * idx + 1]);
}

vector<int> normalize(vector<int> level, int idx)
{
    int size = level.size() - 1;
    if (idx * 2 + 1 > size)
    {
        int tmp = level[idx];
        level[idx] = level[idx * 2];
        level[idx * 2] = tmp;
        return level;
    }
    int tmp = level[idx];
    if (level[idx * 2] > level[idx * 2 + 1])
    {        
        level[idx] = level[idx * 2];
        level[idx * 2] = tmp;
    }
    else
    {
        level[idx] = level[idx * 2 + 1];
        level[idx * 2 + 1] = tmp;
    }
    return level;
}

vector<int> initMaxSub(vector<int> level, int idx)
{
    int size = level.size() - 1;
    if (check(level, idx)) return level;
    level = normalize(level, idx);
    if (idx * 2 + 1 > size)
    {
        level = initMaxSub(level, idx * 2);
        return level;
    }
    level = initMaxSub(level, idx * 2);    
    level = initMaxSub(level, idx * 2 + 1);
    return level;
}

vector<int> initMax(vector<int> level)
{
    int size = level.size() - 1;
    for (int idx = size; idx >= 1; --idx)
        if (!check(level, idx))
            level = initMaxSub(level, idx);              
    return level;
}

binaryTreeNode* insertLocation(int value, binaryTreeNode* root)
{
    binaryTreeNode* pp = root;
    binaryTreeNode* p;
    if (value < pp->element) p = pp->left;
    else p = pp->right;
    while (p != NULL)
    {
        pp = p;
        if (value < pp->element) p = pp->left;
        else p = pp->right;
    }
    return pp;    
}

binaryTreeNode*  biSearchBuild(const vector<int> &tree)
{
    int size = tree.size() - 1;
    binaryTreeNode* root;
    for (int i = 1; i <= size; ++i)
    {
        if (i == 1)
        {
            root = new binaryTreeNode(tree[i]);
            continue;
        }
        binaryTreeNode* p = new binaryTreeNode(tree[i]);
        binaryTreeNode* pp = insertLocation(p->element, root);
        if (p->element < pp->element)
            pp->left = p;
        else pp->right = p;
    }
    return root; 
}

binaryTreeNode* levelBuild(const vector<int> &level, int idx)
{
    binaryTreeNode* p = new binaryTreeNode(level[idx]);
    if (2 * idx < level.size())
        p->left = levelBuild(level, 2 * idx);
    if (2 * idx + 1 < level.size())
        p->right = levelBuild(level, 2 * idx + 1);
    return p;
}

vector<int> ans;

void heapSort(vector<int> level)
{
    vector<int> ansBuffer;
    int size = level.size() - 1;
    for (int i = size; i >= 1; --i)
    {
        int tmp = level[i];
        level.pop_back();
        ansBuffer.push_back(level[1]);
        level[1] = tmp;
        level = initMax(level);
    }
    for (int i = ansBuffer.size() - 1; i >= 0; --i)
        ans.push_back(ansBuffer[i]);
}


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

bool inserted[100005];

void solve()
{
    cout << "Input" << endl; // 30 1 20 4 9 0
    vector<int> level;
    level.push_back(0);
    int x = -1;
    while (x != 0)
    {
        cin >> x;
        if (x == 0) break;
        level.push_back(x);
    }

    vector<int> origion = level;
    level = initMax(level);
    binaryTreeNode* heap = levelBuild(level, 1);

    cout << "Output" << endl;
    ans.clear();
    levelOrder(heap);
    print();
    ans.clear();
    heapSort(level);
    print();

    vector<int> tree;
    tree.push_back(0);
    for (int i = 1; i <= origion.size() - 1; ++i)
    {
        if (i == 1)
        {
            tree.push_back(origion[i]);
            inserted[origion[i]] = true;
            continue;
        }
        if (inserted[origion[i]])
            continue;
        tree.push_back(origion[i]);
        inserted[origion[i]] = true;
    }
  
    binaryTreeNode* biSearchTree = biSearchBuild(tree);

    ans.clear();
    preOrder(biSearchTree);
    print();
    ans.clear();
    inOrder(biSearchTree);
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

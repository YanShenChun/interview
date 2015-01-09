#ifndef TREE_H
#define TREE_H

#include <vector>

struct TreeNode
{
    int m_nValue;
    std::vector<TreeNode*> m_vChildren;
};

TreeNode* CreateTreeNode(int value);
void ConnectTreeNodes(TreeNode *pParent, TreeNode *pChild);
void PrintTreeNode(TreeNode *pNode);
void PrintTree(TreeNode *pRoot);
void DestoryTree(TreeNode *pRoot);

#endif

#include "Tree.h"

TreeNode* CreateTreeNode(int value)
{
    TreeNode *pNode = new TreeNode();
    pNode->m_nValue = value;
    return pNode;
}

void ConnectTreeNodes(TreeNode *pParent, TreeNode *pChild)
{
    if (pParent != NULL)
    {
        pParent->m_vChildren.push_back(pChild);
    }
}

void PrintTreeNode(TreeNode *pNode)
{
    if (pNode != NULL)
    {
        printf("value of this node is: %d.\n", pNode->m_nValue);
        printf("its children is as the following:\n");

        for (std::vector<TreeNode*>::const_iterator i = pNode->m_vChildren.begin();
             i != pNode->m_vChildren.end(); ++i)
        {
            if (*i != NULL)
                printf("%d\t", (*i)->m_nValue);
        }
        printf("\n");
    }
    else
    {
        printf("this node is null.\n");
    }
}

void PrintTree(TreeNode *pRoot)
{
    PrintTreeNode(pRoot);

    if (pRoot != NULL)
    {
        for (std::vector<TreeNode*>::const_iterator i = pRoot->m_vChildren.begin();
             i != pRoot->m_vChildren.end(); ++i)
        {
            PrintTreeNode(*i);
        }
    }
}

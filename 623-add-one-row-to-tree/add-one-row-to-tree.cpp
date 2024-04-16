/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int value = 0;
    int dep;
    void fdepth(TreeNode* root, int deep)
    {
        if (deep == dep - 1)
        {
            TreeNode* ltmp = new TreeNode;
            ltmp->val = value;
            ltmp->left = root->left;
            root->left = ltmp;
            TreeNode* rtmp = new TreeNode;
            rtmp->val = value;
            rtmp->right = root->right;
            root->right = rtmp;
            return ;
        }
        if (root->left != NULL)
            fdepth(root->left, deep + 1);
        if (root->right != NULL)
            fdepth(root->right, deep + 1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth)
    {
        if (depth == 1)
        {
            TreeNode* tmp = new TreeNode;
            tmp->val = val;
            tmp->left = root;
            return tmp;
        }    
        value = val;
        dep = depth;
        fdepth(root, 1);
        return root;
    }
};
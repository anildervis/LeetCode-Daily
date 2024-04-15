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
    int ans = 0;
    void res(TreeNode* root, int num)
    {
        if (root->left != NULL or root->right != NULL)
        {
            if (root->left != NULL)
                res(root->left, num * 10 + root->val);
            if (root->right != NULL)
                res(root->right, num * 10 + root->val);
        }
        else
            ans += num * 10 + root->val;
    }
    int sumNumbers(TreeNode* root)
    {
        res(root, 0);
        return ans;
    }
};
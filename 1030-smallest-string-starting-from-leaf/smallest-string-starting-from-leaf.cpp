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
    string alp = "abcdefghijklmnopqrstuvwxyz";
    priority_queue<string, vector<string>, greater<string>> pq;

    void rec(TreeNode* node, string s)
    {
        if (node->left == NULL and node->right == NULL)
        {
            pq.push({alp[node->val] + s});
            return ;
        }
        if (node->left)
            rec(node->left, alp[node->val] + s);
        if (node->right)
            rec(node->right, alp[node->val] + s);
    }

    string smallestFromLeaf(TreeNode* root)
    {
        rec(root, "");
        return pq.top();
    }
};
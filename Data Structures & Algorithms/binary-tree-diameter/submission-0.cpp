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
    int maxi = INT_MIN;

    int solver(TreeNode* root){
        if(!root){
            return 0;
        }

        int left = solver(root->left);
        int right = solver(root->right);

        maxi = max(maxi,left+right);

        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        solver(root);
        return maxi;
    }
};

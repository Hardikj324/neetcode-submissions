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
    unordered_map<int,int> mp;
    int i = 0;
    TreeNode* solver(vector<int>& preorder,int start,int end){
        if(start>end){
            return nullptr;
        }
        int val = preorder[i++];
        TreeNode* root = new TreeNode(val);
        
        int pos = mp[val];
        root->left = solver(preorder,start,pos-1);
        root->right = solver(preorder,pos+1,end);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]] = i;
        }

        return solver(preorder,0,n-1);;
    }
};

class Solution {
public:
    bool check(ListNode* head, TreeNode* root){
        if(head==nullptr) return true;
        if(root==nullptr) return false;
        if(head->val != root->val) return false;

        return check(head->next,root->left) || check(head->next,root->right);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root == nullptr) return false;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node->val == head->val){
                if(check(head,node)){
                    return true;
                }
            }

            if(node->left) {
                q.push(node->left);
            }

            if(node->right) {
                q.push(node->right);
            }

        }
        return false;
    }
};

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

class Codec {
public:

    string serialize(TreeNode* root) {
       string ans;
       queue<TreeNode*> q;
       q.push(root);
       
       while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();

        if (node) {
            ans += to_string(node->val) + ",";
            q.push(node->left);
            q.push(node->right);
        } else {
            ans += "null,";
        }
       }

       return ans;
    }

    TreeNode* deserialize(string data) {
        if (data == "null,") {
        return nullptr;
        }

        int n = data.size();
        vector<string> val;
        stringstream ss(data);
        string token;

        while(getline(ss,token,',')){
            if (!token.empty()) {
            val.push_back(token);
        }
        }

        TreeNode* root = new TreeNode(stoi(val[0]));
        queue<TreeNode*> q;
        q.push(root);

        int i=1;
        while(!q.empty() && i<val.size()){
            TreeNode* node = q.front();
            q.pop();

            if(val[i]!="null"){
                node->left = new TreeNode(stoi(val[i]));
                q.push(node->left);
            }
            i++;
            if( i<n && val[i]!="null"){
                node->right = new TreeNode(stoi(val[i]));
                q.push(node->right);
            }
            i++;
        }
    return root;
    }
};

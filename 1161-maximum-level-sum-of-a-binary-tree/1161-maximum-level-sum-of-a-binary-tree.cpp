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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        int ans = 1;
        long long maxi = LLONG_MIN;
        while(!q.empty()) {
            int n = q.size();
            long long sum = 0;
            level++;
            for(int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                q.pop();
                sum += temp->val;
                if(temp->left != NULL) {
                    q.push(temp->left);
                }
                if(temp->right != NULL) {
                    q.push(temp->right);
                }
            }
            if(sum > maxi) {
                maxi = sum;
                ans = level;
            }
        }
        return ans;
    }
};
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
    unordered_map<long long, int> mp;
    int ans = 0;
    void dfs(TreeNode* root, long long sum, int targetSum) {
        if(root == NULL) {
            return;
        }
        sum += root->val;
        ans += mp[sum - targetSum];
        mp[sum]++;
        dfs(root->left, sum, targetSum);
        dfs(root->right, sum, targetSum);
        mp[sum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        mp.clear();
        ans = 0;
        mp[0] = 1;
        dfs(root, 0, targetSum);
        return ans;
    }
};

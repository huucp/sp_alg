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
    int ret = 0;
    void dfs(TreeNode *p, vector<int>& cnt) {
        if (p == NULL) return;
        cnt[p -> val]++;
        if (p -> left != NULL) dfs(p -> left, cnt);
        if (p -> right != NULL) dfs(p -> right, cnt);
        if (p -> left == NULL && p -> right == NULL) {
            int odd = 0;
            for (int i = 1; i <= 9; i++)
                if (cnt[i] % 2 == 1) odd++;
            if (odd <= 1) this -> ret++;
        }
        cnt[p -> val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> cnt = vector<int>(10);
        this -> dfs(root, cnt);
        return this -> ret;
    }
};
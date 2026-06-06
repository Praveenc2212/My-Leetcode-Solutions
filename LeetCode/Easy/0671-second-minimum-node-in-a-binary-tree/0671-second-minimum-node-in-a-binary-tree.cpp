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
    set<int> st;
    void dfs( TreeNode* root) {
        if( root ){
            st.insert(root->val);
            dfs( root->left);
            dfs( root->right);
        }
    }
    int findSecondMinimumValue(TreeNode* root) {
        dfs(root);

        int i = 0 ;
        for( int s : st ){
            if( i == 1 ) {
                return s;
            }
            i++;

        }
        return -1;
    }
};
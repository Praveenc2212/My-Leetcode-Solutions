class Solution {
public:

    int fun( TreeNode* root ){

        if( root == nullptr ) return 0 ;

        int left = fun( root->left  );
        int right = fun( root->right );

        if(  left == 0  ){
            root->left = nullptr;
        }
        if(  right  == 0  ){
            root->right = nullptr;
        }
        return root->val + left + right  ;

    }

    TreeNode* pruneTree(TreeNode* root) 
    {
        int t = fun(root);
        if( t == 0  )
            return nullptr ;
        return root;    
    }
};
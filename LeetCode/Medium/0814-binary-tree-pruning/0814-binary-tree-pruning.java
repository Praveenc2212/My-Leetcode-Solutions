
class Solution {
    int fun( TreeNode root ){
        if( root == null )
            return 0 ;
        int left = fun( root.left );
        int right = fun( root.right );

        if( left == 0 ) root.left = null ;
        if( right == 0 ) root.right = null ;
        return root.val + left + right ;
    }
    public TreeNode pruneTree(TreeNode root) {
        int t = fun( root );
        if( t == 0 ) return null;
        return root;
    }
}
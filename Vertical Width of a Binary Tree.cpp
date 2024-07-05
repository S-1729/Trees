class Solution {
  public:
    int minm=0,maxm=0;
    void solve(Node* root,int level){
        if(!root)
            return ;
        minm=min(minm,level);
        maxm=max(maxm,level);
        solve(root->left,level-1);
        solve(root->right,level+1);
    }
    int verticalWidth(Node* root) {
        if(!root)
            return 0;
        solve(root,0);
        return maxm-minm+1;
    }
};

/*
    Given a Binary Tree. You need to find and return the vertical width of the tree.
    
    Examples :
    
    Input:
             1
           /    \
          2      3
         / \    /  \
        4   5  6    7
                \    \
                 8    9
    Output: 6
    Explanation: The width of a binary tree is
    the number of vertical paths in that tree.
    The above tree contains 6 vertical lines.

    Input:
         1
        /  \
       2    3
    Output: 3
    Explanation: The above tree has 3 vertical lines, hence the answer is 3.

    T.C : O(n)
*/

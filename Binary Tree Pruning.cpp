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
    TreeNode* pruneTree(TreeNode* root) {
        if(!root)
            return NULL;
        root->left=pruneTree(root->left);
        root->right=pruneTree(root->right);
        
        if(root->left==NULL && root->right==NULL && root->val==0)
            return NULL;
        return root;
    }
};

/*
    Given the root of a binary tree, return the same tree where every subtree (of the given tree) not containing a 1 has been removed.
    A subtree of a node node is node plus every node that is a descendant of node.
    
    Example 1:
                1                  1
                 \                  \
                  0      -->         0
                /   \                  \
               0     1                  1
    
    Input: root = [1,null,0,0,1]
    Output: [1,null,0,null,1]
    Explanation: 
    Only the red nodes satisfy the property "every subtree not containing a 1".
    The diagram on the right represents the answer.
    
    Example 2:
                1                  1
              /   \                  \
             0      1      -->         1
           /   \   /   \                 \
          0     0 0     1                  1
    
    Input: root = [1,0,1,0,0,0,1]
    Output: [1,null,1,null,1]
    
    Example 3:
                1                    1
              /   \                /   \
             1      0      -->    1      0
           /   \   /   \        /   \     \
          1     1 0     1      1     1     1
        /
       0
       
    Input: root = [1,1,0,1,1,0,1,0]
    Output: [1,1,0,1,1,null,1]

    T.C : O(n)
*/

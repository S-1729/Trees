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
    TreeNode* solve(TreeNode* root,int target){
        if(!root)
            return nullptr;
        if(!root->left && !root->right){
            if(root->val==target)
                return nullptr;
            return root;
        }
        root->left=solve(root->left,target);
        root->right=solve(root->right,target);
        if(!root->left && !root->right){
            if(root->val==target)
                return nullptr;
            return root;
        }
        return root;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return solve(root,target);
    }
};

/*
    Given a binary tree root and an integer target, delete all the leaf nodes with value target.
    Note that once you delete a leaf node with value target, if its parent node becomes a leaf node and has the value target, it should also be deleted (you need to continue doing that until you cannot).
    
    Example 1:
                 1              =>            1          =>      1
              /    \                        /   \                 \
            2        3                     2     3                 3
          /        /   \                           \                 \
        2         2     4                           4                 4
        
    Input: root = [1,2,3,2,null,2,4], target = 2
    Output: [1,null,3,null,4]
    Explanation: Leaf nodes in green with value (target = 2) are removed (Picture in left). 
    After removing, new nodes become leaf nodes with value (target = 2) (Picture in center).
    
    Example 2:
                1               =>            1
              /   \                          /
            3      3                        3
          /   \                              \
         3     2                              2
         
    Input: root = [1,3,3,3,2], target = 3
    Output: [1,3,null,null,2]
    
    Example 3:
                1              =>1            1         =>        1        =>      1
               /                             /                   /
              2                             2                   2
             /                             /
            2                             2
           /
          2
    
    Input: root = [1,2,null,2,null,2], target = 2
    Output: [1]
    Explanation: Leaf nodes in green with value (target = 2) are removed at each step.

    T.C : O(n)
*/

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
    TreeNode* solve(TreeNode* root,int val,int depth,int curr){
        if(root==nullptr)
            return nullptr;
        if(curr==depth-1){
            TreeNode* lefttemp=root->left;
            TreeNode* righttemp=root->right;
            root->left=new TreeNode(val);
            root->right=new TreeNode(val);
            root->left->left=lefttemp;
            root->right->right=righttemp;
            return root;
        }
        root->left=solve(root->left,val,depth,curr+1);
        root->right=solve(root->right,val,depth,curr+1);
        return root;
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* node=new TreeNode(val);
            node->left=root;
            return node;
        }
        return solve(root,val,depth,1);
    }
};

/*
    Given the root of a binary tree and two integers val and depth, add a row of nodes with value val at the given depth depth.
    Note that the root node is at depth 1.
    The adding rule is:
    .Given the integer depth, for each not null tree node cur at the depth depth - 1, create two tree nodes with value val as cur's left subtree root and right subtree root.
    .cur's original left subtree should be the left subtree of the new left subtree root.
    .cur's original right subtree should be the right subtree of the new right subtree root.
    .If depth == 1 that means there is no depth depth - 1 at all, then create a tree node with value val as the new root of the whole original tree, and the original tree is the new root's left subtree.
    
    Example 1:
                4                         4
              /   \                     /   \
            2       6     =>          1       1
          /   \    /                /           \    
        3      1  5                2              6
                                /    \          /
                              3       1       5

    Input: root = [4,2,6,3,1,5], val = 1, depth = 2
    Output: [4,1,1,2,null,null,6,3,1,5]
    
    Example 2:
              4                             4
            /                              /   
          2            =>                 2  
        /   \                           /  \
      3      1                         1     1
                                      /        \
                                     3          1

    Input: root = [4,2,null,3,1], val = 1, depth = 3
    Output: [4,2,null,1,1,3,null,null,1]

    T.C : O(n)
*/

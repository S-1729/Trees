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
    int solve(TreeNode* root,bool leftLeaf){
        if(!root) 
            return 0; 
        if(root->left==nullptr && root->right==nullptr && leftLeaf){
            return root->val; 
        }
        int left=solve(root->left,true);
        int right=solve(root->right,false);
        return left+right;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return solve(root,false);
    }
};

//Code-2
class Solution {
public: 
    int solve(TreeNode* root,TreeNode* parent){
        if(!root) 
            return 0; 
        if(root->left==nullptr && root->right==nullptr){
            if(parent!=nullptr && parent->left==root)
                return root->val; 
        }
        int left=solve(root->left,root);
        int right=solve(root->right,root);
        return left+right;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return solve(root,nullptr);
    }
};

/*
    Given the root of a binary tree, return the sum of all left leaves.
    A leaf is a node with no children. A left leaf is a leaf that is the left child of another node. 

    Example 1:
    Input: root = [3,9,20,null,null,15,7]
    Output: 24
    Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.

    Example 2:
    Input: root = [1]
    Output: 0

    T.C : O(n)
*/

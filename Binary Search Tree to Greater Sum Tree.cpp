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
    void solve(TreeNode* root,int &sum){
        if(!root)
            return ;
        solve(root->right,sum);
        sum+=root->val;
        root->val=sum;
        solve(root->left,sum);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        int sum=0;
        solve(root,sum);
        return root;
    }
};

//Code-2 T.C : O(2n)
class Solution {
public:
    int findSum(TreeNode* root){
        if(!root)
            return 0;
        int left=findSum(root->left);
        int right=findSum(root->right);
        return root->val+left+right;
    }
    
    void solve(TreeNode* root,int &currSum,int totalSum){
        if(!root)
            return ;
        solve(root->left,currSum,totalSum);
        int value=totalSum-currSum;
        currSum+=root->val;
        root->val=value;
        solve(root->right,currSum,totalSum);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        int totalSum=findSum(root);
        int currSum=0;
        solve(root,currSum,totalSum);
        return root;
    }
};

/*
    Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.    
    As a reminder, a binary search tree is a tree that satisfies these constraints:
      .The left subtree of a node contains only nodes with keys less than the node's key.
      .The right subtree of a node contains only nodes with keys greater than the node's key.
      .Both the left and right subtrees must also be binary search trees.
     
    
    Example 1:
    Input: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
    Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
    
    Example 2:
    Input: root = [0,null,1]
    Output: [1,null,1]

    T.C : O(n)
*/

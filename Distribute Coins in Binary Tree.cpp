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
    int ans=0;
    int solve(TreeNode* root){
        if(!root)
            return 0;
        int Left=solve(root->left);
        int Right=solve(root->right);
        int val=root->val+Left+Right-1;
        ans+=abs(val);
        return val;
    }
    int distributeCoins(TreeNode* root) {
        solve(root);
        return ans;
    }
};

/*
    You are given the root of a binary tree with n nodes where each node in the tree has node.val coins. There are n coins in total throughout the whole tree.
    In one move, we may choose two adjacent nodes and move one coin from one node to another. A move may be from parent to child, or from child to parent.
    Return the minimum number of moves required to make every node have exactly one coin.

    Example 1:
          3
        /   \
       0     0

    Input: root = [3,0,0]
    Output: 2
    Explanation: From the root of the tree, we move one coin to its left child, and one coin to its right child.

    Example 2:
            0
          /   \
         3     0

    Input: root = [0,3,0]
    Output: 3
    Explanation: From the left child of the root, we move two coins to the root [taking two moves]. Then, we move one coin from the root of the tree to the right child.

    T.C : O(n)
*/

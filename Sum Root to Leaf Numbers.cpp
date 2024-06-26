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
    int solve(TreeNode* root,int sum){
        if(!root)
            return 0;
        sum=(sum*10)+root->val;
        if(!root->left&&!root->right)
            return sum;
        int left=solve(root->left,sum);
        int right=solve(root->right,sum);
        return left+right;
    }
    int sumNumbers(TreeNode* root) {
        return solve(root,0);
    }
};

//Code-2 S.C : O(n)
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,root->val});
        int ans=0;
        while(!q.empty()){
            TreeNode* node=q.front().first;
            int sum=q.front().second;
            q.pop();
            if(!node->left&&!node->right){
                ans+=sum;
            }
            if(node->left)
                q.push({node->left,sum*10+node->left->val});
            if(node->right)
                q.push({node->right,sum*10+node->right->val});
        }
        return ans;
    }
};

/*
    You are given the root of a binary tree containing digits from 0 to 9 only.
    Each root-to-leaf path in the tree represents a number.
       .For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
    Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.
    A leaf node is a node with no children.

    Example 1:
    Input: root = [1,2,3]
    Output: 25
    Explanation:
    The root-to-leaf path 1->2 represents the number 12.
    The root-to-leaf path 1->3 represents the number 13.
    Therefore, sum = 12 + 13 = 25.

    Example 2:
    Input: root = [4,9,0,5,1]
    Output: 1026
    Explanation:
    The root-to-leaf path 4->9->5 represents the number 495.
    The root-to-leaf path 4->9->1 represents the number 491.
    The root-to-leaf path 4->0 represents the number 40.
    Therefore, sum = 495 + 491 + 40 = 1026.

    T.C : O(n)
*/

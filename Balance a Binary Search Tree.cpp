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
    vector<int>arr;
    TreeNode* solve(int low,int high){
        if(low>high)
            return NULL;
        int mid=low+(high-low)/2;
        TreeNode* root=new TreeNode(arr[mid]);
        root->left=solve(low,mid-1);
        root->right=solve(mid+1,high);
        return root;
    }
        
    void inorder(TreeNode* root){
        if(!root)
            return ;
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return solve(0,arr.size()-1);
    }
};

/*
    Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.
    A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.
    
    Example 1:
              1        =>         2            (or)          3
               \                /  \                        /  \
                2              1    3                      1    4
                  \                  \                      \
                   3                  4                       2
                    \
                     4

    Input: root = [1,null,2,null,3,null,4,null,null]
    Output: [2,1,3,null,null,null,4]
    Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.
    
    Example 2:
              2
            /   \
          1       3

    Input: root = [2,1,3]
    Output: [2,1,3]

    T.C : O(2n)
    S.C : O(n)
*/

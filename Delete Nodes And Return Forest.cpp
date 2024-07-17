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
    unordered_set<int>S;
    vector<TreeNode*>ans;
    TreeNode* solve(TreeNode* root){
        if(!root)
            return NULL;
        root->left=solve(root->left);
        root->right=solve(root->right);
        if(S.find(root->val)!=S.end()){
            if(root->left)
                ans.push_back(root->left);
            if(root->right)
                ans.push_back(root->right);
            return NULL;
        }
        return root;
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(auto x:to_delete)
            S.insert(x);
        if(solve(root))
            ans.push_back(root);
        return ans;
    }
};

/*
    Given the root of a binary tree, each node in the tree has a distinct value.
    After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).
    Return the roots of the trees in the remaining forest. You may return the result in any order.
    
    Example 1:
                  1
                /   \
              2       3
            /  \    /   \
          4     5  6     7
    
    Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
    Output: [[1,2,null,4],[6],[7]]
    
    Example 2:
                  1
                /   \
              2      4
                \
                 3

    Input: root = [1,2,4,null,3], to_delete = [3]
    Output: [[1,2,4]]
    
    T.C : O(n)
    S.C : O(n)
*/

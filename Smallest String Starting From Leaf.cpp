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
    string ans="";
    void solve(TreeNode* root,string s){
        if(!root)
            return ;
        s=char(root->val+'a')+s;
        if(!root->left&&!root->right){
            if(ans=="" || ans>s)
                ans=s;
            return ;
        }
        solve(root->left,s);
        solve(root->right,s);
    }
    string smallestFromLeaf(TreeNode* root) {
        solve(root,"");
        return ans;
    }
};


//Code-2 S.C : O(n)
class Solution {
public:
    vector<string>ans;
    void solve(TreeNode* root,string s){
        if(!root)
            return ;
        s=char(root->val+'a')+s;
        if(!root->left&&!root->right){
            ans.push_back(s);
            return ;
        }
        solve(root->left,s);
        solve(root->right,s);
    }
    string smallestFromLeaf(TreeNode* root) {
        solve(root,"");
        sort(begin(ans),end(ans));
        return ans[0];
    }
};

/*
    You are given the root of a binary tree where each node has a value in the range [0, 25] representing the letters 'a' to 'z'.
    Return the lexicographically smallest string that starts at a leaf of this tree and ends at the root.
    As a reminder, any shorter prefix of a string is lexicographically smaller.
    For example, "ab" is lexicographically smaller than "aba".
    A leaf of a node is a node that has no children.
  
    Example 1:
              a
            /   \
          b      c
        /  \    /  \
      d     e  d    e
    Input: root = [0,1,2,3,4,3,4]
    Output: "dba"

    Example 2:
              z
            /   \
          b      d
        /  \    /  \
      b     d  a    c    
    
    Input: root = [25,1,3,1,3,0,2]
    Output: "adz"

    Example 3:
               c
            /    \
          c       b
           \     / 
            b   a        
           /
          a
    Input: root = [2,2,1,null,1,0,null,0]
    Output: "abc"

    T.C : O(n)
*/

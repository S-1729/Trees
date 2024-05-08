struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<vector<int>>ans;
    void solve(Node* root,vector<int>v){
        if(!root)
            return ;
        v.push_back(root->data);
        if(!root->left && !root->right){
            ans.push_back(v);
            return ;
        }
        solve(root->left,v);
        solve(root->right,v);
    }
    vector<vector<int>> Paths(Node* root) {
        // code here
        solve(root,{});
        return ans;
    }
};

/*
    Given a Binary Tree of nodes, you need to find all the possible paths from the root node to all the leaf nodes of the binary tree.

    Example 1:
    Input:
           1
        /     \
       2       3
    Output: 
    1 2 
    1 3 
    Explanation: 
    All possible paths:
    1->2
    1->3
    
    Example 2:
    Input:
             10
           /    \
          20    30
         /  \
        40   60
    Output: 
    10 20 40 
    10 20 60 
    10 30 

    T.C : O(n)
    S.C : O(height of the tree)
*/

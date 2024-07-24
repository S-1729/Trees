class Solution {
  public:
    vector<int>arr;
    void solve(Node* root){
        if(!root)
            return;
            solve(root->left);
            arr.push_back(root->data);
            solve(root->right);
    }
    bool isBST(Node* root) {
        solve(root);
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]>=arr[i+1])
                return false;
        }
        return true;
    }
};

/*
    Given the root of a binary tree. Check whether it is a BST or not.
    Note: We are considering that BSTs can not contain duplicate Nodes.
    A BST is defined as follows:
    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.
    
    Examples:
    
    Input:
       2
     /    \
    1      3
            \
             5
    Output: true 
    Explanation: 
    The left subtree of every node contains smaller keys and right subtree of every node contains greater. Hence, the tree is a BST.
    
    Input:
      2
       \
        7
         \
          6
           \
            9
    Output: false 
    Explanation: 
    Since the node with value 7 has right subtree nodes with keys less than 7, this is not a BST. 
    
    Input:
       10
     /    \
    5      20
          /   \
         9     25
    Output: false
    Explanation: The node is present in the right subtree of 10, but it is smaller than 10.
    
    T.C : O(n)
    S.C : O(n)
*/

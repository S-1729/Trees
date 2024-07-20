/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    Node* solve(Node* root){
        if(!root)
            return NULL;
        root->left=solve(root->left);
        root->right=solve(root->right);
        if((!root->left&&!root->right) || (root->left&&root->right))
            return root;
        else if(root->left)
            return root->left;
        else
            return root->right;
    }

    Node *RemoveHalfNodes(Node *root) {
        return solve(root);
    }
};

/*
    You are given a binary tree and you need to remove all the half nodes (which have only one child). Return the root node of the modified tree after removing all the half-nodes.   
    Note: The output will be judged by the inorder traversal of the resultant tree, inside the driver code.
    
    Examples:
    
    Input: tree = 5
                /   \
              7     8
            / 
          2
    Output: 2 5 8
    Explanation: In the above tree, the node 7 has only single child. After removing the node the tree becomes  2<-5->8. Hence, the answer is 2 5 8 & it is in inorder traversal.
    
    Input:  tree = 2   
                  / \   
                7   5 
    Output: 7 2 5
    Explanation: Here there are no nodes which has only one child. So the tree remains same.
    
    T.C : O(n)
*/

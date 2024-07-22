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
class Solution{
    public:
    vector<int> solve(Node* root){
        if(!root)
            return {0,1,INT_MAX,INT_MIN};
        if(!root->left && !root->right)
            return {1,1,root->data,root->data};
        vector<int>left =solve(root->left);
        vector<int>right=solve(root->right);

        if(left[1] && right[1] && root->data>left[3] && root->data<right[2])
            return {left[0]+right[0]+1,1,min(root->data,left[2]),max(root->data,right[3])};
        else
            return {max(left[0],right[0]),0,0,0};
    }
    int largestBst(Node *root)
    {
    	return solve(root)[0];
    }
};

/*
    Given a binary tree. Find the size of its largest subtree which is a Binary Search Tree.
    Note: Here Size equals the number of nodes in the subtree.
    
    Examples :
    
    Input:   1
            /  \
            4   4              
           / \ 
          6   8
    Output: 1 
    Explanation: There's no sub-tree with size greater than 1 which forms a BST. All the leaf Nodes are the BSTs with size equal to 1.
    
    Input:    6
            /   \
          6      2              
           \    / \
            2  1   3
    Output: 3
    Explanation: The following sub-tree is a BST of size 3:  2
                                                           /   \
                                                          1     3
    
    T.C : O(n)
*/

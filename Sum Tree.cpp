/*
struct Node
{
    int data;
    Node* left, * right;
}; 
*/
class Solution {
  public:
    pair<int,bool>solve(Node* root){
        if(!root)
            return {0,true};
        if(!root->left && !root->right)
            return {root->data,true};
        auto p1=solve(root->left);
        auto p2=solve(root->right);
        int sum=p1.first+p2.first;
        return {sum+root->data,p1.second && p2.second && (sum==root->data)};
    }

    bool isSumTree(Node* root) {
        return solve(root).second;
    }
};

/*
    Given a Binary Tree. Check for the Sum Tree for every node except the leaf node. Return true if it is a Sum Tree otherwise, return false.   
    A SumTree is a Binary Tree where the value of a node is equal to the sum of the nodes present in its left subtree and right subtree. 
    An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. A leaf node is also considered a Sum Tree.
    
    Examples :
    
    Input:
        3
      /   \    
     1     2
    Output: true
    Explanation: The sum of left subtree and right subtree is 1 + 2 = 3, which is the value of the root node. Therefore,the given binary tree is a sum tree.
    
    Input:
              10
            /    \
          20      30
        /   \ 
       10    10
    Output: false
    Explanation: The given tree is not a sum tree. For the root node, sum of elements in left subtree is 40 and sum of elements in right subtree is 30. Root element = 10 which is not equal to 30+40.
    
    T.C : O(n)
*/

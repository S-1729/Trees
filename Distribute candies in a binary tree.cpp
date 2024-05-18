/*
struct Node {
	int key;
	Node *left, *right;
};
*/

class Solution
{
    public:
    int ans=0;
    int solve(Node* root){
        if(!root)
        return 0;
        
        int Left=solve(root->left);
        int Right=solve(root->right);
        int val=root->key+Left+Right-1;
        ans+=abs(val);
        return val;
    }
    int distributeCandy(Node* root)
    {
        solve(root);
        return ans;
    }
};

/*
    Given a binary tree with N nodes, in which each node value represents number of candies present at that node. In one move, one may choose two adjacent nodes and move only one candy from one node to another (the move may be from parent to child, or from child to parent.) 
    The task is to find the minimum number of moves required such that every node has exactly one candy.
    Note that the testcases are framed such that it is always possible to achieve a configuration in which every node has exactly one candy, after some moves.

    Example 1:
    Input :      3
               /   \
              0     0 

    Output : 2
    Explanation: 
    From the root of the tree, we move one candy to its left child, and one candy to its right child.

    Example 2:
    Input :      0
               /   \
              3     0  

    Output : 3
    Explanation : 
    From the left child of the root, we move two candies to the root [taking two moves]. Then, we move one candy from the root of the tree to the right child.

    T.C : O(n)
*/

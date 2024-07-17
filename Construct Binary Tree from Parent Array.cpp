/* node structure  used in the program
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
    unordered_map<int,vector<int>>mp;
    Node* solve(int n){
        if(n==-1)
            return NULL;
        Node* root=new Node(n);
        if(mp.find(n)!=mp.end()){
          root->left=solve(mp[n][0]);
          root->right=solve(mp[n][1]);
        }
        return root;
    }
    Node *createTree(vector<int> parent) {
        int n;
        for(int i=0;i<parent.size();i++){
            if(parent[i]==-1)
                n=i;
            else
                mp[parent[i]].push_back(i);
        }
        for(auto &it:mp){
            for(int i=0;i<2-it.second.size();i++)
            it.second.push_back(-1);
        }
        return solve(n);
        
    }
};

/*
    Given an array parent that is used to represent a tree. The array indices (0-based indexing) are the values of the tree nodes and parent[i] denotes the parent node of a particular node. 
    The parent of the root node would always be -1, as there is no parent for the root. 
    Construct the standard linked representation of Binary Tree from this array representation and return the root node of the constructed tree. 
    Note: If two elements have the same parent, the one that appears first in the array will be the left child and the other is the right child. 
    You don't need to print anything, the driver code will print the level order traversal of the returned root node to verify the output.
    
    Examples:
    
    Input: parent[] = [-1, 0, 0, 1, 1, 3,5]
    Output: 0 1 2 3 4 5 6
    Explanation: the tree generated
    will have a structure like 
              0
            /   \
           1     2
          / \
         3   4
        /
       5
     /
    6

    Input: parent[] = [2, 0, -1]
    Output: 2 0 1
    Explanation: the tree generated will
    have a sturcture like
                 2
                /   
               0      
              /   
             1     
    
    T.C : O(n)
    S.C : O(n)
*/

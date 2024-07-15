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
    TreeNode* solve(int num){
        if(num==-1)
            return NULL;
        TreeNode* root=new TreeNode(num);
        if(mp.find(num)!=mp.end()){
            root->left=solve(mp[num].first);
            root->right=solve(mp[num].second);
        }
        return root;
    }
    
    unordered_map<int,pair<int,int>>mp;
    unordered_set<int>S;
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        for(auto &arr:descriptions){
            if(mp.find(arr[0])==mp.end())
                mp[arr[0]]={-1,-1};
            if(arr[2]==1)
                mp[arr[0]].first=arr[1];
            else
                mp[arr[0]].second=arr[1];
            S.insert(arr[1]);
            
        }
    
        for(auto &it:mp){
            if(S.find(it.first)==S.end())
                return solve(it.first);
        }
        return NULL;
    }
};

/*
    You are given a 2D integer array descriptions where descriptions[i] = [parenti, childi, isLefti] indicates that parenti is the parent of childi in a binary tree of unique values. Furthermore,
      .If isLefti == 1, then childi is the left child of parenti.
      .If isLefti == 0, then childi is the right child of parenti.
    Construct the binary tree described by descriptions and return its root.
    The test cases will be generated such that the binary tree is valid.
    
    Example 1:
                    50
                  /    \
                20      80
              /   \     /
            15     17  19    

    Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
    Output: [50,20,80,15,17,19]
    Explanation: The root node is the node with value 50 since it has no parent.
    The resulting binary tree is shown in the diagram.
    
    Example 2:
                    1
                  /
                2
                  \
                   3
                 /
               4
    
    Input: descriptions = [[1,2,1],[2,3,0],[3,4,1]]
    Output: [1,2,null,null,3,4]
    Explanation: The root node is the node with value 1 since it has no parent.
    The resulting binary tree is shown in the diagram.
    
    T.C : O(n)
    S.C : O(n)
*/

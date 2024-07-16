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
    bool solve(TreeNode* root,int x,string &str){
        if(!root)
            return false;
        if(root->val==x)
            return true;
        str+='L';
        if(solve(root->left,x,str))
            return true;
        str.pop_back();
        str+='R';
        if(solve(root->right,x,str))
            return true;
        str.pop_back();
        return false;
        
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string str1="",str2="";
        solve(root,startValue,str1);
        solve(root,destValue,str2);
        int i=0;
        while(i<str1.size() && i<str2.size() && str1[i]==str2[i])
            i++;
        string ans="";
        for(int j=i;j<str1.size();j++)
            ans.push_back('U');
        for(int j=i;j<str2.size();j++)
            ans.push_back(str2[j]);
        return ans;
    }
};

//Code-2
class Solution {
public:
    TreeNode* LCA(TreeNode* root,int startValue,int destValue){
        if(!root)
            return NULL;
        if(root->val==startValue || root->val==destValue)
            return root;
        TreeNode* left=LCA(root->left,startValue,destValue);
        TreeNode* right=LCA(root->right,startValue,destValue);
        if(left && right)
            return root;
        else if(left)
            return left;
        else
            return right;
    }
    
    bool solve(TreeNode* root,int x,string &str){
        if(!root)
            return false;
        if(root->val==x)
            return true;
        str+='L';
        if(solve(root->left,x,str))
            return true;
        str.pop_back();
        str+='R';
        if(solve(root->right,x,str))
            return true;
        str.pop_back();
        return false;
        
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string str1="",str2="";
        TreeNode* lca=LCA(root,startValue,destValue);
        solve(lca,startValue,str1);
        solve(lca,destValue,str2);
        string ans="";
        for(int i=0;i<str1.size();i++)
            ans.push_back('U');
        ans+=str2;
        return ans;
    }
};

/*
    You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n. You are also given an integer startValue representing the value of the start node s, and a different integer destValue representing the value of the destination node t.
    Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such path as a string consisting of only the uppercase letters 'L', 'R', and 'U'. Each letter indicates a specific direction:
      .'L' means to go from a node to its left child node.
      .'R' means to go from a node to its right child node.
      .'U' means to go from a node to its parent node.
    Return the step-by-step directions of the shortest path from node s to node t.
    
    Example 1:
                       5
                    /     \
                  1         2
                /         /   \
              3          6     4
    
    Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
    Output: "UURL"
    Explanation: The shortest path is: 3 → 1 → 5 → 2 → 6.
    
    Example 2:
                    2
                  /
                1
    
    Input: root = [2,1], startValue = 2, destValue = 1
    Output: "L"
    Explanation: The shortest path is: 2 → 1.
    
    T.C : O(n)
    S.C : O(n)
*/

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
    vector<int>arr;
    void solve(Node* root){
        if(!root)
            return ;
        arr.push_back(root->data);
        solve(root->left);
        solve(root->right);
    }

    vector<int> merge(Node *root1, Node *root2) {
        solve(root1);
        solve(root2);
        sort(begin(arr),end(arr));
        return arr;
    }
};

/*
    Given two BSTs, return elements of merged BSTs in sorted form.

    Examples :

    Input:
    BST1:
           5
         /   \
        3     6
       / \
      2   4  
    BST2:
            2
          /   \
         1     3
                \
                 7
                /
               6
    Output: 1 2 2 3 3 4 5 6 6 7
    Explanation: After merging and sorting the two BST we get 1 2 2 3 3 4 5 6 6 7.

    Input:
    BST1:
           12
         /   
        9
       / \    
      6   11
    BST2:
          8
        /  \
       5    10
      /
     2
    Output: 2 5 6 8 9 10 11 12
    Explanation: After merging and sorting the two BST we get 2 5 6 8 9 10 11 12.

    T.C : O(nlogn)
    S.C : O(n+m)
*/

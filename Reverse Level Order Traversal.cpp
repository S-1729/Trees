/*   
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
vector<int> reverseLevelOrder(Node *root)
{
    vector<int>ans;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* node=q.front();
        q.pop();
        ans.push_back(node->data);
        if(node->right)
        q.push(node->right);
        if(node->left)
        q.push(node->left);
    }
    reverse(begin(ans),end(ans));
    return ans;
}

/*
    Given a binary tree of size n, find its reverse level order traversal. ie- the traversal must begin from the last level.

    Example 1:
    Input :
            1
          /   \
         3     2
    Output: 
    3 2 1
    Explanation:
    Traversing level 1 : 3 2
    Traversing level 0 : 1

    Example 2:
    Input :
           10
          /  \
         20   30
        / \ 
       40  60
    Output: 
    40 60 20 30 10
    Explanation:
    Traversing level 2 : 40 60
    Traversing level 1 : 20 30
    Traversing level 0 : 10

    T.C : O(n)
    S.C : O(n)
*/

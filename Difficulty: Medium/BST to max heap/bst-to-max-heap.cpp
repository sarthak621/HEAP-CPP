//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

/* Helper function that allocates a new node
with the given data and NULL left and right
pointers. */
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}
void postorderTraversal(Node* root)
{
    if (!root)
        return;

    // recur on left subtree
    postorderTraversal(root->left);

    // then recur on right subtree
    postorderTraversal(root->right);

    // print the root's data
    cout << root->data << " ";
}



// } Driver Code Ends

//User function Template for C++

/*struct Node {
    int data;
    Node *left, *right;
};*/

class Solution{
  public:
    
    void inOrderTraversal(Node* root , vector<int>&ans ){
        if(!root) return;
        
        if(root->left){
            inOrderTraversal(root->left,ans);
        }
        ans.push_back(root->data);
        if(root->right){
            inOrderTraversal(root->right,ans);
        }
    }
    
    void postOrderTraversal(Node* root,  vector<int>&ans, int &index ){
        //left right root
        
        if(!root) return;
        
        if(root->left){
            postOrderTraversal(root->left,ans,index);
        }
        if(root->right){
            postOrderTraversal(root->right,ans,index);
        }
        
        root->data=ans[index];
        index++;
        
    }
    
    void convertToMaxHeapUtil(Node* root)
    {
        // Your code goes here
        
        //approach-> first do inorder traversal and then do postorder traversal
        
        vector<int>ans;
        
        inOrderTraversal(root,ans);
        
        int index=0;
        
        return postOrderTraversal(root,ans,index);
        
        // return ans;
    }    
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    getchar();
    while (t--)
    {
        string inp, ch;
        getline(cin, inp);
        struct Node* root = buildTree(inp);
        Solution ob;
        ob.convertToMaxHeapUtil(root);
        postorderTraversal(root);
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}


// } Driver Code Ends
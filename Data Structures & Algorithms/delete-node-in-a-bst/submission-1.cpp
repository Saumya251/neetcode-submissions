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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr){
            return root;
        }
    if(root->val > key){
        root->left=deleteNode(root->left, key);
    }
    else if(root->val < key){
        root->right=deleteNode(root->right, key);
    }
    else{
        if(root->left==nullptr && root->right==nullptr){ //leaf node
            delete(root);
            return nullptr;
        }
        else if(root->right == nullptr){ //only one child
            TreeNode *temp=root->left;
            delete(root);
            return temp;
        }
        else if(root->left == nullptr){
            TreeNode *temp=root->right;
            delete(root);
            return temp;
        }
        else{ //two child exists
            TreeNode *child = root->left;
            TreeNode *parent = root;
            while(child->right){
                parent = child;
                child = child->right;
            }
            if(root != parent){ 
                parent->right=child->left;
                child->left = root->left;
                child->right = root->right;
                delete(root);
                return child;
            }
            else{ //root==parents
                child->right=root->right;
                delete(root);
                return child;
            }
        }
    }
        return root;
    }
};
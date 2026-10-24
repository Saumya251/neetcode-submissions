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
    bool isSameTree(TreeNode* p,TreeNode* q ){
        bool left1, right1;
        if(p==nullptr && q== nullptr){
            return true;
        }
        if(p!=nullptr && q==nullptr || p==nullptr && q!=nullptr){
            return false;
        }
        left1=isSameTree(p->left,q->left );
        right1=isSameTree(p->right,q->right);
        if(p->val==q->val && left1==true && right1==true)
        return true;
        else
        return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot){
        bool left1,right1;
        if(subRoot==nullptr){
           return true;
        }
        if(root==nullptr && subRoot !=nullptr){
            return false;
        }
        if(isSameTree(root,subRoot)){
        return true;
        }
        left1 = isSubtree(root->left,subRoot);
        right1 = isSubtree(root->right,subRoot);
        if(left1==true || right1==true)
        return true;
        else 
        return false;
    }
};





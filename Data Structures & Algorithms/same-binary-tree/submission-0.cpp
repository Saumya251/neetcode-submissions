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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool left1,right1;
        if(p==nullptr && q==nullptr){
           return true;
        }
        if(p==nullptr && q !=nullptr || p!=nullptr && q==nullptr){
            return false;
        }
        left1 = isSameTree(p->left, q->left);
        right1 = isSameTree(p->right, q->right);
        if(left1== true && right1==true && p->val==q->val)
           return true;
        else
        return false;
    }
};








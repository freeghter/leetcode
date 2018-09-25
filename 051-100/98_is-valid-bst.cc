//
// Created by ft on 2018/9/10.
//
/**
 * 给定一个二叉树，判断其是否是一个有效的二叉搜索树。
 * 假设一个二叉搜索树具有如下特征：
 * 节点的左子树只包含小于当前节点的数。
 * 节点的右子树只包含大于当前节点的数。
 * 所有左子树和右子树自身必须也是二叉搜索树。
 *
 * 示例 1:
 * 输入:
 *    2
 *   / \
 *  1   3
 *  输出: true
 *
 *输入:
 *     5
 *    / \
 *   1   4
 *  / \
 * 3   6
 * 输出: false
 * 解释: 输入为: [5,1,4,null,null,3,6]。
 * 根节点的值为 5 ，但是其右子节点值为 4 。
 */
#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {

        if(root == nullptr || (root->left == nullptr && root->right == nullptr))
            return true;

        stack<TreeNode *> s;
        if(root->left != nullptr){
            s.push(root->left);
            while (!s.empty()){
                auto t = s.top(); s.pop();
                if(t->val >= root->val)
                    return false;
                if(t->left != nullptr)
                    s.push(t->left);
                if(t->right != nullptr)
                    s.push(t->right);
            }
        }

        if(root->right != nullptr){
            s.push(root->right);
            while (!s.empty()){
                auto t = s.top(); s.pop();
                if(t->val <= root->val)
                    return false;
                if(t->left != nullptr)
                    s.push(t->left);
                if(t->right != nullptr)
                    s.push(t->right);
            }
        }

        bool left = true, right = true;
        if(root->left)
            left = isValidBST(root->left);
        if(root->right)
            right = isValidBST(root->right);
        return left && right;
    }
};

int main(int argc, char * argv[]){
    return 0;
}

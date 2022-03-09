/*
给定一个二叉树，计算 整个树 的坡度 。

一个树的 节点的坡度 定义即为，该节点左子树的节点之和和右子树节点之和的 差的绝对值 。如果没有左子树的话，左子树的节点之和为 0 ；没有右子树的话也是一样。空结点的坡度是 0 。

整个树 的坡度就是其所有节点的坡度之和。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-tilt
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int findTilt(TreeNode* root) {
        if (nullptr == root) {
            return 0;
        }
        GetPlus(root);
        GetDiff(root);
        GetPlus(root);
        return root->val;
    }
    void GetDiff(TreeNode* root) {
        TreeNode* left = root->left;
        int leftVal = 0;
        if (nullptr != left)
        {
            leftVal = left->val;
        }
        TreeNode* right = root->right;
        int rightVal = 0;
        if (nullptr != right)
        {
            rightVal = right->val;
        }
        root->val = ((leftVal >= rightVal) ? leftVal - rightVal : rightVal - leftVal);
        if (nullptr != left)
        {
            GetDiff(left);
        }
        if (nullptr != right)
        {
            GetDiff(right);
        }
    }
    void GetPlus(TreeNode* root) {
        TreeNode* left = root->left;
        int leftVal = 0;
        if (nullptr != left)
        {
            if (nullptr != left->left)
            {
                GetPlus(left);
            }
            leftVal = left->val;

        }
        TreeNode* right = root->right;
        int rightVal = 0;
        if (nullptr != right)
        {
            if (nullptr != root->right)
            {
                GetPlus(right);
            }
            rightVal = right->val;
        }
        root->val += (leftVal + rightVal);
    }
};
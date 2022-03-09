/*
����һ�������������� ������ ���¶� ��

һ������ �ڵ���¶� ���弴Ϊ���ýڵ��������Ľڵ�֮�ͺ��������ڵ�֮�͵� ��ľ���ֵ �����û���������Ļ����������Ľڵ�֮��Ϊ 0 ��û���������Ļ�Ҳ��һ�����ս����¶��� 0 ��

������ ���¶Ⱦ��������нڵ���¶�֮�͡�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/binary-tree-tilt
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
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
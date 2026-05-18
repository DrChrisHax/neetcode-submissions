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
    int diameterOfBinaryTree(TreeNode* root) {
        std::unordered_map<TreeNode*, pair<int, int>> map_;
        map_[nullptr] = {0, 0};
        std::stack<TreeNode*> stack_;
        stack_.push(root);

        while (!stack_.empty()) {
            TreeNode* node = stack_.top();

            TreeNode* left = node->left;
            TreeNode* right = node->right;
            if (left && map_.find(left) == map_.end()) {
                stack_.push(left);
            } else if (right && map_.find(right) == map_.end()) {
                stack_.push(right);
            } else {
                stack_.pop();

                auto [leftH, leftD] = map_[left];
                auto [rightH, rightD] = map_[right];

                int h = 1 + std::max(leftH, rightH);
                int d = std::max(leftH + rightH, std::max(leftD, rightD));

                map_[node] = {h, d};
            }
        }

        return map_[root].second;
    }
};

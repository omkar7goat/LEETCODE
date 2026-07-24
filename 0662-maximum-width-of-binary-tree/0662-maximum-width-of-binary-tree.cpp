class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        unsigned long long max_width = 0;

        while (!q.empty()) {
            int n = q.size();

            unsigned long long first_index = q.front().second;
            unsigned long long last_index = q.back().second;

            max_width = max(max_width, last_index - first_index + 1);

            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front().first;
                unsigned long long index = q.front().second;
                q.pop();

                unsigned long long normalized_index = index - first_index;

                if (curr->left) {
                    q.push({curr->left, 2 * normalized_index});
                }
                if (curr->right) {
                    q.push({curr->right, 2 * normalized_index + 1});
                }
            }
        }

        return max_width;
    }
};
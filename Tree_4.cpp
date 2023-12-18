#include <iostream>
#include <vector>
#include <stack>

using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        TreeNode* current = root;
        int count = 0;

        while (current != NULL || !s.empty()) {
            while (current != NULL) {
                s.push(current);
                current = current->left;
            }

            current = s.top();
            s.pop();

            count++;
            if (count == k) {
                return current->val;
            }

            current = current->right;
        }

        return -1;
    }
};

TreeNode* buildTree(const vector<int>& nodes, int index, int n) {
    TreeNode* root = NULL;

    if (index < n && nodes[index] != -1) {
        root = new TreeNode(nodes[index]);
        root->left = buildTree(nodes, 2 * index + 1, n);
        root->right = buildTree(nodes, 2 * index + 2, n);
    }

    return root;
}

int main() {
    Solution solution;

    vector<int> nodes1 = { 3, 1, 4, -1, 2 }; 
    TreeNode* root1 = buildTree(nodes1, 0, nodes1.size());
    int k1 = 1;
    cout << "Example 1: " << solution.kthSmallest(root1, k1) << endl;

    vector<int> nodes2 = { 5, 3, 6, 2, 4, -1, -1, 1 };
    TreeNode* root2 = buildTree(nodes2, 0, nodes2.size());
    int k2 = 3;
    cout << "Example 2: " << solution.kthSmallest(root2, k2) << endl;

    return 0;
}

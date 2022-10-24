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
    vector<TreeNode*> generateTrees(int n) {
        return generateTreesImpl(1, n);
    }
    
private:
    vector<TreeNode*> generateTreesImpl(int min, int max)
    {
        if(min > max) { return { nullptr }; }

        vector<TreeNode*> trees;

        for(int rootVal = min; rootVal <= max; ++rootVal)
        {
            vector<TreeNode*> leftSubTrees = generateTreesImpl(min, rootVal - 1);
            vector<TreeNode*> rightSubTrees = generateTreesImpl(rootVal + 1, max);

            for(auto leftSubTree : leftSubTrees)
            {
                for(auto rightSubTree :rightSubTrees )
                {
                    TreeNode* root = new TreeNode(rootVal);
                    root->left = leftSubTree;
                    root->right = rightSubTree;
                    trees.push_back(root);
                }
            }
        }

        return trees;
    }
};

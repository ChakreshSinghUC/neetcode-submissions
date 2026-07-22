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
    vector<int> rightSideView(TreeNode* root) {
        //vector<vector<int>> levelOrderTraversal;
        vector<int> ans;
        if (root == nullptr) {
            return ans;
        }

        queue<TreeNode*> grayNodes;
        grayNodes.push(root);

        while (!grayNodes.empty()) {
            //vector<int> currLevel;

            int n = grayNodes.size();

            while (n--) {
                TreeNode* currNode = grayNodes.front();
                grayNodes.pop();

                if(n==0) {
                    ans.push_back(currNode->val);
                }

               // currLevel.push_back(currNode->val);

                if (currNode->left != nullptr) {
                    grayNodes.push(currNode->left);
                }
                if (currNode->right != nullptr) {
                    grayNodes.push(currNode->right);
                }
            }
            //levelOrderTraversal.push_back(currLevel);
        }

        return ans;
    }
};

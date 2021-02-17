#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  TreeNode *trimBST(TreeNode *root, int low, int high) {
    if (root == NULL) {
      return root;
    }
    if (root->val < low) {
      return trimBST(root->right, low, high);
    }
    if (root->val > high) {
      return trimBST(root->left, low, high);
    }
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);
    return root;
  }
};

class FastSolution {
 private:
  TreeNode *findFirstInRange(TreeNode *root, int low, int high) {
    if (root == NULL) {
      return root;
    } else if (low <= root->val && root->val <= high) {
      return root;
    } else if (root->val < low) {
      return findFirstInRange(root->right, low, high);
    } else {
      return findFirstInRange(root->left, low, high);
    }
  }

 public:
  TreeNode *trimBST(TreeNode *root, int low, int high) {
    if (root == NULL) {
      return root;
    }
    if (root->val < low || root->val > high) {
      root = findFirstInRange(root, low, high);
    }
    TreeNode *left = root->left;
    TreeNode *right = root->right;
    if (left != NULL && (left->val < low || left->val > high)) {
      root->left = findFirstInRange(root->left, low, high);
    }
    if (right != NULL && (right->val < low || right->val > high)) {
      root->right = findFirstInRange(root->right, low, high);
    }
    trimBST(root->left, low, high);
    trimBST(root->right, low, high);
    return root;
  }
};

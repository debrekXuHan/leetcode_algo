/*
 * @lc app=leetcode id=99 lang=c
 *
 * [99] Recover Binary Search Tree
 *
 * https://leetcode.com/problems/recover-binary-search-tree/description/
 *
 * algorithms
 * Hard (37.54%)
 * Likes:    1295
 * Dislikes: 67
 * Total Accepted:    151.4K
 * Total Submissions: 397.8K
 * Testcase Example:  '[1,3,null,null,2]'
 *
 * Two elements of a binary search tree (BST) are swapped by mistake.
 * 
 * Recover the tree without changing its structure.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,3,null,null,2]
 * 
 * 1
 * /
 * 3
 * \
 * 2
 * 
 * Output: [3,1,null,null,2]
 * 
 * 3
 * /
 * 1
 * \
 * 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,1,4,null,null,2]
 * 
 * ⁠ 3
 * ⁠/ \
 * 1   4
 * /
 * 2
 * 
 * Output: [2,1,4,null,null,3]
 * 
 * ⁠ 2
 * ⁠/ \
 * 1   4
 * /
 * ⁠ 3
 * 
 * 
 * Follow up:
 * 
 * 
 * A solution using O(n) space is pretty straight forward.
 * Could you devise a constant space solution?
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// stacking all nodes and then sorting
void inorder(struct TreeNode *root, struct TreeNode *res[], int *cnt) {
    if (NULL == root) return;
    inorder(root->left, res, cnt);
    res[(*cnt)++] = root;
    inorder(root->right, res, cnt);
    res[(*cnt)++] = root;
    return;
}

void recoverTree(struct TreeNode* root){
    struct TreeNode *res[2000] = {0};
    int cnt = 0;
    inorder(root, res, &cnt);

    if (cnt <= 0) return;
    // bubble sorting
    for (int i = 0; i < cnt; i++) {
        for (int j = 1; j < cnt - i; j++) {
            if (res[j - 1]->val > res[j]->val) {
                int tmp = res[j - 1]->val;
                res[j - 1]->val = res[j]->val;
                res[j]->val = tmp;
            }
        }
    }
}

// a faster method, searching for two wrong nodes and swap them
void inorder(struct TreeNode *root, struct TreeNode **pre, struct TreeNode **first, struct TreeNode **second) {
    if (NULL == root) return;
    inorder(root->left, pre, first, second);

    if (!(*pre)) {
        *pre = root;
    } else {
        if ((*pre)->val > root->val) {
            if (!(*first)) *first = *pre;
            *second = root;
        }
        *pre = root;
    }
    inorder(root->right, pre, first, second);
    return;
}

void recoverTree(struct TreeNode* root){
    struct TreeNode *pre = NULL, *first = NULL, *second = NULL;
    inorder(root, &pre, &first, &second);
    int tmp = first->val;
    first->val = second->val;
    second->val = tmp;
    return;
}
// @lc code=end
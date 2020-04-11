/*
 * @lc app=leetcode id=102 lang=c
 *
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (52.29%)
 * Likes:    2478
 * Dislikes: 64
 * Total Accepted:    545.5K
 * Total Submissions: 1M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
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


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int **result = NULL;
    if (root == NULL) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return result;
    }

    *returnSize = 0;
    *returnColumnSizes = NULL;

    struct TreeNode **queue = (struct TreeNode **)malloc(sizeof(struct TreeNode *));
    struct TreeNode *pop;
    int start = 0, end = 0, length = 0;

    queue[end++] = root;
    length = 1;
    while (length > 0) {
        result = (int **)realloc(result, (*returnSize + 1) * sizeof(int *));
        result[*returnSize] = (int *)malloc(sizeof(int) * length);
        *returnColumnSizes = (int *)realloc(*returnColumnSizes, (*returnSize + 1) * sizeof(int));
        (*returnColumnSizes)[*returnSize] = length;

        for (int i = 0; i < length; i++) {
            pop = queue[start++];
            result[*returnSize][i] = pop->val;
            if (pop->left) {
                queue = (struct TreeNode **)realloc(queue, sizeof(struct TreeNode *) * (end + 1));
                queue[end++] = pop->left;
            }
            if (pop->right) {
                queue = (struct TreeNode **)realloc(queue, sizeof(struct TreeNode *) * (end + 1));
                queue[end++] = pop->right;
            }
        }
        length = end - start;
        *returnSize += 1;
    }
    return result;
}


// @lc code=end


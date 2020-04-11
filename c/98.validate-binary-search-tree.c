/*
 * @lc app=leetcode id=98 lang=c
 *
 * [98] Validate Binary Search Tree
 *
 * https://leetcode.com/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (27.13%)
 * Likes:    3297
 * Dislikes: 469
 * Total Accepted:    615K
 * Total Submissions: 2.3M
 * Testcase Example:  '[2,1,3]'
 *
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 * 
 * Assume a BST is defined as follows:
 * 
 * 
 * The left subtree of a node contains only nodes with keys less than the
 * node's key.
 * The right subtree of a node contains only nodes with keys greater than the
 * node's key.
 * Both the left and right subtrees must also be binary search trees.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 * 
 * Input: [2,1,3]
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * ⁠   5
 * ⁠  / \
 * ⁠ 1   4
 * / \
 * 3   6
 * 
 * Input: [5,1,4,null,null,3,6]
 * Output: false
 * Explanation: The root node's value is 5 but its right child's value is 4.
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

/*
// recursive method 1
bool judge_bound(struct TreeNode *root, int *lower_bound, int *upper_bound) {
    if (NULL == root) return true;

    int lower_bound_left, upper_bound_left, lower_bound_right, upper_bound_right;
    bool flag_left = judge_bound(root->left, &lower_bound_left, &upper_bound_left);
    bool flag_right = judge_bound(root->right, &lower_bound_right, &upper_bound_right);

    if ((root->right && root->val >= lower_bound_right) || (root->left && root->val <= upper_bound_left)) {
        return false;
    }

    *lower_bound = (root->left == NULL) ? root->val : lower_bound_left;
    *upper_bound = (root->right == NULL) ? root->val : upper_bound_right;

    return flag_left && flag_right;
}

bool isValidBST(struct TreeNode* root){
    int lower_bound, upper_bound;
    return judge_bound(root, &lower_bound, &upper_bound);
}
*/

// recursive method 2
void push_stack(struct TreeNode *root, int *stack, int *cnt) {
    if (NULL == root) return;

    push_stack(root->left, stack, cnt);
    stack[(*cnt)++] = root->val;
    push_stack(root->right, stack, cnt);
    return;
}

bool isValidBST(struct TreeNode* root){
    int stack[10000];
    int cnt = 0;
    push_stack(root, stack, &cnt);

    for (int i = 1; i < cnt; i++) {
        if (stack[i] <= stack[i - 1]) return false;
    }
    return true;
}
// @lc code=end
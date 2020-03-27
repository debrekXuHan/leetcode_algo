/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (59.89%)
 * Likes:    4176
 * Dislikes: 231
 * Total Accepted:    474.5K
 * Total Submissions: 792.2K
 * Testcase Example:  '3'
 *
 * 
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * 
 * For example, given n = 3, a solution set is:
 * 
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        add(result, "", n, 0);

        return result;
    }

    // if leftneed > 0, then you can insert a "(" in the string
    // if rightmore > 0, then you can insert a ")" in the string
    // the formal para "res" should be a reference since "res" can be returned in the recursive function

    void add(vector<string> &res, string s, int leftneed, int rightmore) {
        if (0 == leftneed && 0 == rightmore) {
            res.push_back(s);
            return;
        }

        if (leftneed > 0) {
            add(res, s + '(', leftneed - 1, rightmore + 1);
        }
        if (rightmore > 0) {
            add(res, s + ')', leftneed, rightmore - 1);
        }
    }
};
// @lc code=end


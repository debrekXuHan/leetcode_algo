/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 *
 * https://leetcode.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (51.34%)
 * Likes:    782
 * Dislikes: 101
 * Total Accepted:    174.2K
 * Total Submissions: 339.1K
 * Testcase Example:  '3'
 *
 * Given a positive integer n, generate a square matrix filled with elements
 * from 1 to n^2 in spiral order.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 8, 9, 4 ],
 * ⁠[ 7, 6, 5 ]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // init the result
        vector<vector<int>> result(n, vector<int>(n, 0));
        int count = n * n;
        int k = 1;
        int left = 0, right = n - 1, top = 0, bottom = n - 1;

        while (k <= count) {
            // top left to top right
            for (int i = left; i <= right; i++) {
                result[top][i] = k;
                k++;
            }
            // top right to bottom right
            for (int i = top + 1; i <= bottom; i++) {
                result[i][right] = k;
                k++;
            }
            // bottom right to bottom left
            for (int i = right - 1; i >= left; i--) {
                result[bottom][i] = k;
                k++;
            }
            // bottom left to top left
            for (int i = bottom - 1; i > top; i--) {
                result[i][left] = k;
                k++;
            }
            left++; right--;
            top++; bottom--;
        }
        return result;
    }
};

// @lc code=end


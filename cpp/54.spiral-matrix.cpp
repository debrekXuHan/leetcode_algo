/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (32.77%)
 * Likes:    1810
 * Dislikes: 502
 * Total Accepted:    318.7K
 * Total Submissions: 972.6K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of
 * the matrix in spiral order.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * Output: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * Example 2:
 * 
 * Input:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (0 == matrix.size()) return result;
        if (1 == matrix.size()) return matrix[0];

        // init the "left", "right", "top" and "bottom"
        int left = 0, right = matrix[0].size() - 1, top = 0, bottom = matrix.size() - 1;
        int num = matrix.size() * matrix[0].size();
        int n = 0;

        while (n < num) {
            // top left to top right
            for (int i = left; i <= right; i++) {
                result.push_back(matrix[top][i]);
                n++;
            }
            // top right to bottom right
            for (int i = top + 1; i <= bottom; i++) {
                result.push_back(matrix[i][right]);
                n++;
            }
            // bottom right to bottom left
            for (int i = right - 1; i >= left; i--) {
                result.push_back(matrix[bottom][i]);
                n++;
            }
            // bottom left to top left
            for (int i = bottom - 1; i > top; i--) {
                result.push_back(matrix[i][left]);
                n++;
            }
            top++;
            bottom--;
            left++;
            right--;
        }
        // pop out the redundant elements
        while (n > num) {
            result.pop_back();
            n--;
        }
        return result;
    }
};
// @lc code=end


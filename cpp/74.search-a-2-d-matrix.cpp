/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 *
 * https://leetcode.com/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (35.89%)
 * Likes:    1367
 * Dislikes: 142
 * Total Accepted:    289.5K
 * Total Submissions: 806.1K
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,50]]\n3'
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 * 
 * 
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the
 * previous row.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 3
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 13
 * Output: false
 * 
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (!matrix.size()) return false;
        if (!matrix[0].size()) return false;

        int height = matrix.size();
        int width = matrix[0].size();

        bool result = false;
        int row = 0, col = 0;

        // determine the row by binary search
        int front = 0, end = height - 1;
        int mid = (front + end) / 2;
        while (front < end && target != matrix[mid][0]) {
            if (target < matrix[mid][0]) end = mid - 1;
            if (target > matrix[mid][0]) front = mid + 1;
            mid = (front + end) / 2;
        }
        if (target < matrix[mid][0] && mid > 0) {
            // if target smaller than the final search, search the previous row
            row = mid - 1;
        } else {
            row = mid;
        }

        // determine the column by binary search
        front = 0; end = width - 1;
        mid = (front + end) / 2;
        while (front < end && target != matrix[row][mid]) {
            if (target < matrix[row][mid]) end = mid - 1;
            if (target > matrix[row][mid]) front = mid + 1;
            mid = (front + end) / 2;
        }
        col = mid;

        if (target == matrix[row][col]) result = true;
        return result;
    }
};
// @lc code=end


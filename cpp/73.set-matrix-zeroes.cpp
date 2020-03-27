/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 *
 * https://leetcode.com/problems/set-matrix-zeroes/description/
 *
 * algorithms
 * Medium (42.01%)
 * Likes:    1634
 * Dislikes: 272
 * Total Accepted:    276.9K
 * Total Submissions: 658.5K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * Given a m x n matrix, if an element is 0, set its entire row and column to
 * 0. Do it in-place.
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * [
 * [1,1,1],
 * [1,0,1],
 * [1,1,1]
 * ]
 * Output: 
 * [
 * [1,0,1],
 * [0,0,0],
 * [1,0,1]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 
 * [
 * [0,1,2,0],
 * [3,4,5,2],
 * [1,3,1,5]
 * ]
 * Output: 
 * [
 * [0,0,0,0],
 * [0,4,5,0],
 * [0,3,1,0]
 * ]
 * 
 * 
 * Follow up:
 * 
 * 
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best
 * solution.
 * Could you devise a constant space solution?
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int> > info;

        int height = matrix.size();
        int width = matrix[0].size();

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (0 == matrix[i][j]) {
                    info.push_back({i, j});
                }
            }
        }

        for (int i = 0; i < info.size(); i++) {
            int row = info[i][0];
            int col = info[i][1];
            for (int j = 0; j < height; j++) matrix[j][col] = 0;
            for (int j = 0; j < width; j++) matrix[row][j] = 0;
        }

        return;
    }
};
// @lc code=end


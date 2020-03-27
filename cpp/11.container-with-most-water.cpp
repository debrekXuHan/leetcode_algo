/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (49.00%)
 * Likes:    4967
 * Dislikes: 522
 * Total Accepted:    558.4K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * Given n non-negative integers a1, a2, ..., an , where each represents a
 * point at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
 * with x-axis forms a container, such that the container contains the most
 * water.
 * 
 * Note: You may not slant the container and n is at least 2.
 * 
 * 
 * 
 * 
 * 
 * The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In
 * this case, the max area of water (blue section) the container can contain is
 * 49. 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: [1,8,6,2,5,4,8,3,7]
 * Output: 49
 */

// @lc code=start
// This solution is not an efficient solution
class Solution {
public:
    int maxArea(vector<int>& height) {
        int num = height.size();
        int i = 0, j = 0;

        int max_area = 0, area = 0;

        for (i = 0; i < num - 1; i++) {
            for (j = i + 1; j < num; j++) {
                area = (j - i) * min(height[i], height[j]);
                if (area > max_area) max_area = area;
            }
        }

        return max_area;
    }
};

// The solution with O(n) complexity and more efficient
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;

        int max_area = 0;

        while (i < j) {
            max_area = max(max_area, (j - i) * min(height[i], height[j]));
            height[i] < height[j] ? i++ : j--;  // push the shorter side can probably achieve a larger area
        }

        return max_area;
    }
};
// @lc code=end


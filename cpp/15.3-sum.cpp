/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (25.73%)
 * Likes:    5705
 * Dislikes: 691
 * Total Accepted:    788.3K
 * Total Submissions: 3.1M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // sort the number array
        vector<vector<int>> result;

        // in case that the length of number array is shorter than 3
        if (nums.size() < 3) return result;

        int middle = 0, right = 0;
        int a = 0, b = 0;

        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] > 0) break;  // the sum any 3 numbers must greater than 0

            int target = -nums[i];
            middle = i + 1;
            right = nums.size() - 1;

            while (middle < right) {
                a = nums[middle];
                b = nums[right];
                if ((a + b) > target) {
                    right--;
                } else if ((a + b) < target) {
                    middle++;
                } else {
                    result.push_back({nums[i], a, b});
                    // deal with the repeating numbers for the middle number
                    while (middle < right && nums[middle] == a) middle++;
                    // deal with the repeating numbers for the right number
                    while (middle < right && nums[right] == b) right--;
                }
            }
            // deal with the repeating numbers for the left number
            while (i < nums.size() - 2 && nums[i + 1] == nums[i]) i++;
        }
        return result;
    }
};
// @lc code=end


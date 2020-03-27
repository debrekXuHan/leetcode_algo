/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (32.57%)
 * Likes:    1539
 * Dislikes: 290
 * Total Accepted:    298.6K
 * Total Submissions: 916.8K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers and an integer target, are there elements
 * a, b, c, and d in nums such that a + b + c + d = target? Find all unique
 * quadruplets in the array which gives the sum of target.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate quadruplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
 * 
 * A solution set is:
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if (nums.size() < 4) return result;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 3; i++) {
            int target_3 = target - nums[i];

            for (int j = i + 1; j < nums.size() - 2; j++) {
                int target_2 = target_3 - nums[j];

                int front = j + 1;
                int back = nums.size() - 1;

                while (front < back) {
                    int two_sum = nums[front] + nums[back];
                    if (two_sum > target_2) {
                        back--;
                    } else if (two_sum < target_2) {
                        front++;
                    } else {
                        vector<int> quad = {nums[i], nums[j], nums[front], nums[back]};
                        result.push_back(quad);

                        // deal with the repeating numbers for the third and fourth numbers
                        while ((front < back) && (nums[front] == quad[2])) front++;
                        while ((front < back) && (nums[back] == quad[3])) back--;
                    }
                }
                // deal with the repeating numbers for the second number
                while ((j < nums.size() - 2) && nums[j] == nums[j+1]) j++;
            }
            // deal with the repeating numbers for the first number
            while ((i < nums.size() - 2) && nums[i] == nums[i+1]) i++;
        }
        return result;
    }
};
// @lc code=end


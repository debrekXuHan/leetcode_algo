/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (45.72%)
 * Likes:    1664
 * Dislikes: 120
 * Total Accepted:    426.6K
 * Total Submissions: 933.2K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 * 
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 * 
 */

// @lc code=start
// The solution with the complexity of O(n^2)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3) {
            return accumulate(nums.begin(), nums.end(), 0);
        }

        sort(nums.begin(), nums.end());
        int sum = 0;
        int closest = nums[0] + nums[1] + nums[2];  // initialize the closest sum

        int first = 0, second = 0, third = 0;

        for (first = 0; first < nums.size() - 2; first++) {
            second = first + 1;
            third = nums.size() - 1;

            while (second < third) {
                sum = nums[first] + nums[second] + nums[third];
                if (sum == target) return target;

                if (abs(sum - target) < abs(closest - target)) {
                    closest = sum;
                }

                if (sum > target) {
                    third--;
                } else {
                    second++;
                }
            }
        }
        return closest;
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 *
 * https://leetcode.com/problems/jump-game/description/
 *
 * algorithms
 * Medium (33.23%)
 * Likes:    3083
 * Dislikes: 278
 * Total Accepted:    366.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that
 * position.
 * 
 * Determine if you are able to reach the last index.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,1,1,4]
 * Output: true
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last
 * index.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,1,0,4]
 * Output: false
 * Explanation: You will always arrive at index 3 no matter what. Its
 * maximum
 * jump length is 0, which makes it impossible to reach the last index.
 * 
 * 
 */

// @lc code=start
// a better solution
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        int step = nums[0];

        for (int i = 1; i < size; i++) {
            step--;
            if (step < 0) {
                return false;
            }
            // it can reach further by the jump length on current index
            if (nums[i] > step) {
                step = nums[i];
            }
        }
        return true;
    }
};

// recursive solution. maybe not so efficient
class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool result = false;
        result = reachLast(nums, 0);
        return result;
    }

    bool reachLast(vector<int>& nums, int pos) {
        // if it can reach the end, return TRUE
        if (pos + nums[pos] >= nums.size() - 1) {
            return true;
        }

        bool res = false;
        for (int i = 1; i <= nums[pos]; i++) {
            res = reachLast(nums, pos + i);
            if (res) break;
        }
        return res;
    }
};
// @lc code=end


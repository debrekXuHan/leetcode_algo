/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (35.11%)
 * Likes:    2654
 * Dislikes: 118
 * Total Accepted:    426.2K
 * Total Submissions: 1.2M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * If the target is not found in the array, return [-1, -1].
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        int l = 0, r = nums.size() - 1;
        int start = -1, end = -1;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (target == nums[mid]) {  // middle element equals to the target and then expand
                start = mid; end = mid;
                while (target == nums[start]) {
                    start--;
                    if (start < 0) break;
                }
                while (target == nums[end]) {
                    end++;
                    if (end > nums.size() - 1) break;
                }
                start += 1;
                end -= 1;
                break;
            }

            // binary search
            if (target > nums[mid]) {
                l = mid + 1;
            }
            if (target < nums[mid]) {
                r = mid - 1;
            }
        }
        result.push_back(start);
        result.push_back(end);
        return result;
    }
};
// @lc code=end


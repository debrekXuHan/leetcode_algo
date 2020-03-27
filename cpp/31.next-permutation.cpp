/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (31.81%)
 * Likes:    2764
 * Dislikes: 948
 * Total Accepted:    322.2K
 * Total Submissions: 1M
 * Testcase Example:  '[1,2,3]'
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 * 
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 * 
 * The replacement must be in-place and use only constant extra memory.
 * 
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 * 
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();

        int i = 0, flag = 0, k = len - 1;
        int tmp = 0;
        // find the largest index "flag" that nums[flag-1] < num[flag]
        for (i = len - 1; i >= 0; i--) {
            if (0 == i) {  // if the vector is in descending order, simply reverse it
                reverse(nums.begin(), nums.end());
                return;
            }
            if (nums[i] > nums[i - 1]) break;
        }
        flag = i;

        // nums[i] ~ nums[len-1] is in descending order and reverse them
        while (i < k) {
            tmp = nums[i];
            nums[i] = nums[k];
            nums[k] = tmp;

            i++; k--;
        }

        // find the smallest number from nums[flag] to nums[len-1] that is larger than
        // nums[flag] and swap the two numbers
        for (i = flag; i < len; i++) {
            while (nums[flag - 1] < nums[i]) {
                tmp = nums[flag - 1];
                nums[flag - 1] = nums[i];
                nums[i] = tmp;
                return;
            }
        }
    }
};
// @lc code=end


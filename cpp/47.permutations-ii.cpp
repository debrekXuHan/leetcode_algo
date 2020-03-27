/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (44.28%)
 * Likes:    1578
 * Dislikes: 56
 * Total Accepted:    313.4K
 * Total Submissions: 707.8K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,1,2]
 * Output:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        permutation(nums, result, 0);
        return result;
    }

    void permutation(vector<int> nums, vector<vector<int>> &res, int begin) {
        if (begin >= nums.size()) {
            res.push_back(nums);
            return;
        }

        for (int i = begin; i < nums.size(); i++) {
            if ((i == begin) || (nums[i] != nums[begin])) {  // skip the repeating numbers
                swap(nums[begin], nums[i]);
                permutation(nums, res, begin + 1);
            }
        }
        return;
    }
};
// @lc code=end


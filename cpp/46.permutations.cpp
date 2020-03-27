/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (60.40%)
 * Likes:    3111
 * Dislikes: 94
 * Total Accepted:    520.7K
 * Total Submissions: 862.2K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        permutation(nums, result, 0);
        return result;
    }

    // the recursive function
    // here nums is a reference
    void permutation(vector<int> &nums, vector<vector<int>> &result, int begin) {
        if (begin >= nums.size()) {
            result.push_back(nums);
            return;
        }

        for (int i = begin; i < nums.size(); i++) {
            swap(nums[begin], nums[i]);  // swap function to re-arrange the array
            permutation(nums, result, begin + 1);
            // reset before the next iteration
            swap(nums[begin], nums[i]);
        }
        return;
    }
};

// another solution
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        permutation(nums, result, 0);
        return result;
    }

    // the recursive function
    // here "nums" is not a reference
    void permutation(vector<int> nums, vector<vector<int>> &result, int begin) {
        if (begin >= nums.size()) {
            result.push_back(nums);
            return;
        }

        for (int i = begin; i < nums.size(); i++) {
            swap(nums[begin], nums[i]);  // swap function to re-arrange the array
            permutation(nums, result, begin + 1);
        }
        return;
    }
};
// @lc code=end


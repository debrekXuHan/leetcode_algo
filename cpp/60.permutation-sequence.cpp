/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 *
 * https://leetcode.com/problems/permutation-sequence/description/
 *
 * algorithms
 * Medium (35.33%)
 * Likes:    1187
 * Dislikes: 287
 * Total Accepted:    165.5K
 * Total Submissions: 468.5K
 * Testcase Example:  '3\n3'
 *
 * The set [1,2,3,...,n] contains a total of n! unique permutations.
 * 
 * By listing and labeling all of the permutations in order, we get the
 * following sequence for n = 3:
 * 
 * 
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * 
 * 
 * Given n and k, return the k^th permutation sequence.
 * 
 * Note:
 * 
 * 
 * Given n will be between 1 and 9 inclusive.
 * Given k will be between 1 and n! inclusive.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3, k = 3
 * Output: "213"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 4, k = 9
 * Output: "2314"
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string getPermutation(int n, int k) {
        string result(n, '0');

        int num = 1;
        // init the result to "1234..."
        for (int i = 1; i <= n; i++) {
            num *= i;
            result[i - 1] = '0' + i;
        }

        k -= 1;
        for (int i = 0; i < n - 1; i++) {
            num /= (n - i);
            int idx = i + k / num;
            char select = result[idx];

            // re-organize the rest digits by removing the selected digit
            for (; idx > i; idx--) {
                result[idx] = result[idx - 1];
            }
            result[i] = select;
            k = k % num;
        }
        return result;
    }
};
// @lc code=end


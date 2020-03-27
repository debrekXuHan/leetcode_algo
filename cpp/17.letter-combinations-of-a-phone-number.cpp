/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (44.91%)
 * Likes:    3206
 * Dislikes: 368
 * Total Accepted:    531.2K
 * Total Submissions: 1.2M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * Note:
 * 
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> list = {"", "", "abc", "def",
                               "ghi", "jkl", "mno",
                               "pqrs", "tuv", "wxyz"};
        vector<string> result;
        if (0 == digits.size()) return result;

        result = {""};
        for (int i = 0; i < digits.size(); i++) {
            string letters = list[digits[i] - '0'];

            vector<string> tmp;
            for (int j = 0; j < letters.size();j++) {
                for (int k = 0; k < result.size(); k++) {
                    tmp.push_back(result[k] + letters[j]);
                }
            }
            result = tmp;
        }
        return result;
    }
};
// @lc code=end


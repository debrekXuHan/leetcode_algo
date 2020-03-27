/*
 * @lc app=leetcode id=3 lang=c
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (29.61%)
 * Likes:    7909
 * Dislikes: 473
 * Total Accepted:    1.3M
 * Total Submissions: 4.6M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start


int lengthOfLongestSubstring(char * s){
    int idx[128] = {};  // based on ASCII
    int res = 0, left = 0;
    int i = 1;
    char *ps = s;

    while (*ps) {
        int index = *ps;

        // deal with the repeating letters
        if (0 != idx[index] && idx[index] > left) {
            left = idx[index];
        }

        idx[index] = i;

        if ((i - left) > res) {
            res = i - left;
        }
        i++;
        ps++;
    }
    return res;
}


// @lc code=end


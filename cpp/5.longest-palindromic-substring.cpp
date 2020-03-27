/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (28.78%)
 * Likes:    5615
 * Dislikes: 474
 * Total Accepted:    813.5K
 * Total Submissions: 2.8M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 *
 * Example 1:
 *
 *
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 *
 *
 * Example 2:
 *
 *
 * Input: "cbbd"
 * Output: "bb"
 *
 *
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if (len <= 1)
            return s;
        int left = 0, right = 0, max_right = len - 1;
        int max_len = 1, sub_len = 0, lpos = 0;

        for(int i = 0; i < len;) {
            left  = i;
            right = i;

            // determine the right position
            while (right < max_right && s[right + 1] == s[right]) {
                right = right + 1;
            }
            i = right + 1;  // it can save runtime (comparing with i++)

            // determine the palindromic substring
            while (left > 0 && right < max_right && s[left - 1] == s[right + 1]) {
                left--;
                right++;
            }

            sub_len = right - left + 1;
            if (sub_len > max_len) {
                lpos = left;
                max_len = sub_len;
            }
        }
        return s.substr(lpos, max_len);
    }
};
// @lc code=end


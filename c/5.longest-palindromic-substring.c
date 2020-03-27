/*
 * @lc app=leetcode id=5 lang=c
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


char * longestPalindrome(char * s){
    char *ps = s;
    // calculate the string length
    int len = 0;
    while (*ps) {
        len++;
        ps++;
    }
    if (1 == len) return s;

    int left = 0, right = 0, max_right = len - 1;
    int l_pos = 0, max_len = 0;

    for (int i = 0; i < len; i++) {
        left = i; right = i;
        // determine the right position, skip the repeating letters
        while (right < max_right && s[right + 1] == s[right]) {
            right++;
        }

        // determine the palindromic substring
        while (left > 0 && right < max_right && s[left - 1] == s[right + 1]) {
            left--; right++;
        }

        int cur_len = right - left + 1;
        if (cur_len > max_len) {
            max_len = cur_len;
            l_pos = left;
        }
    }
    char *res = (char *)malloc(sizeof(char) * max_len + 1);
    for (int i = 0; i < max_len; i++) {
        res[i] = s[i + l_pos];
    }
    res[max_len] = '\0';  // end of a string
    return res;
}


// @lc code=end


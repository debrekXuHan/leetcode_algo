/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0, left = -1, n = s.size();
        unordered_map<int, int> m;  // a map from the letters to the last appearance position

        for (int i = 0; i < n; i++) {
            if (m.count(s[i]) && m[s[i]] > left) {  // no repeating letters in the substring
                left = m[s[i]];
            }
            m[s[i]] = i;
            res = max(res, i - left);  // pick out the longest substring
        }

        return res;
    }
};
// @lc code=end


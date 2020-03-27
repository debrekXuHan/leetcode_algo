/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (34.80%)
 * Likes:    1421
 * Dislikes: 4120
 * Total Accepted:    414.4K
 * Total Submissions: 1.2M
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 *
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 *
 *
 * And then read line by line: "PAHNAPLSIIGYIR"
 *
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 *
 *
 * string convert(string s, int numRows);
 *
 * Example 1:
 *
 *
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 *
 *
 * Example 2:
 *
 *
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 *
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 *
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.size(), pos = 0;
        string result = "";

        // if numRows is 1, directly return the input string
        if (1 == numRows) {
            return s;
        }

        for (int i = 0; i < numRows; i++) {  // iteration by the number of rows
            pos = i;
            if (i == 0 || i == numRows - 1) {  // the first and the last row
                while (pos < len) {
                    result += s[pos];
                    pos += (2 * numRows - 2);
                }
            } else {  // the middle rows
                while (pos < len) {
                    result += s[pos];
                    if ((pos + 2 * (numRows - i - 1)) < len) {
                        result += s[pos + 2 * (numRows - i - 1)];
                    }
                    pos += (2 * numRows - 2);
                }
            }
        }
        return result;
    }
};
// @lc code=end


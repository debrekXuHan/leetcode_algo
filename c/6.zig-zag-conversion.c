/*
 * @lc app=leetcode id=6 lang=c
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


char * convert(char * s, int numRows){
    char *pS = s;
    if (1 == numRows) return s;

    // calculation the string length
    int len = 0;
    while (*pS) {
        len++;
        pS++;
    }
    char *pRes = (char *)malloc(sizeof(char) * len + 1);
    int k = 0, pos = 0;

    // iteration by numRows
    for (int i = 0; i < numRows; i++) {
        pos = i;
        if (0 == i || (numRows - 1) == i) {  // the first and the last rows
            while (pos < len) {
                pRes[k++] = s[pos];
                pos += (2 * numRows - 2);
            }
        } else {  // the middle rows
            while (pos < len) {
                pRes[k++] = s[pos];
                if ((pos + 2 * (numRows - i - 1)) < len) {
                    pRes[k++] = s[pos + 2 * (numRows - i - 1)];
                }
                pos += (2 * numRows - 2);
            }
        }
    }
    pRes[len] = '\0';
    return pRes;
}


// @lc code=end


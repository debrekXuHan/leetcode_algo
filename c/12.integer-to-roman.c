/*
 * @lc app=leetcode id=12 lang=c
 *
 * [12] Integer to Roman
 *
 * https://leetcode.com/problems/integer-to-roman/description/
 *
 * algorithms
 * Medium (53.64%)
 * Likes:    860
 * Dislikes: 2412
 * Total Accepted:    314.6K
 * Total Submissions: 586.5K
 * Testcase Example:  '3'
 *
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D
 * and M.
 * 
 * 
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * 
 * For example, two is written as II in Roman numeral, just two one's added
 * together. Twelve is written as, XII, which is simply X + II. The number
 * twenty seven is written as XXVII, which is XX + V + II.
 * 
 * Roman numerals are usually written largest to smallest from left to right.
 * However, the numeral for four is not IIII. Instead, the number four is
 * written as IV. Because the one is before the five we subtract it making
 * four. The same principle applies to the number nine, which is written as IX.
 * There are six instances where subtraction is used:
 * 
 * 
 * I can be placed before V (5) and X (10) to make 4 and 9. 
 * X can be placed before L (50) and C (100) to make 40 and 90. 
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 * 
 * 
 * Given an integer, convert it to a roman numeral. Input is guaranteed to be
 * within the range from 1 to 3999.
 * 
 * Example 1:
 * 
 * 
 * Input: 3
 * Output: "III"
 * 
 * Example 2:
 * 
 * 
 * Input: 4
 * Output: "IV"
 * 
 * Example 3:
 * 
 * 
 * Input: 9
 * Output: "IX"
 * 
 * Example 4:
 * 
 * 
 * Input: 58
 * Output: "LVIII"
 * Explanation: L = 50, V = 5, III = 3.
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: 1994
 * Output: "MCMXCIV"
 * Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 * 
 */

// @lc code=start


char * intToRoman(int num){
    char *pList[4][10] = {
        {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
        {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
        {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
        {"", "M", "MM", "MMM"}
    };

    char *pRes = (char *)malloc(sizeof(char) * 20);
    char *pTmp = pRes;

    if (num / 1000) {
        int digit = num / 1000;
        char *pPick = pList[3][digit];
        while (*pPick) {
            *pTmp = *pPick;
            pTmp++; pPick++;
        }
        num = num % 1000;
    }
    if (num / 100) {
        int digit = num / 100;
        char *pPick = pList[2][digit];
        while (*pPick) {
            *pTmp = *pPick;
            pTmp++; pPick++;
        }
        num = num % 100;
    }
    if (num / 10) {
        int digit = num / 10;
        char *pPick = pList[1][digit];
        while (*pPick) {
            *pTmp = *pPick;
            pTmp++; pPick++;
        }
        num = num % 10;
    }
    if (num) {
        char *pPick = pList[0][num];
        while (*pPick) {
            *pTmp = *pPick;
            pTmp++; pPick++;
        }
    }
    *pTmp = '\0';
    return pRes;
}


// @lc code=end


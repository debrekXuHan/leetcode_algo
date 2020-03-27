/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 *
 * https://leetcode.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (29.09%)
 * Likes:    1183
 * Dislikes: 2669
 * Total Accepted:    411.5K
 * Total Submissions: 1.4M
 * Testcase Example:  '2.00000\n10'
 *
 * Implement pow(x, n), which calculates x raised to the power n (x^n).
 * 
 * Example 1:
 * 
 * 
 * Input: 2.00000, 10
 * Output: 1024.00000
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 2.10000, 3
 * Output: 9.26100
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 2.00000, -2
 * Output: 0.25000
 * Explanation: 2^-2 = 1/2^2 = 1/4 = 0.25
 * 
 * 
 * Note:
 * 
 * 
 * -100.0 < x < 100.0
 * n is a 32-bit signed integer, within the range [−2^31, 2^31 − 1]
 * 
 * 
 */

// @lc code=start
// do not directly use pow() function here
class Solution {
public:
    double myPow(double x, int n) {
        if (0 == n) return 1;
        double res = myPow(x, n / 2);
        return (n % 2 == 0) ? res * res : n < 0 ? (1 / x) * res * res : x * res * res;
    }
};

// Wrong Answer
class Solution {
public:
    double myPow(double x, int n) {
        if (0 == n) return 1;
        if (n < 0) {
            n = -n; // if n = -2147483648, -n is overflow
            x = 1 / x;
        }
        return (n % 2 == 0) ? myPow(x * x, n / 2) : x * myPow(x * x, n / 2);
    }
};
// @lc code=end


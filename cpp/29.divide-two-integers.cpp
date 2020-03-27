/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 *
 * https://leetcode.com/problems/divide-two-integers/description/
 *
 * algorithms
 * Medium (16.18%)
 * Likes:    936
 * Dislikes: 4572
 * Total Accepted:    246.9K
 * Total Submissions: 1.5M
 * Testcase Example:  '10\n3'
 *
 * Given two integers dividend and divisor, divide two integers without using
 * multiplication, division and mod operator.
 * 
 * Return the quotient after dividing dividend by divisor.
 * 
 * The integer division should truncate toward zero.
 * 
 * Example 1:
 * 
 * 
 * Input: dividend = 10, divisor = 3
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: dividend = 7, divisor = -3
 * Output: -2
 * 
 * Note:
 * 
 * 
 * Both dividend and divisor will be 32-bit signed integers.
 * The divisor will never be 0.
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
 * of this problem, assume that your function returns 2^31 − 1 when the
 * division result overflows.
 * 
 * 
 */

// @lc code=start
// Wrong solution. Should use a bit-idea solution
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        long result = dividend / divisor;

        if (result > INT_MAX) return INT_MAX;
        if (result < INT_MIN) return INT_MIN;

        return result;
    }
};

// the environment can only store 32-bit signed integers
// This solution works for some certain C++ compiler.
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        int a = abs(dividend), b = abs(divisor);
        int result = 0, x = 0;

        while (a - b >= 0) {
            for (x = 0; a - (b << x << 1) >= 0; x++);
            result += 1 << x;
            a -= b << x;
        }

        return (dividend > 0) == (divisor > 0) ? result : -result;
    }
};

// This solution works for the new Leetcode compiler.
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        long a = abs(long(dividend)), b = abs(long(divisor));
        long result = 0;
        int x = 0;

        while (a - b >= 0) {
            for (x = 0; a - (b << x << 1) >= 0; x++);
            result += 1 << x;
            a -= b << x;
        }

        return (dividend > 0) == (divisor > 0) ? result : -result;
    }
};
// @lc code=end


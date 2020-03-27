/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (32.69%)
 * Likes:    1462
 * Dislikes: 672
 * Total Accepted:    259.6K
 * Total Submissions: 794.3K
 * Testcase Example:  '"2"\n"3"'
 *
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2, also represented as a string.
 * 
 * Example 1:
 * 
 * 
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 * 
 * Example 2:
 * 
 * 
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 * 
 * 
 * Note:
 * 
 * 
 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contain only digits 0-9.
 * Both num1 and num2 do not contain any leading zero, except the number 0
 * itself.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */

// @lc code=start
// better solution
class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size(), len2 = num2.size();
        // init the result, the max length is len1 + len2
        string result(len1 + len2, '0');

        for (int i = len1 - 1; i >= 0; i--) {
            int carry = 0;
            for (int j = len2 - 1; j >= 0; j--) {
                // sum operation on the corresponding digits
                int sum = (result[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
                carry = sum / 10;
                result[i + j + 1] = '0' + (sum % 10);
            }
            result[i] += carry;
        }

        int flag = result.find_first_not_of('0');
        if (flag >= 0) {
            return result.substr(flag);
        }
        return "0";
    }
};


// my solution
class Solution {
public:
    string multiply(string num1, string num2) {
        string result = "";
        // directly return "0" if there is a zero number in these two numbers
        if (num1 == "0" || num2 == "0") {
            result = "0";
            return result;
        }

        int len1 = num1.size(), len2 = num2.size();
        int flag = 0;
        string sum = "";

        for (int i = len1 - 1; i >= 0; i--) {
            string cur = "";
            int carry = 0;
            for (int k = flag; k > 0; k--) cur += '0';  // fill with '0's for some certain digits
            for (int j = len2 - 1; j >= 0; j--) {
                int mul = (num2[j] - '0') * (num1[i] - '0') + carry;
                carry = mul / 10;
                cur += ('0' + (mul % 10));
            }
            if (carry) cur += ('0' + carry);  // if there is a carry number for the last digit
            sum = add(sum, cur);
            flag++;
        }

        // reverse the string and give out the result
        for (int i = sum.size() - 1; i >= 0; i--) {
            result += sum[i];
        }
        return result;
    }

    string add(string num1, string num2) {
        int max_len = max(num1.size(), num2.size());
        string res = "";
        int carry = 0;

        for (int i = 0; i < max_len; i++) {
            int n1 = i < num1.size() ? num1[i] - '0' : 0;
            int n2 = i < num2.size() ? num2[i] - '0' : 0;
            int sum = n1 + n2 + carry;
            carry = sum / 10;
            res += ('0' + (sum % 10));
        }
        if (carry) res += ('0' + carry);
        return res;
    }
};
// @lc code=end


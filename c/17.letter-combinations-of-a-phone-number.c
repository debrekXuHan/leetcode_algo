/*
 * @lc app=leetcode id=17 lang=c
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (44.91%)
 * Likes:    3206
 * Dislikes: 368
 * Total Accepted:    531.2K
 * Total Submissions: 1.2M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * Note:
 * 
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** letterCombinations(char * digits, int* returnSize){
    char *array[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int  choices[10] = {0, 0, 3, 3, 3, 3, 3, 4, 3, 4};

    char *pDigits = digits;
    int len = 0, size = 1;
    while (*pDigits) {
        if (0 == choices[*pDigits - '0']) {  // inpput array with "0" or "1"
            len = 0; break;
        }
        size *= choices[*pDigits - '0'];
        pDigits++; len++;
    }

    // empty input array or array with "0" or "1"
    if (!len) {
        *returnSize = 0;
        return NULL;
    }

    int res_size = size, cur_size = size;
    *returnSize = res_size;
    char **pRet = (char **)malloc(sizeof(char *) * res_size);
    for (int i = 0; i < size; i++) {
        pRet[i] = (char *)malloc(sizeof(char) * (len + 1));
    }

    pDigits = digits;
    int index = 0;
    while (*pDigits) {
        cur_size /= choices[*pDigits - '0'];
        char *pArray = array[*pDigits - '0'];
        for (int i = 0; i < size; i++) {
            pRet[i][index] = pArray[(i / cur_size) % choices[*pDigits - '0']];
        }
        pDigits++; index++;
    }
    for (int i = 0; i < size; i++) {
        pRet[i][index] = '\0';
    }
    return pRet;
}
// @lc code=end
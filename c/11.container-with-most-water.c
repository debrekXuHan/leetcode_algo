/*
 * @lc app=leetcode id=11 lang=c
 *
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (49.00%)
 * Likes:    4967
 * Dislikes: 522
 * Total Accepted:    558.4K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * Given n non-negative integers a1, a2, ..., an , where each represents a
 * point at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
 * with x-axis forms a container, such that the container contains the most
 * water.
 * 
 * Note: You may not slant the container and n is at least 2.
 * 
 * 
 * 
 * 
 * 
 * The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In
 * this case, the max area of water (blue section) the container can contain is
 * 49. 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: [1,8,6,2,5,4,8,3,7]
 * Output: 49
 */

// @lc code=start


int maxArea(int* height, int heightSize){
    int *pHead = height;
    int *pRear = height + heightSize - 1;

    int maxRes = 0;
    int minHeight = 0, area = 0;
    while (pHead < pRear) {
        // determine the min height between two sides
        if (*pHead < *pRear) {
            minHeight = *pHead;
        } else {
            minHeight = *pRear;
        }

        area = minHeight * (pRear - pHead);
        if (area > maxRes) {
            maxRes = area;
        }

        if (*pHead < *pRear) {
            pHead++;
        } else {
            pRear--;
        }
    }
    return maxRes;
}


// @lc code=end


/*
 * @lc app=leetcode id=15 lang=c
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (25.73%)
 * Likes:    5705
 * Dislikes: 691
 * Total Accepted:    788.3K
 * Total Submissions: 3.1M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
// Bubble sorting
void sort(int *nums, int numsSize) {
    if (numsSize <= 1) return;

    int *pNums = nums;
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = 1; j < numsSize - i; j++) {
            if (nums[j - 1] > nums[j]) {
                int tmp = nums[j - 1];
                nums[j - 1] = nums[j];
                nums[j] = tmp;
            }
        }
    }
    return;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    // init parameters
    *returnSize = 0;
    if (numsSize < 3 || NULL == nums) return NULL;

    int base_alloc_size = 16;
    int **pRes = (int **)malloc(sizeof(int *) * base_alloc_size);;
    *returnColumnSizes = (int *)malloc(sizeof(int) * base_alloc_size);

    sort(nums, numsSize);

    int left = 0, right = 0;
    int i = 0, sum = 0;

    for (int i = 0; i < numsSize - 2; i++) {
        if (nums[i] > 0) break;

        // skip the repeating numbers
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        left = i + 1;
        right = numsSize - 1;
        while (left < right) {
            sum = nums[i] + nums[left] + nums[right];
            if (sum > 0) {
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                pRes[*returnSize] = (int *)malloc(sizeof(int) * 3);
                pRes[*returnSize][0] = nums[i];
                pRes[*returnSize][1] = nums[left];
                pRes[*returnSize][2] = nums[right];

                (*returnColumnSizes)[*returnSize] = 3;

                *returnSize += 1;

                while ((left < right) && (nums[left] == nums[left + 1])) left++;
                while ((left < right) && (nums[right] == nums[right - 1])) right--;
                left++; right--;
            }

            // enlarge the allocated memory
            if (*returnSize == base_alloc_size) {
                base_alloc_size *= 2;
                pRes = (int **)realloc(pRes, sizeof(int *) * base_alloc_size);
                (*returnColumnSizes) = (int *)realloc((*returnColumnSizes), sizeof(int) * base_alloc_size);
            }
        }
    }

    return pRes;
}
// @lc code=end
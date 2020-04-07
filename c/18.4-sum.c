/*
 * @lc app=leetcode id=18 lang=c
 *
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (32.57%)
 * Likes:    1539
 * Dislikes: 290
 * Total Accepted:    298.6K
 * Total Submissions: 916.8K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers and an integer target, are there elements
 * a, b, c, and d in nums such that a + b + c + d = target? Find all unique
 * quadruplets in the array which gives the sum of target.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate quadruplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
 * 
 * A solution set is:
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
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

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if (numsSize < 4 || NULL == nums) return NULL;

    // sort the array
    sort(nums, numsSize);
    int base_alloc_size = 16;
    int **pRes = (int **)malloc(sizeof(int *) * base_alloc_size);;
    *returnColumnSizes = (int *)malloc(sizeof(int) * base_alloc_size);

    for (int i = 0; i < numsSize - 3; i++) {
        int target_3 = target - nums[i];
        for (int j = i + 1; j < numsSize - 2; j++) {
            int target_2 = target_3 - nums[j];

            int front = j + 1;
            int back = numsSize - 1;
            while (front < back) {
                int sum_2 = nums[front] + nums[back];
                if (sum_2 > target_2) {
                    back--;
                } else if (sum_2 < target_2) {
                    front++;
                } else {
                    int *target_combine = (int *)malloc(sizeof(int) * 4);
                    target_combine[0] = nums[i];
                    target_combine[1] = nums[j];
                    target_combine[2] = nums[front];
                    target_combine[3] = nums[back];
                    pRes[*returnSize] = target_combine;

                    (*returnColumnSizes)[*returnSize] = 4;
                    *returnSize += 1;
                    while ((front < back) && (nums[front] == nums[front + 1])) front++;
                    while ((front < back) && (nums[back] == nums[back - 1])) back--;
                    front++; back--;
                }
                // enlarge the allocated memory
                if (*returnSize == base_alloc_size) {
                    base_alloc_size *= 2;
                    pRes = (int **)realloc(pRes, sizeof(int *) * base_alloc_size);
                    (*returnColumnSizes) = (int *)realloc((*returnColumnSizes), sizeof(int) * base_alloc_size);
                }
            }
            while (j < numsSize - 2 && nums[j] == nums[j + 1]) j++;
        }
        while (i < numsSize - 3 && nums[i] == nums[i + 1]) i++;
    }
    return pRes;
}
// @lc code=end
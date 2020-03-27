/*
 * @lc app=leetcode id=16 lang=c
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (45.72%)
 * Likes:    1664
 * Dislikes: 120
 * Total Accepted:    426.6K
 * Total Submissions: 933.2K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 * 
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 * 
 */

// @lc code=start

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

// calculate absolute value
int calcAbs(int num) {
    return num >= 0 ? num : -num;
}

int threeSumClosest(int* nums, int numsSize, int target){
    int resSum = 0;
    if (numsSize < 3) {
        for (int i = 0; i < numsSize; i++) {
            resSum += nums[i];
        }
        return resSum;
    }

    // sorting the array
    sort(nums, numsSize);

    int first = 0, second = 0, third = 0;
    int sum = 0;
    resSum = nums[0] + nums[1] + nums[2];
    for (first = 0; first < numsSize - 2; first++) {
        second = first + 1;
        third = numsSize - 1;

        while (second < third) {
            sum = nums[first] + nums[second] + nums[third];
            if (sum == target) return target;

            if (calcAbs(sum - target) < calcAbs(resSum - target)) {
                resSum = sum;
            }
            if (sum > target) {
                third--;
            } else {
                second++;
            }
        }
    }
    return resSum;
}


// @lc code=end


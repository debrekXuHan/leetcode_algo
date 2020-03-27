/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
 *
 * https://leetcode.com/problems/rotate-list/description/
 *
 * algorithms
 * Medium (28.94%)
 * Likes:    916
 * Dislikes: 955
 * Total Accepted:    242.3K
 * Total Submissions: 837.1K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, rotate the list to the right by k places, where k is
 * non-negative.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2->3->4->5->NULL, k = 2
 * Output: 4->5->1->2->3->NULL
 * Explanation:
 * rotate 1 steps to the right: 5->1->2->3->4->NULL
 * rotate 2 steps to the right: 4->5->1->2->3->NULL
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 0->1->2->NULL, k = 4
 * Output: 2->0->1->NULL
 * Explanation:
 * rotate 1 steps to the right: 2->0->1->NULL
 * rotate 2 steps to the right: 1->2->0->NULL
 * rotate 3 steps to the right: 0->1->2->NULL
 * rotate 4 steps to the right: 2->0->1->NULL
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (NULL == head) return NULL;
        ListNode *tmp = head;
        // count the node numbers
        int count = 1;
        while (tmp->next) {
            count++;
            tmp = tmp->next;
        }
        ListNode *rear = tmp;

        k = k % count;
        if (0 == k) return head;  // return the original list

        // split into 2 sub-lists from the des position
        // put the back sub-list to the front
        int des = count - k;
        count = 1; tmp = head;
        while (count < des) {
            tmp = tmp->next;
            count++;
        }
        ListNode *res = tmp->next;
        tmp->next = NULL;
        rear->next = head;

        return res;
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=2 lang=c
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (32.83%)
 * Likes:    7174
 * Dislikes: 1858
 * Total Accepted:    1.2M
 * Total Submissions: 3.8M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example:
 * 
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *p1 = l1, *p2 =l2;
    struct ListNode *res = (struct ListNode *)malloc(sizeof(struct ListNode));
    res->val = 0;
    res->next = NULL;

    int carry = 0;
    struct ListNode *p = NULL;
    while (p1 || p2 || carry) {
        if (NULL == p) {
            p = res;
        } else {
            p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
            p = p->next;
            p->val = 0;
            p->next = NULL;
        }

        int val1 = p1 ? p1->val : 0;
        int val2 = p2 ? p2->val : 0;

        int sum = val1 + val2 + carry;
        p->val = sum % 10;
        carry = sum / 10;

        p1 = p1 ? p1->next : NULL;
        p2 = p2 ? p2->next : NULL;
    }
    return res;
}
// @lc code=end


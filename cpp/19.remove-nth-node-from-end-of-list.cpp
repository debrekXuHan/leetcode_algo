/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (34.80%)
 * Likes:    2664
 * Dislikes: 192
 * Total Accepted:    535K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, remove the n-th node from the end of list and return
 * its head.
 * 
 * Example:
 * 
 * 
 * Given linked list: 1->2->3->4->5, and n = 2.
 * 
 * After removing the second node from the end, the linked list becomes
 * 1->2->3->5.
 * 
 * 
 * Note:
 * 
 * Given n will always be valid.
 * 
 * Follow up:
 * 
 * Could you do this in one pass?
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *t1 = head, *t2 = head;
        // use t2 as a flag to find the Nth position
        for (int i = 0; i < n; i++) {
            t2 = t2->next;
        }

        // the first node is removed
        if (NULL == t2) {
            head = head->next;
            return head;
        }

        // t1 points to the Nth node from the end while t2 points to the end
        while (t2->next != NULL) {
            t2 = t2->next;
            t1 = t1->next;
        }

        // skip the Nth node
        t1->next = t1->next->next;
        return head;
    }
};
// @lc code=end


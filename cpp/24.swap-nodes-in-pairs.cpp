/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (48.36%)
 * Likes:    1786
 * Dislikes: 152
 * Total Accepted:    414.1K
 * Total Submissions: 856.2K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 * 
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 * 
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
    ListNode* swapPairs(ListNode* head) {
        ListNode *prev = new ListNode(0);
        prev->next = head;

        ListNode *t1 = prev, *t2 = head;
        while (t2 != NULL) {
            if (t2->next == NULL) break;

            // swap two ListNodes
            t1->next = t2->next;
            t2->next = t1->next->next;
            t1->next->next = t2;

            // move the pointers forward
            t1 = t2;
            t2 = t2->next;
        }

        return prev->next;
    }
};
// @lc code=end


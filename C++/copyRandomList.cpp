// Time Complexity: O(n)
// Space Complexity: O(1)

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
    public:
        RandomListNode *copyRandomList(RandomListNode *head) {
            // insert the copied node after the original one
            for(RandomListNode *cur = head; cur; cur = cur->next->next) {
                RandomListNode *node = new RandomListNode(cur->label);
                node->next = cur->next;
                cur->next = node;
            }

            // update random node
            for(RandomListNode *cur = head; cur; cur = cur->next->next) {
                if(cur->random) {
                    cur->next->random = cur->random->next;
                }
            }

            // seperate the copied nodes from original ones
            RandomListNode dummy(INT_MIN);
            for( RandomListNode *cur = head, *copy_cur = &dummy; 
                    cur;
                    copy_cur = copy_cur->next, cur = cur->next) {
                copy_cur->next = cur->next;
                cur->next = cur->next->next;
            }

            return dummy.next;
        }
};

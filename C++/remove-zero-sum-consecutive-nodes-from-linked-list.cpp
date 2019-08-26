// Time:  O(n)
// Space: O(n)

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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode dummy(0);
        auto curr = &dummy;
        dummy.next = head;
        int prefix = 0;
        OrderedDict<int, ListNode*> lookup;
        while (curr) {
            prefix += curr->val;
            auto node = curr;
            if (lookup.count(prefix)) {
                node = lookup[prefix];
            }
            while (lookup.count(prefix)) {
                lookup.popitem();
            }
            lookup[prefix] = node;
            node->next = curr->next;
            curr = curr->next;
        }
        return dummy.next;
    }

private:
    template<typename K, typename V>
    class OrderedDict {
    public:
        bool count(const K& key) const {
            return map_.count(key);
        }
        
        V& operator[](const K& key) {
            if (!map_.count(key)) {
                list_.emplace_front();
                list_.begin()->first = key;
                map_[key] = list_.begin();
            }
            return map_[key]->second;
        }

        void popitem() {
            auto del = list_.front(); list_.pop_front();
            map_.erase(del.first);
        }
    
    private:
        list<pair<K, V>> list_;
        unordered_map<K, typename list<pair<K, V>>::iterator> map_;
    };
};

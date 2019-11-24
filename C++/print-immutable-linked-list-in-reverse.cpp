// Time:  O(n)
// Space: O(sqrt(n))

class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        int count = 0;
        auto curr = head;
        while (curr) {
            curr = curr->getNext();
            ++count;
        }
        int bucket_count = ceil(sqrt(count));
        
        vector<ImmutableListNode *> buckets;
        count = 0;
        curr = head;
        while (curr) {
            if (count % bucket_count == 0) {
                buckets.emplace_back(curr);
            }
            curr = curr->getNext();
            ++count;
        }
        
        for (int i = buckets.size() - 1; i >= 0; --i) {
            printNodes(buckets[i], bucket_count);
        }
    }

private:
    void printNodes(ImmutableListNode *head, int count) {
        vector<ImmutableListNode *> nodes;
        while (head && nodes.size() != count) {
            nodes.emplace_back(head);
            head = head->getNext();
        }
        for (int i = nodes.size() - 1; i >= 0; --i) {
            nodes[i]->printValue();
        }
    }
};

// Time:  O(n)
// Space: O(n)
class Solution2 {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        vector<ImmutableListNode *> nodes;
        while (head) {
            nodes.emplace_back(head);
            head = head->getNext();
        }
        for (int i = nodes.size() - 1; i >= 0; --i) {
            nodes[i]->printValue();
        }
    }
};

// Time:  O(n^2)
// Space: O(1)
class Solution3 {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        for (ImmutableListNode *tail = nullptr, *curr = nullptr; tail != head; tail = curr) {
            for (curr = head; curr->getNext() != tail; curr = curr->getNext());
            curr->printValue();
        }
    }
};

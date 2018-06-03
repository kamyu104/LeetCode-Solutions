// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        if (hand.size() % W) {
            return false;
        }

        unordered_map<int, int> counts;
        for (const auto& i : hand) {
            ++counts[i];
        }

        priority_queue<int, vector<int>, greater<int>> min_heap(hand.begin(), hand.end());
        for (int i = 0; i < hand.size() / W; ++i) {
            while (counts[min_heap.top()] == 0) {
                min_heap.pop();
            }
            int start = min_heap.top(); min_heap.pop();
            for (int j = 0; j < W; ++j) {
                --counts[start];
                if (counts[start] < 0) {
                    return false;
                }
                ++start;
            }
        }
        return true;
    }
};

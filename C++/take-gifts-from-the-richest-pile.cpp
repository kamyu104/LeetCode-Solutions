// Time:  O(n + klogn)
// Space: O(1)

// heap
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        make_heap(begin(gifts), end(gifts));
        while (--k >= 0) {
            const int x = gifts.front();
            pop_heap(begin(gifts), end(gifts)); gifts.pop_back();
            gifts.emplace_back(sqrt(x));
            push_heap(begin(gifts), end(gifts));
        }
        return accumulate(cbegin(gifts), cend(gifts), 0ll);
    }
};

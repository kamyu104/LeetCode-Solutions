// Time:  O(klogn)
// Space: O(1)

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        make_heap(begin(piles), end(piles));
        while (--k >= 0) {
            int x = piles.front();
            pop_heap(begin(piles), end(piles)); piles.pop_back();
            piles.emplace_back((x + 1) / 2);
            push_heap(begin(piles), end(piles));
        }
        return accumulate(cbegin(piles), cend(piles), 0);
    }
};

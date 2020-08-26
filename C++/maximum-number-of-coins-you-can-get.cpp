// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(begin(piles), end(piles));
        int result = 0;
        for (int i = piles.size() / 3; i < piles.size(); i += 2) {
            result += piles[i];
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(1)

// greedy
class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        const int mn = ranges::min(enemyEnergies);
        return currentEnergy >= mn ? ((currentEnergy - mn) + accumulate(cbegin(enemyEnergies), cend(enemyEnergies), 0ll)) / mn : 0;
    }
};

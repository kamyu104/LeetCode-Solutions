// Time:  O(n)
// Space: O(1)

// greedy
class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int result = 0;
        for (int i = 0; i < size(energy); ++i) {
            const int inc1 = max((energy[i] + 1) - initialEnergy, 0);
            const int inc2 = max((experience[i] + 1) - initialExperience, 0);
            result += inc1 + inc2;
            initialEnergy += inc1 - energy[i];
            initialExperience += inc2 + experience[i];
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        vector<int> days(flowers.size());
        for (int i = 0; i < flowers.size(); ++i) {
            days[flowers[i] - 1] = i;
        }
        auto result = numeric_limits<int>::max();
        for (int i = 0, left = 0, right = k + 1; right < days.size(); ++i) {
            if (days[i] < days[left] || days[i] <= days[right]) {   
                if (i == right) {
                    result = min(result, max(days[left], days[right])); 
                }
                left = i, right = k + 1 + i;
            }
        }
        return (result == numeric_limits<int>::max()) ? -1 : result + 1;
    }
};

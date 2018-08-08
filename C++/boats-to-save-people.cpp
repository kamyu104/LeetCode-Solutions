// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int result = 0;
        int left = 0, right = people.size() - 1;
        while (left <= right) {
            ++result;
            if (people[left] + people[right] <= limit) {
                ++left;
            }
            --right;
        }
        return result;
    }
};

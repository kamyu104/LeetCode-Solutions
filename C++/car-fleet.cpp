// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> cars;
        for (int i = 0; i < position.size(); ++i) {
            cars.emplace_back(position[i],
                              static_cast<double>(target - position[i]) / speed[i]);
        }
        sort(cars.begin(), cars.end());
        int result = 0;
        double curr = 0;
        for (int i = position.size() - 1; i >= 0 ; --i) {
            if (cars[i].second > curr) {
                curr = cars[i].second;
                ++result;
            }
        }
        return result;
    }
};

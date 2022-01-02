// Time:  O(nlogn)
// Space: O(1)

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(begin(asteroids), end(asteroids));
        for (const auto& x : asteroids) {
            if (x > mass) {
                return false;
            }
            mass += min(x, asteroids.back() - mass);
        }
        return true;
    }
};

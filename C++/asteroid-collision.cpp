// Time:  O(n)
// Space: O(n)

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        for (const auto& x : asteroids) {
            if (x > 0) {
                result.emplace_back(x);
            }
            while (!empty(result) && 0 < result.back() && result.back() < -x) {
                result.pop_back();
            }
            if (!empty(result) && 0 < result.back()) {
                if (result.back() == -x) {
                    result.pop_back();
                }
                continue;
            }
            result.emplace_back(x);
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(n)
class Solution2 {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        for (const auto& x : asteroids) {
            bool is_exploded = false;
            while (!empty(result) && x < 0 && 0 < result.back()) {
                if (result.back() < -x) {
                    result.pop_back();
                    continue;
                } else if (result.back() == -x) {
                    result.pop_back();
                }
                is_exploded = true;
                break;
            }
            if (!is_exploded) {
                result.emplace_back(x);
            }
        }
        return result;
    }
};

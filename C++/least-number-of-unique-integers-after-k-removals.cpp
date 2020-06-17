// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        const auto& count = counter(arr);
        const auto& count_count = counter(count);
        int result = count.size();
        for (int c = 1; c <= arr.size(); ++c) {
            if (!count_count.count(c)) {
                continue;
            }
            if (k < c * count_count.at(c)) {
                result -= k / c;
                break;
            }
            k -= c * count_count.at(c);
            result -= count_count.at(c);
        }
        return result;
    }

private:
    unordered_map<int, int> counter(const vector<int>& arr) {
        unordered_map<int, int> result;
        for (const auto& i : arr) {
            ++result[i];
        }
        return result;
    }
    
    unordered_map<int, int> counter(const unordered_map<int, int>& count) {
        unordered_map<int, int> result;
        for (const auto& [_, i] : count) {
            ++result[i];
        }
        return result;
    }
};

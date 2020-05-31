// Time:  O(n)
// Space: O(n)

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        return counter(target) == counter(arr);
    }

private:
    unordered_map<int, int> counter(const vector<int>& arr) {
        unordered_map<int, int> count;
        for (const auto& x : arr) {
            ++count[x];
        }
        return count;
    }
};

// Time:  O(nlogn)
// Space: O(1)
class Solution2 {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(begin(target), end(target));
        sort(begin(arr), end(arr));
        return target == arr;
    }
};

// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_set<int> lookup(cbegin(arr), cend(arr));
        return count_if(cbegin(arr), cend(arr),
                        [&lookup](const auto& x) {
                            return lookup.count(x + 1);
                        });
    }
};

// Time:  O(nlogn)
// Space: O(1)
class Solution2 {
public:
    int countElements(vector<int>& arr) {
        sort(begin(arr), end(arr));
        int result = 0, l = 1;
        for (int i = 0; i + 1 < arr.size(); ++i) {
            if (arr[i] == arr[i + 1]) {
                ++l;
                continue;
            }
            if (arr[i] + 1 == arr[i + 1]) {
                result += l;
            }
            l = 1;
        }
        return result;
    }
};

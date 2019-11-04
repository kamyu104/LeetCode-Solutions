// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int result = 1;
        unordered_map<int,int> lookup;
        for (int i = 0 ; i < arr.size() ; ++i){
            lookup[arr[i]] = lookup[arr[i] - difference] + 1;
            result = max(result, lookup[arr[i]]);
        }
        return result;
    }
};

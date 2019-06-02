// Time:  O(m * n)
// Space: O(m * n)

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int> count;
        for (const auto& row : matrix){
            ++count[encode(row)]; 
        }
        
        using pair_type = decltype(count)::value_type;
        return max_element(count.cbegin(), count.cend(),
                           [] (const pair_type& a,
                               const pair_type& b) {
                               return a.second < b.second;
                           })->second;
    }

private:
    string encode(const vector<int>& s) {
        string result;
        for (const auto& c : s) {
            result.push_back(c ^ s[0]);
        }
        return result;
    }
};

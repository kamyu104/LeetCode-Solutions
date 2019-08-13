// Time:  O(1)
// Space: O(1)

class Solution {
public:
    Solution() : lookup_(12) {
        for (int M = 1; M < lookup_.size(); ++M) {
            lookup_[M] = lookup_[M - 1] + dayOfMonth(M);
        }
    }

    int dayOfYear(string date) {   
        const auto& result = split(date, '-');
        const auto& Y = stoi(result[0]), &M = stoi(result[1]), &D = stoi(result[2]);
        const auto& leap = (M > 2 && (((Y % 4 == 0) && (Y % 100 != 0)) || (Y % 400 == 0))) ? 1 : 0;
        return lookup_[M - 1] + D + leap;
    }

private:
    int dayOfMonth(int M) {
        return (M == 2) ? 28 : 31 - (M - 1) % 7 % 2;
    }
    
    vector<string> split(const string& s, const char delim) {
        vector<string> result;
        auto end = string::npos;
        do {
            const auto& start = end + 1;
            end = s.find(delim, start);
            result.emplace_back(s.substr(start, end - start));
        } while (end != string::npos); 
        return result;
    }

    vector<int> lookup_;
};

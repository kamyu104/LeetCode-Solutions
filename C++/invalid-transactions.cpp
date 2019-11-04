// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        static const int AMOUNT = 1000;
        static const int MINUTES = 60;
        vector<tuple<string, int, int, string>> trans;
        for (const auto& transaction : transactions) {
            const auto& t = split(transaction, ',');
            trans.emplace_back(t[0], stoi(t[1]), stoi(t[2]), t[3]);
        }
        sort(trans.begin(), trans.end(),
             [](const auto& a, const auto& b) {
                 return get<1>(a) < get<1>(b);
             });
        unordered_map<string, vector<int>> trans_indexes;
        for (int i = 0; i < trans.size(); ++i) {
            trans_indexes[get<0>(trans[i])].emplace_back(i);
        }
        vector<string> result;
        for (const auto& [name, indexes] : trans_indexes) {
            int left = 0, right = 0;
            for (int i = 0; i < indexes.size(); ++i) {
                const auto& t = trans[indexes[i]];
                if (get<2>(t) > AMOUNT) {
                    result.emplace_back(to_str(t));
                    continue;
                }
                while (left + 1 < indexes.size() &&
                       get<1>(trans[indexes[left]]) < get<1>(t) - MINUTES) {
                    ++left;
                }
                while (right + 1 < indexes.size() &&
                       get<1>(trans[indexes[right + 1]]) <= get<1>(t) + MINUTES) {
                    ++right;
                }
                for (int i = left; i <= right; ++i) {
                    if (get<3>(trans[indexes[i]]) != get<3>(t)) {
                        result.emplace_back(to_str(t));
                        break;
                    }
                }
            }
        }
        return result;
    }

private:
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
    
    template<typename T>
    string to_str(const T& t) {
        stringstream ss;
        ss << get<0>(t) << "," << get<1>(t) << ","
           << get<2>(t) << "," << get<3>(t);
        return ss.str();
    }
};

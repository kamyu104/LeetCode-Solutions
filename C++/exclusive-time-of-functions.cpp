// Time:  O(n)
// Space: O(n)

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> result(n);
        stack<int> stk;
        int prev = 0;
        for (const auto& log : logs) {
            vector<string> tokens = split(log, ':');
            if (tokens[1] == "start") {
                if (!stk.empty()) {
                    result[stk.top()] += stoi(tokens[2]) - prev;
                }
                stk.emplace(stoi(tokens[0]));
                prev = stoi(tokens[2]);
            } else {
                result[stk.top()] += stoi(tokens[2]) - prev + 1;
                stk.pop();
                prev = stoi(tokens[2]) + 1;
            }
        }
        return result;
    }

private:
    vector<string> split(const string& s, const char delim) {
        vector<string> tokens;
        stringstream ss(s);
        string token;
        while (getline(ss, token, delim)) {
            tokens.emplace_back(token);
        }
        return tokens;
    }
};


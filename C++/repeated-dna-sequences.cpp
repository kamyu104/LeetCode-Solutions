class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        if(s.size() < 10) return ans;

        unordered_map<string,int> freq;
        for(int i=0;i<s.size()-9;i++){
            string cur = s.substr(i,10);
            // cout<<cur<<endl;
            freq[cur]++;
        }

        for(pair ele:freq){
            // cout<<ele.first<<" "<<ele.second<<endl;
            if(ele.second > 1){
                ans.emplace_back(ele.first);
            }
        }
        return ans;
    }
}; 
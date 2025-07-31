class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> ans;
        const int n=arr.size();
        for(int i=0; i<n; i++){
            const int x=arr[i];
            int skip=0, take=x;
            ans.insert(take);
            for(int j=i-1; j>=0; j--){
                skip|=arr[j];
                take=skip|x;
                if (skip==take) break;
                ans.insert(take);
            }
        }   
        return ans.size();
    }
};

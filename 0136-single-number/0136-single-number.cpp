class Solution {
public:
    int singleNumber(vector<int>& v) {
        int k=0,n=v.size();
        for(auto x : v)k=k^x;
        return k;
    }
};
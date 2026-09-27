class Solution {
public:
    bool canTransform(vector<int>& v, vector<int>& n) {
        long long  s1=0,s2=0;
        for(auto x : v)s1+=x;
        for(auto x : n)s2+=x;
        return (s1==s2);
        
    }
};
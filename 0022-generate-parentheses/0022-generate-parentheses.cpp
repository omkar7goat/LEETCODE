class Solution {
public:
   vector<string>v;
    void helper(int n,int a,int b,string s){
    if(s.size()==2*n){
        v.push_back(s);return;
    }
    if(a<n){
        helper(n,a+1,b,s+'(');
    }
    if(b<a){
        helper(n,a,b+1,s+')');
    }
 }
    vector<string> generateParenthesis(int n) {
        helper(n,0,0,"");
        return v;
    }
};
class Solution {
public:
     unordered_map<char, string> mp = {{'2', "abc"},{'3', "def"},{'4', "ghi"},{'5', "jkl"},{'6', "mno"},{'7', "pqrs"},{'8', "tuv"},{'9', "wxyz"},{'1',""}};
    vector<string>ans;
    void f(int i ,string curr , int n , string s){
       if(i>=n){
        ans.push_back(curr);return;
       }
        string g= mp[s[i]];
        for(auto x : g){
            curr+=x;
            f(i+1,curr,n,s);
            int currsize=curr.size()-1;string newcurr="";
            for(int k=0;k<currsize;k++)newcurr+=curr[k];
            curr=newcurr;
        }
    }
    vector<string> letterCombinations(string s) {
        f(0,"",s.size(),s);
       return ans;
    }
};
class Solution {
public:
     unordered_map<char, string> mp = {{'2', "abc"},{'3', "def"},{'4', "ghi"},{'5', "jkl"},{'6', "mno"},{'7', "pqrs"},{'8', "tuv"},{'9', "wxyz"},{'1',""}};
    vector<string>ans;
    void f(int i ,string& curr , int n , string s){
       if(i>=n){
        ans.push_back(curr);return;
       }
        string g= mp[s[i]];
        for(auto x : g){
            curr+=x;
            f(i+1,curr,n,s);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string s) {
        string curr="";
        f(0,curr,s.size(),s);
       return ans;
    }
};
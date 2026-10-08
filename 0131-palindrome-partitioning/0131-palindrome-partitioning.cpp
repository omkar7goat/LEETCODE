class Solution {
public:
   vector<vector<string>>ans;
    void f(int i ,int n,string s,vector<string>state){
        if(i>=n){
           ans.push_back(state);
        }
        for(int j=i;j<n;j++){
            string g="";
            for(int k=i;k<=j;k++)g+=s[k];
            string l=g;reverse(l.begin(),l.end());
            if(l==g){
                state.push_back(g);
                f(j+1,n,s,state);
                state.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        int n=s.size();vector<string>state;
        f(0,n,s,state);
        return ans;
        
    }
};
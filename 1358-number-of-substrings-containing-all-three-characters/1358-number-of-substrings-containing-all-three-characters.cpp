class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size(),lo=0,hi=0,ans=0;
        set<char>st;map<char,int>mp;
        while(hi<=n-1){
            char ch=s[hi];
            mp[ch]=hi;st.insert(ch);
            if(st.size()==3){
                int lowidx=1e9;char minchar;
                for(auto x : mp){
                    if(x.second<lowidx){
                        lowidx=x.second;minchar=x.first;
                    }
                }
                ans+=(lowidx-lo+1)*(n-hi);
                st.erase(minchar);mp.erase(minchar);
                lo=lowidx+1;
                
            }
            else{
                hi++;
            }



        }
      return ans;
    }
};
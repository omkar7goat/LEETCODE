class Solution {
public:
    string removeKdigits(string s, int k) {
        stack<char>st;int n=s.size();
        if(n==1){
            if(k>=1)return "0";
            else return s;
        }
        string ans="";
        for(int i=0;i<n;i++){
            char curr=s[i];int g=k;
            if((st.size()==0)&&(curr!='0')){
                st.push(curr);continue;
            }
            if(k>0){
                while((st.size()>0)&&(k>0)&&(curr<st.top())){
                    st.pop();k--;
                }
                if((st.size()==0)&&(curr=='0'))continue;
                st.push(curr); 
            }
            else{
                if((st.size()==0)&&(curr=='0'))continue;
                st.push(s[i]);
            }
        }
        if(k>0){
            while((k>0)&&(st.size()>0)){
                st.pop();k--;
            }
        }
        while(st.size()>0){
            ans+=st.top();st.pop();
        }
        reverse(ans.begin(),ans.end());
        
        if(ans=="")return "0";

        return ans;
    }
};
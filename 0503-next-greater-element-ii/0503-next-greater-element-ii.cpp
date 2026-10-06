class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& v) {
        stack<int>st;int n=v.size();vector<int>ans(n,-1);
        for(int i=n-1;i>=0;i--){
            int curr=v[i];
            while((st.size()>0)&&(st.top()<=curr)){
                st.pop();
            }
            ans[i]=st.empty() ? -1 : st.top();
            st.push(v[i]);
        }
         for(int i=n-1;i>=0;i--){
            int curr=v[i];
            while((st.size()>0)&&(st.top()<=curr)){
                st.pop();
            }
            ans[i]=st.empty() ? -1 : st.top();
            st.push(v[i]);
        }
   return ans;
    }
};
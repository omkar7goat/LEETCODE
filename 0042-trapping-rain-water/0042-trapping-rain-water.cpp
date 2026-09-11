class Solution {
public:
    int trap(vector<int>& v) {
        int n=v.size();int ans=0;
        vector<int>prev(n,0);prev[0]=v[0];
        for(int i=1;i<n;i++){
            prev[i]=max(v[i],prev[i-1]);
        }
        vector<int>next(n,0);next[n-1]=v[n-1];
        for(int i=n-2;i>=0;i--){
            next[i]=max(v[i],next[i+1]);
        }
        for(int i=0;i<n;i++){
            int a=prev[i],b=next[i];
            int c=min(a,b);
            int d=c-v[i];
            if(d<0)continue;
            ans+=d;
        }

        return ans;
    
    }
};
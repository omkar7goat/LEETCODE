class Solution {
public:
    int maxScore(vector<int>& v, int k) {
        int n=v.size(),ans=0;
        int lo=n-k,hi=n-1,s=0;
        for(int i=lo;i<=hi;i++){
            s+=v[i];ans=max(ans,s);
        }
        for(int i=0;i<k;i++){
            s-=v[lo];lo=(lo+1) % n;
          hi=(hi+1) % n;
          s+=v[hi];

          
          ans=max(ans,s);

        }
        return ans;
    }
};
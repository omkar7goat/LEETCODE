class Solution {
public:
    int longestOnes(vector<int>& v, int k) {
        int n=v.size(),lo=0,hi=0,s=0,ans=-1e9,curr=k;
        if(k==0){
            int ansz=-1e9;
            int currsum=0;
            for(int i=0;i<n;i++){
                if(v[i]==0){
                    currsum=0;
                }
                else{
                    currsum++;
                }
                ansz=max(ansz,currsum);
            }
            return ansz;
        }
        queue<int>q;
        while(hi<=n-1){
            if(v[hi]==1){
                s=hi-lo+1;ans=max(ans,s);hi++;
            }
            else{
                if(curr==0){
                   if(q.size()>0){
                    int a=q.front();q.pop();
                   while(lo<=a)lo++;curr=1;
                   }
                   
                   
                }
                else{
                    curr--;s=hi-lo+1;ans=max(ans,s);q.push(hi);hi++;
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    int minDays(vector<int>& v, int m, int k) {
        int n=v.size(),lo=1,hi=-1e9;
        for(auto x : v)hi=max(hi,x);
        long long n1=n,m1=m,k1=k;
        if(n1<m1*k1)return -1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int curr=0,currdays=0;
            for(auto x : v){
                if(x<=mid){
                    curr++;
                    if(curr==k){
                        currdays++;curr=0;
                    }
                }
                else curr=0;
            }
            if(currdays<m){
              lo=mid+1;
            }
            else hi=mid-1;
        }
        return lo;
    }
};
class Solution {
public:
    int minEatingSpeed(vector<int>& v, int h) {
        int n=v.size();sort(v.begin(),v.end());
        int lo=1,hi=v[n-1];
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            long long  curr=0;
            for(auto x: v){
                if(x<mid)curr+=1;
                else{
                    curr+=(x/mid);
                    if(x%mid!=0)curr++;
                }
            }
            if(curr<=h){
                hi=mid-1;
            }
            else lo=mid+1;
        }

        return lo;
    }
};
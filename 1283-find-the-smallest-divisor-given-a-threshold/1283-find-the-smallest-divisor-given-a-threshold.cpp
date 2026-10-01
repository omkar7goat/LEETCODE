class Solution {
public:
    int smallestDivisor(vector<int>& v, int threshold) {
        int n=v.size(),lo=1,hi=1e6;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int curr=0;
            for(auto x : v){
                curr+=(x/mid);
                if(x%mid!=0)curr++;

            }
            if(curr>threshold)lo=mid+1;
            else hi=mid-1;

        }
        return lo;
    }
};
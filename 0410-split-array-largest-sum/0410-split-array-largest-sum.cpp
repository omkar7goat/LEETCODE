class Solution {
public:
    int splitArray(vector<int>& v, int k) {
        int n=v.size(),lo=0,hi=0;
        for(auto x : v)lo=max(lo,x);
        for(auto x : v)hi+=x;
        if((lo==0)&&(hi==0))return 0;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int curr=0,currk=0;
            for(auto x : v){
                curr+=x;
                if(curr>mid){
                    currk++;curr=x;
                }
                else if(curr==mid){
                    curr=0;currk++;
                }
            }
            if(curr!=0)currk++;
            if(currk<=k)hi=mid-1;
            else lo=mid+1;

        }
        return lo;
    }
};
class Solution {
public:
    int findPeakElement(vector<int>& v) {
        int n=v.size(),lo=0,hi=n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            long long a=-1e12,b=-1e12;
            if(mid+1<=n-1)a=v[mid+1];
            if(mid-1>=0)b=v[mid-1];
            if((v[mid]>a)&&(v[mid]>b))return mid;
            if(v[mid]>b)lo=mid+1;
            else hi=mid-1;
        }
        return 0;
    }
};
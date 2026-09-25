class Solution {
public:
    int searchInsert(vector<int>& v, int k) {
        int n=v.size(),lo=0;
        int hi=n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(v[mid]==k)return mid;
            if(v[mid]>k){
               hi=mid-1;
            }
            else{
              lo=mid+1;
            }
        }
        return lo;
    }
};
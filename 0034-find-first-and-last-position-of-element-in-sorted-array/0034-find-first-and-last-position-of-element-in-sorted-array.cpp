class Solution {
public:
    vector<int> searchRange(vector<int>& v, int k) {
        int n=v.size(),lo=0;
        int hi=n-1,first=-1,last=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(v[mid]==k){
                if ((mid-1)>=0 && (v[mid-1]==v[mid])){
                    hi=mid-1;
                }
                else{
                    first=mid;break;
                }
            }
            else if(v[mid]>k){
               hi=mid-1;
            }
            else{
               lo=mid+1;
            }
        }
        lo=0,hi=n-1;
           while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(v[mid]==k){
                if(((mid+1)<=(n-1))&&(v[mid+1]==v[mid])){
                    lo=mid+1;
                }
                else{
                    last=mid;break;
                }
            }
            else if(v[mid]>k){
               hi=mid-1;
            }
            else{
               lo=mid+1;
            }
        }
        return {first,last};
    }
};
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int target) {
        int n=v.size(),m=v[0].size();
        int lo=0,hi=n*m-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int currcol=mid%m;
            int currrow=mid/m;
            if(v[currrow][currcol]==target)return true;
            if(v[currrow][currcol]<target){
                lo=mid+1;
            }
            else hi =mid-1;
            
        }
        return false;
    }
};
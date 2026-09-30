class Solution {
public:
    int findMin(vector<int>& v) {
        int n=v.size(),lo=0,hi=n-1,ans=0;
        if(n==1)return v[0];
        
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int a=mid-1,b=mid+1;
            if(a<0)a+=n;
            if(b>=n)b=b%n;
            if((v[mid]<v[a])&&(v[mid]< v[b]))return v[mid];
            if(v[mid]>v[lo]){
                if(v[mid]>v[hi])lo=mid+1;
                else hi=mid-1;
            }
            else{
                if(v[mid]>v[hi])lo=mid+1;
                else hi=mid-1;
            }
        }

        return -1;
        
    }

};
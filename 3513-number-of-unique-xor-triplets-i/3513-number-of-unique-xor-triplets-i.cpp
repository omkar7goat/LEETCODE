class Solution {
public:
    int uniqueXorTriplets(vector<int>& v) {
        int n=v.size(); if(n==2 || n==1)return n;
        int c=0,k=n;
        while(k>0){
            c++;k/=2;
        }        
        
        return pow(2,c);
        
    }
};
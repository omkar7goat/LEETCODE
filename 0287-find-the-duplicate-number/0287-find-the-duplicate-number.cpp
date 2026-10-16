class Solution {
public:
    int findDuplicate(vector<int>& v) {
        int n=v.size();
        int i=0;
        while(i<n){
            int corridx=v[i]-1;
            if(i==corridx){
                i++;continue;
            }
            if(v[corridx]==v[i])return v[corridx];
            swap(v[i],v[corridx]);
        }
       return n; 
    }
};
class Solution {
public:
    int minRotations(string s) {
        int state=0;int n=s.size();int ans=0;
        for(char  ch : s){
            int c=ch-'0';
            int x=(abs)(c-state);
            if(x>5)x=10-x;
            ans+=x;
            state=c;
        }
        return ans;
        
    }
};
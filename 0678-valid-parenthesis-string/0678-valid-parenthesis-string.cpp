class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        stack<int>open,aster;
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(ch=='*')aster.push(i);
            else if(ch==')'){
                if((open.size()==0)&&(aster.size()==0))return false;
               else if(open.size()>0){
                    open.pop();
                }
                else if(aster.size()>0){
                    aster.pop();
                }
            }
            else{
                open.push(i);
            }
        }
        while(open.size()>0 && aster.size()>0){
            if(aster.top()<open.top())return false;
            else{
                open.pop();
                aster.pop();
            }
        }
        return (open.size()==0);
    }
};
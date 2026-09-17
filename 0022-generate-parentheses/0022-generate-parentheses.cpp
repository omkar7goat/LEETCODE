class Solution {
public:
    vector<string>v;
    void f(string s , int o , int c ,int n){
        if((o+c==2*n)&&(o==c)){
            v.push_back(s);return;
        } 
        if(o<n)f(s+'(',o+1,c,n);      
        if(c<o) f(s+')',o,c+1,n);
       
    }
    vector<string> generateParenthesis(int n) {
        f("",0,0,n);
        return v;
    }
};
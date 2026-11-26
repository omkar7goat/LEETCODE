class Solution {
public:
   bool f(string cs , string ps) {
     int n=min(cs.length(),ps.length());
     int g=0;
     for(int i=0;i<n;i++){
        if(cs[i]!=ps[i])g++;
     }
     if(g>1)return false;
     return true;

   }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=wordList.size();
        queue<string>q;
        q.push(beginWord);
        set<string>vis;vis.insert(beginWord);
        int t=1;
        while(q.size()>0){
            int currsize=q.size();
            while(currsize--){
                string cs=q.front();q.pop();
                if(cs==endWord){
                    return t;
                }
                for(int i=0;i<n;i++){
                    string ps=wordList[i];
                    if(f(cs,ps) &&(vis.find(ps)==vis.end () ) ){
                        q.push(ps);
                        vis.insert(ps);
                    }
                }
            }
            t++;
        }
        return 0;
    }
};
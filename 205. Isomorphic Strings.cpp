class Solution {
public:
bool isIsomorphic(string s, string t) {
map<char,char>pairs;
map<char,bool>visited;
map<char,bool>vis;

//egg ->s   add ->t

//paper -> s title ->t
//p->t , a->i , p->t , e->l , r->e --> true

//foo ->s || bar->t
//f->b , o->a, o!=a --> false

//badc-> s  ||  baba->t

for(int i=0;i<s.size();i++){
if(visited[s[i]]==0 && vis[t[i]]==0){
pairs[s[i]]=t[i]; //e -> a , //g->d
visited[s[i]]=1; //e visited
 vis[t[i]]=1;
              }
                            	
if(visited[s[i]]==0 && vis[t[i]]==1){
              return false;
  }
                                                	
else if(visited[s[i]]==1){
//see if same character or not
       //g=d i.e true
if(pairs[s[i]]!=t[i]) {
          		return false;
}				
}
}
return true;
    }
};

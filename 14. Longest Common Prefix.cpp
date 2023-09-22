class Node{
public:
Node*links[26] ; 
bool flag = false ; 
int cntPrefix=0;

bool containsKey(char ch){
    return links[ch-'a'] != NULL ;
}

void put(char ch, Node*node){
    links[ch-'a'] = node ; 
}

Node*get(char ch){
    return links[ch-'a'] ;
}

void setEnd(){
    flag = true; 
}

void increasePrefix(){
    cntPrefix++;
}
bool isEnd(){
    return flag;
}
}; 

class Trie{
private: 
Node*root ; 
public:
Trie(){
    root = new Node()  ; 
}

void insert(string &word){
Node*node = root ; 
for(int i=0;i<word.size();i++){
    //if word already exist no need to increase prefix count 
    if(!node->containsKey(word[i])){
        node->put(word[i],new Node()) ; 
        node->increasePrefix() ;
    }
    node=node->get(word[i]) ; 
}
node->setEnd();
}

void solve(string &word,string&res){
    //["flower","flow","flight"] 
    // f->1 and l -> 1 after that o->3 break 
    Node*node = root ; 
    for(int i=0;i<word.size();i++){
      //  cout<<word[i]<<" "<<node->cntPrefix<<"\n"; 
      //common prefix has cnt of prefix as 1 
        if(node->cntPrefix==1){
            node=node->get(word[i]) ; 
            res+=word[i];
        }
        else break;

        //when any of the word completed no need to see further
        if(node->isEnd()==true) break;
    }
}
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
     Trie* obj = new Trie() ; 
     string res = "" , curr ="";

    for(auto&word:strs) {
         if(word=="") return "" ; 
         else obj->insert(word) ;
    }
    obj->solve(strs[0],res); 
    return res ;
    }
};

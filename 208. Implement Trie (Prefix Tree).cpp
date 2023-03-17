//    *************STRIVER OP************************
class Node{
    public:
  //2 member function of trie 
  Node*arr[26]; //array of size 26 of type Node
  bool flag=false; //flag initiallized as false

  //check if the word[i] exist i.e it doesn't points to null
  bool containsKey(char ch){
      return arr[ch-'a']!=NULL;
  }

  //creating another reference trie in order to insert new word[i] 
  //it is basically done by pointing to trie 
  void insertInReferenceTrie(char ch,Node*node){
      arr[ch-'a']=node;
  }
  Node*get(char ch){
      //where arr points will be return
     return arr[ch-'a'] ;
  }
  //mark flag as true at the end of word
  void setEnd(){
       flag=true;
  }
  //Checks if word is completed or not
  bool isEnd(){
      return flag;//if Flag true that means word was found in search else not
  }
};

class Trie {
    private:
    Node*root;

public:
    Trie() {
            //Creating new objects 
            root = new Node();    
    }
    
    //T.C -> O(length of word)
    void insert(string word) {
        Node*dummyNode=root;

        for(int i=0;i<word.size();i++){
            //if word[i] doesn't exist in trie insert it 
            if(!dummyNode->containsKey(word[i])){
                dummyNode->insertInReferenceTrie(word[i],new Node());
            }
            //move to Reference Trie 
            dummyNode=dummyNode->get(word[i]);
        }
        //standing at Last Reference Trie when word inserted than mark flag as true
        dummyNode->setEnd();
    }

     //T.C -> O(length of word)
    bool search(string word) {
        Node*dummyNode=root;
        for(int i=0;i<word.size();i++){
            //if word[i] doesn't exist in trie that means that word is not present
            if(!dummyNode->containsKey(word[i])){
               return false;
            }
            //move to Reference Trie 
            dummyNode=dummyNode->get(word[i]);
        }
        //standing at Last Reference Trie if Flag true that means word was found in search else not
       return dummyNode->isEnd();
    }
    
    //T.C -> O(length of word)
    bool startsWith(string prefix) {
        Node*dummyNode=root;
         for(int i=0;i<prefix.size();i++){
            //if word[i] doesn't exist in trie that means that word is not present
            if(!dummyNode->containsKey(prefix[i])){
               return false;
            }
            //move to Reference Trie 
            dummyNode=dummyNode->get(prefix[i]);
        }
        //standing at any Reference Trie means that prefix exist 
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

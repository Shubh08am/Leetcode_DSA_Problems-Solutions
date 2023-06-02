class Node{
    public:
    int key,value,cnt; 
    Node*next;
    Node*prev;

    Node(int _key,int _value){
        key=_key;
        value=_value;
        cnt=1;//frequency track in frequency List Map
    }
};

class List{
    public:

    int size;
    Node*head;
    Node*tail; 

    List(){
        head = new Node(-1,-1) ; 
        tail = new Node(-1,-1) ; 
        head->next=tail ; 
        tail->prev=head; 
        size=0; // INITIALIZING SIZE OF LIST AS 0
    }
    //T.C :- O(1) [ONLY LINK CHANGED]
    void addNode(Node*newNode){
        Node*temp=head->next;
        newNode->next=temp;
        newNode->prev=head;
        head->next=newNode;
        temp->prev=newNode;
        size++;
    }
    //T.C :- O(1) [ONLY LINK CHANGED]
    void delNode(Node*nodeToDelete){
        Node*prevNode = nodeToDelete->prev; 
        Node*nextNode = nodeToDelete->next; 
        prevNode->next=nextNode ; 
        nextNode->prev=prevNode ;
        size--;
    }

};


class LFUCache {
public:
    //INITIAL CONFIGURATION 
    map<int,Node*>keyNode; 
    map<int,List*>freqListMap;
    int maxSizeOfCache , minFreq , currSizeOfCache ; 

    LFUCache(int capacity) {
        maxSizeOfCache=capacity;
        minFreq=0;
        currSizeOfCache=0;
    }
    //T.C :- O(1)  -> INGNORING HASH-MAP [LOGN] FACTOR AS USING VECTOR OF LIST IT CAN BE O(1)
    void updatefreqListMap(Node*node){
        keyNode.erase(node->key) ; 

        //REMOVE CURRENT FREQUENCY [node->cnt] List from freqListMap

        freqListMap[node->cnt]->delNode(node) ; 

        //minFreq UPDATED WHEN CORRESPONDING LIST TO CURRENT FREQUENCY [node->cnt]  IS EMPTY 
        if(node->cnt==minFreq && freqListMap[node->cnt]->size==0){
            minFreq++;
        }

        List*nextFreqList = new List() ; 

        //CHECK FOR NEXT FREQUENCY AS CURRENT FREQUENCY [node->cnt] IS REMOVED 
        if(freqListMap.find(node->cnt+1) != freqListMap.end()){
            nextFreqList  = freqListMap[node->cnt+1];
        } 

        //update frequency of node 
        node->cnt+=1; 

        //INSERT NODE IN nextFreqList
        nextFreqList->addNode(node)  ; 

        // UPDATE freqListMap 
        freqListMap[node->cnt] = nextFreqList;

        //OLD ADDRESS KEPT OF NODE IN KEYNODE 
        keyNode[node->key] = node ;
    }
     //T.C :- O(1)  -> INGNORING HASH-MAP [LOGN] FACTOR AS USING VECTOR OF LIST IT CAN BE O(1)
    int get(int key) {
        //KEY PREESNT IN KEYNODE
       if(keyNode.find(key)!=keyNode.end()){
           Node*node  = keyNode[key] ; 
           int res = node->value ; 
           //NOW,SINCE KEY IS ACCESS UPDATE ITS FREQUENCY AND FREQUENCY LIST UPDATED 
           updatefreqListMap(node);
           return res;
       } 
    return -1; //KEY NOT PREESNT IN KEYNODE
    }
    
    //T.C :- O(1)  -> INGNORING HASH-MAP [LOGN] FACTOR AS USING VECTOR OF LIST IT CAN BE O(1)
    void put(int key, int value) {
        //EDGE CASE :- NO ENTRY IN CACHE ALLOWED 
        if(maxSizeOfCache ==  0) {
            return;
        }
        //KEY ALREADY PREESNT IN KEYNODE
       if(keyNode.find(key)!=keyNode.end()){
           Node*node  = keyNode[key] ; 
           node->value = value;  //UPDATED
           //NOW,SINCE KEY IS ACCESS UPDATE ITS FREQUENCY AND FREQUENCY LIST UPDATED 
           updatefreqListMap(node);
       }

    // KEY NOT PREESNT IN KEYNODE
       else{

           if(currSizeOfCache == maxSizeOfCache){
               List * list = freqListMap[minFreq] ; //LFU -> MIN FREQUENCY 
               keyNode.erase(list->tail->prev->key) ; //WHEN TIE -> LRU ONE REMOVED 
               freqListMap[minFreq]->delNode(list->tail->prev);
               currSizeOfCache--;
           }

           currSizeOfCache++; //ELEMENT INSERTEED 
           minFreq=1 ; //AS FIRST TIME KEY COMES AND INSERTED IN CACHE IT HAS FREUENCY AS 1

            List*FreqList = new List() ; 

            //IF freqListMap WITH minFreq IS NOT EMPTY TAKE THAT LIST AND INSERT NODE IN IT 
            if(freqListMap.find(minFreq) != freqListMap.end()) {
                FreqList=freqListMap[minFreq];
            }

            Node*nodeToInsert = new Node(key,value) ; 
            FreqList->addNode(nodeToInsert) ; //ADD NODE RIGHT AFTER HEAD 
            
            //OLD ADDRESS KEPT OF NODE IN KEYNODE 
            keyNode[key] = nodeToInsert ;
            
            freqListMap[minFreq] = FreqList;
       } 
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

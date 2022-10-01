class Solution {
public:
    bool wordPattern(string pattern, string s) {
     
    vector<string>word; // stores words of s --> dog at 0th index and so on
        
    string dummy="";
        
// storing every words in word 
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==' ')
        {
            word.push_back(dummy);
            dummy.clear();
        }
        else    { dummy+=s[i];   }
    }
        // last word still left add it as well
    word.push_back(dummy);
    
    
	// using two maps --> first one m for pattern and mp for storing frequency of word
    map<char,string> m;
    map<string,int> mp;
        
        
        // case 1 --> when size not equal ex-> abb  , dog cat  --> false
    if(pattern.size()!=word.size())   return false;
    
    
    for(int i=0;i<pattern.size();i++)
    {
        // find key --> a   if not exist in map than only go inside
        if(m.find(pattern[i])==m.end())
        {
            
            if(mp[word[i]]==0){
        // corresponding to a --> dog 
                m[pattern[i]]=word[i];
                // store freq of dog than
                mp[word[i]]++;
            }
      // ex-> ab , cat cat --> first frequency of cat increase to 1 --> but for b->cat not possible as cat already exist in term of frequency 
            else return false;
        }
   
    //abba -->  after we stored a and b  and came again to a than just see if  a-->dog (correspond) and b-->cat
        else
        {
            if(m[pattern[i]]!=word[i])
                return false;
        }
    }
    return true;    
    }
};

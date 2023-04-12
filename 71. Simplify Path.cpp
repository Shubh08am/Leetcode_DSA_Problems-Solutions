class Solution {
public:
    string simplifyPath(string path) {
        //APPROACH:- STACK CONCEPT 
        //AS REMOVAL WITH SOME CONDITION MENTIONED 
        
        stack<string>s;
        string res=""; 
        int n = path.size() ; 

        for(int i=0;i<n;i++){
            if(path[i]!= '/'){
                //directory name 
                string directoryName = "" ; 

            //ITERATE TILL '/' NOT FOUND 
                while(i<n && path[i]!='/') {
                    directoryName+=path[i];
                     i++;
                }
                if(directoryName==".."){
                    //up a level 
                   if(!s.empty()) s.pop();
                }
                else if(directoryName!="."){
                    s.push(directoryName);
                }
            }
        }

        if(s.empty()){
            return "/" ;
        }

        //TRICKY PART OF TAKING IN ANSWER :-
        while(!s.empty()){
            res= "/"+s.top()+res ;
            s.pop(); 
        }
        return res;
    }
};

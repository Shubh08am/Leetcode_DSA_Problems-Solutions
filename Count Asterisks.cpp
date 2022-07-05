class Solution {

public:

    int countAsterisks(string s) {

        int c= 0; int cc = 0 ; 

        vector<int>v(20000) ;

        

for(int i=0;i<s.size();i++){		if(s[i]=='|') { v.push_back(i);}

}

    for(int i = 1 ; i<v.size()-1;i+=2){

        

    int st = v[i] ;

        int e = v[i + 1] ; 

    

        for(int i = st; i<e ; i++){

            if( s[i] == '*') c++;

        }

        

    }

        /*

        for(int i = 0 ; i<v[0] ; i++){ 

            if( s[i] == '*') c+= 1;

        } 

        */

        for(int i = v[v.size()-1] ; i<s.size();i++){

            if(s[i] == '*') c+=1 ; }

        

    return c ;

    }

};

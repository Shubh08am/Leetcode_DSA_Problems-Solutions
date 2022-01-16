class Solution {

public:

    vector<string> divideString(string s, int k, char fill) {

       int n = s.size()/k; 

        

if ( n * k != s.size())

{ 

    string add ( k-s.size()%k , fill ) ; 

    s+= add ;

    n++;

}

        vector<string>res ; 

        

        for( int i=0 ; i<n ; i++ ) 

        { 

            res.push_back(s.substr(i*k , k ));

        }

        return res;

                     

    }

};

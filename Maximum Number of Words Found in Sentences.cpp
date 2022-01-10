class Solution {

public:

    int mostWordsFound(vector<string>& sentences) {

        

   int ans= 0;

        for( int i = 0; i<sentences.size() ; i++ )

        { int cnt =0;

           for( int j= 0 ; j<sentences[i].length();j++)

           {

               if ( sentences [i][j] == 32)

                cnt++ ;

           }    

            ans = max(ans,cnt+1);

            

    }

     //int m = cnt + 1 ;

        return ans;

    }

};

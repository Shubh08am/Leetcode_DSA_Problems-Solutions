class Solution {

public:

    bool checkValid(vector<vector<int>>& matrix) {

        int n=matrix.size();

        int Xor=0;

        for(int i=1;i<=n;i++)     

            Xor = Xor^i;

        for(int i=0;i<n;i++){ //rows

            int currentRow=Xor;

            for(int j=0;j<n;j++){

                currentRow^=matrix[i][j];

            }

            if(currentRow!=0) return 0;

        }

        for(int i=0;i<n;i++){

            int currentCol=Xor;

            for(int j=0;j<n;j++){

                currentCol^=matrix[j][i];

            }

            if(currentCol!=0) return 0;

        }

        return 1;

    }

};

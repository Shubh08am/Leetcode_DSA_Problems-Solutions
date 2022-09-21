class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int res=INT_MAX;
        for(int i = 0;i+k<=blocks.size();i++){
            int sum=0;
            for(int j  =i;j<i+k;j++){
                if(blocks[j]=='W')sum++;
            }
            res=min(res,sum);
        }
        return res;
    }
};

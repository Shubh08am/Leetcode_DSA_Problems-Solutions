class Solution {
public:
    int guessNumber(int n) {
       
int low=0;
int high=n-1;
while(low<=high)
{
int mid=low+(high-mid)/2;
if(guess(mid)==-1)
high=mid-1;
else if(guess(mid)==1)
low=mid+1;
else
return mid;
}
return low;
    }
};

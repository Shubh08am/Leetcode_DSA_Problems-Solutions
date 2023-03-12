/*
We have to increment n-1 elements by 1 to make them equal. This is equal to decrementing only 1 element by 1.
For example- [5,6,7,8] can be made equal if we decrement number 8, three times and 7, two times and 6 one times. Decrementing 8 by 1 is equal to adding 1 to all the other elements.
*/
class Solution {
	public:
		int minMoves(vector<int>& nums) {
			int mn=*min_element(nums.begin(),nums.end()) , cnt=0;
 			for(auto& it : nums) cnt+=(it-mn);
			return cnt;

		}
};

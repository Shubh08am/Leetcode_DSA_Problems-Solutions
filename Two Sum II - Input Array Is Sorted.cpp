class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        

int n = numbers.size();

vector<int>v;

int i=0; int j=n-1;

while(j>=i){

if(numbers[i]+numbers[j] == target ) 

{

	v.push_back(++i);

	v.push_back(++j);		

	break;

}

else if(numbers[i]+numbers[j] < target)i++;

 else  if(numbers[i]+numbers[j] > target) j--;

}

	return v;
    }
};

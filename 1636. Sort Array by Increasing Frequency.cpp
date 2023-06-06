class Solution {

public:

    static bool comp(const pair<int,int>&A,const pair<int,int>&B){

	if(A.first==B.first) return A.second<B.second;	return A.first>B.first;

    }

    vector<int> frequencySort(vector<int>& nums) {

      priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(&comp)>minHeap(&comp);

unordered_map<int,int>Freq;

for(auto&val:nums) Freq[val]++;

for(auto&it:Freq){

	minHeap.push({it.second,it.first});

	

	//if(minHeap.size()>k) minHeap.pop();

}

vector<int>res;

while(!minHeap.empty()){

   int val = minHeap.top().first ; 

   int val2 = minHeap.top().second;

    

    

      while (val--) res.push_back(val2);

	minHeap.pop();

}

return res;

        

    }

};

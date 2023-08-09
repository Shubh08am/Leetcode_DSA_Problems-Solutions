class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        //we can create group of at least gcd(all no. occurences)
        //but gcd > 1 as group size need to be > 1
        // [1,1,1,1,2,2,4,4,4,4] -> 4 -> 1,4 and 2-> 2 gcd(2,4) = 2 i.e 2 size group
        unordered_map<int, int>freq;
        int g = 0;
        for (auto&it : deck) freq[it]++;
        for (auto&it : freq) g = __gcd(it.second, g);
        return g!=1;
    }
};

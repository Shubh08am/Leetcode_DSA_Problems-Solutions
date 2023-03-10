class FoodRatings {
public: 
    struct cmp{
      bool operator ()(const pair<int, string>& l, const pair<int, string>& r)const{
         //Not equal rating , return higher rating one 
        if(l.first != r.first){
            return l.first > r.first;
        }
        //equal rating , return lexicographically smaller name 
        else return l.second < r.second;
      }
    };
   
    map<string,multiset<pair<int,string>,cmp>>a;
    map<string,string>place;
    map<string, int> rate;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size() ; 
        for(int i=0;i<n;i++){
            place[foods[i]]=cuisines[i];
            rate[foods[i]]=ratings[i];
            a[cuisines[i]].insert({ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        //find place of food first 
        string where = place[food] ; 
        int r = rate[food];
        rate[food] = newRating;
     //erase earlier rating of food first than insert new one 
        a[where].erase({r, food});
        a[where].insert({newRating,food}); //insert 
    }
    
    string highestRated(string cuisine) {
         auto curr = *(a[cuisine].begin()) ; 
         return curr.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */

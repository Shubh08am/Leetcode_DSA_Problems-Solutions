class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        //use topological sort(Kahn's Algorithm) 
        /* 
        create adjacency List 
           ith elem    -> List 
        ingredients[i] -> used in which receipes 
           idegree of receipes increase 
           initially,in queue push all supplies which are required in ingredients 
           than at last see which all receipes have indegree as 0 can be made as it has all required ingredients 
        */
        int n = recipes.size();
        vector<string>res; 
        unordered_map<string,vector<string>>adj;
        unordered_map<string,int>indegree;
        for(int i=0;i<ingredients .size();i++){
             for(auto&it:ingredients[i]){
                 adj[it].push_back(recipes[i]);
                 indegree[recipes[i]]++;    //idegree of receipes increase 
             }
        }
        
        queue<string>q;
        //push in queue all supplies 
        for(auto&it:supplies){
            q.push(it);
        }

        while(!q.empty()){
            string supp = q.front();
            q.pop();

            for(auto&item:adj[supp]){
                //decrease the indegree 
                indegree[item]--;
                //if it becomes 0 we can make that receipes and push in queue 
                if(indegree[item]==0){
                q.push(item);
                }
            }
        }
        //Now,see in indegree all those receipes which has indegree as 0 has all the required ingredients 
        for(int i=0;i<n;i++){
            if(indegree[recipes[i]]==0) res.push_back(recipes[i]) ;
        }
        return res;
    }
};

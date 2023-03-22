class Solution {
private:
	double dfs(unordered_map<string,vector<pair<string, double>>> &adj, unordered_map<string,int>&vis ,string start, string end){
		
		// return -1 if start and end not exist
		if(adj.find(start) == adj.end() || adj.find(end) == adj.end()) return -1.0; 
    
	//	if same always return 1
		if(start == end) return 1.0;  

		vis[start]=1; // mark as visited 

		for(auto&it : adj[start]){
			string node = it.first;
			double wt = it.second;
			if(!vis[node]){
				double currVal = dfs(adj, vis,node, end);
      //  cout<<node<<" "<<wt<<" "<<currVal<<"\n";
			//if previously currVal was not -1
				if(currVal != -1.0){
					return currVal*wt;
				}
			}
		}
		return -1.0;
	} 


public:
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
		unordered_map<string, vector<pair<string, double>>>adj;
    vector<double>division;

		for(int i = 0; i < equations.size(); i++){
			// a->b(if wt x) than b->a(wt is 1/x) 
			string u = equations[i][0] , v = equations[i][1];
			adj[u].push_back({v, values[i]});
			adj[v].push_back({u, (double)1/values[i]});
		}

		for(auto q: queries){
			unordered_map<string,int> vis; //for previous visited nodes
			double res = dfs(adj, vis, q[0], q[1]);   
			division.push_back(res);
		}
		return division;
	}
};

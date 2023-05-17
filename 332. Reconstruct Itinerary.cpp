class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> graph;
        for (auto ticket : tickets) {
            graph[ticket[0]].insert(ticket[1]);
        }
       /* for(auto&x:graph){
            cout<<x.first<<" -> ";
            for(auto y:x.second) cout<<y<<" ";
            cout<<"\n" ; 
        } 
        */
        vector<string>Itinerary;
        //The reason we are using stack is because if path doesnt exists
        // from small lexical order, we will try the next and store it in stack
        stack<string> q;
        q.push("JFK");
        while (!q.empty()) {
            string from = q.top();

            //If no more neighbour left to push 
            if (!graph[from].size()) { //if we cant move to anywhere from src
                Itinerary.push_back(from);
                q.pop();
            }
            else {
                //else we pick the place with smaller lexical order and push it into stack.
                auto to = (graph[from].begin()); 
              //  cout<<*to<<" ";
                 q.push(*to); //go and push its neighbour i.e to component 
                graph[from].erase(to); //After, pushing remove them 
            }
        }
        //The order will be stored in reverse as we have used a stack
        reverse(Itinerary.begin(), Itinerary.end());
        return Itinerary;
    }
};

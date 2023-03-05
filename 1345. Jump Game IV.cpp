class Solution {
public:
    int minJumps(vector<int>& arr) {
        // total 3 steps 
        // first -> go backward 
        // second -> go forward 
        // third -> remain at same pos and jump to next occurence of that element 
        //Apply BFS
        unordered_map<int,vector<int>>index;
         int n = arr.size() , jump=0;
         for(int i=0;i<n;i++){
             index[arr[i]].push_back(i);
         }
        //make a visited vector which tells whether the path already visited or not 
           vector<int>visited(n,0);
           queue<int>q; 
           //initially,at 0 pos thus push 0 in queue 
           q.push(0);
           while(!q.empty()){
               int size_to_traverse = q.size();
               while(size_to_traverse--){
                   int pos = q.front();
                   q.pop();
                   int backward = pos-1 ; 
                   int forward = pos+1 ; 
                   //if at last Pos we have reached destination 
                   if(pos==n-1) return jump;
                   //Step 1 :- go backward if possible and not visited path 
                   if(backward>=0 && !visited[backward]){
                       //push in queue and mark as visited 
                       q.push(backward);
                       visited[backward]=1;
                   }
                   //Step 2 :- go forward if possible and not visited path 
                   if(forward<n && !visited[forward]){
                       //push in queue and mark as visited 
                       q.push(forward);
                       visited[forward]=1;
                   }
                    //Step 3 :- remain at same pos and jump to next occurence of that element 
                    for(auto nextPos : index[arr[pos]]){
                        //if not visited path push in queue and mark as visited 
                     if(!visited[nextPos]){
                          q.push(nextPos);  
                          visited[nextPos]=1;
                     }
                    }
                //to remove tle after taking a path for a pos don't explore the remaining path 
                // as already visited[pos] is true and we are doing unnecessary traversal i.e revisiting
                index[arr[pos]].clear();
               }
            jump++;
           }
           return 0;
    }
};

class DisjointSet{
public:
    vector<int>rank,size,parent;

    DisjointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);

        //Initially,every node is a prent of itself 
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    //FIND ULTIMATE PARENT
    int findUltimatePrent(int node){
            return node==parent[node]?node:parent[node]=findUltimatePrent(parent[node]) ;
    }

    //UNION BY RANK
    void UnionByRank(int u,int v){
        int ulp_u = findUltimatePrent(u);
        int ulp_v = findUltimatePrent(v);

        //4 case 

        //case 1 :- SAME COMPONENT THAN RETURN 
        if(ulp_u==ulp_v) return;

        //case 2 :- rank[ulp_u] < ranl[ulp_v] 
        //smaller get connected to larger and parent of smaller updated to larger one
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }

         //case 3 :- rank[ulp_u] < ranl[ulp_v] 
        //smaller get connected to larger and parent of smaller updated to larger one
        if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }

         //case 4 :- rank[ulp_u] == ranl[ulp_v] 
        //anyone get connected to other one and parent of node getting connected updated
        if(rank[ulp_u]==rank[ulp_v]){
            parent[ulp_u]=ulp_v; // ulp_u connected to ulp_v
            rank[ulp_v]++;// since connected to ulp_v its rank increased
        }
    }
    void UnionBySize(int u,int v){
        int ulp_u = findUltimatePrent(u);
        int ulp_v = findUltimatePrent(v);

        //4 cases 

        //case 1:- SAME COMPONENT THAN RETURN 
        if(ulp_u == ulp_v) return;

        //case 2: -NOT BELONGING TO SAME COMPONENT 
         //smaller get connected to larger and parent of smaller updated to larger one
         //and size of larger one updated by including size of smaller one
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }

         //case 3: -NOT BELONGING TO SAME COMPONENT 
         //smaller get connected to larger and parent of smaller updated to larger one
         //and size of larger one updated by including size of smaller one
        if(size[ulp_u]>size[ulp_v]){
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }

         //case 4: -NOT BELONGING TO SAME COMPONENT 
         //anyone get connected to other node and parent of node getting connected
         // is updated to one from whom connected
         //and size of node from whom connected is updated by including 
         //size of node getting connected
        if(size[ulp_u]==size[ulp_v]){
            parent[ulp_u]=ulp_v; // ulp_u connected to ulp_v
            size[ulp_v]+=size[ulp_u]; // size of ulp_v increased by size of ulp_u
        }
    }
};

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        //2709. Greatest Common Divisor Traversal -> same concept question
        
        //Time Complexity : O(N * log(max(num)))  
        // USE PRIME FACTORIZATION 
        // STORE EVERY INDEX AS A FACTOR FOR A PRIME NO 
        //EX. 2-> POSITION WHERE 2 ARE FACTOR OF A NUMBER 
        // 3 -> , 5-> ...SO ON 
        //THAN, USE DSU AND MAKE COMPONENT USING INDEX 
       //THAN, FIND LARGEST SIZE OF A COMPONENT 

       map<int,vector<int>>factor; 
       int n = nums.size();
       for(int i=0;i<n;i++){
           for(int j=2;j*j<=nums[i];j++){
               if(nums[i]%j==0){
                   //CONTRIBUTION OF PRIME NO AT WHICH INDEX AS FACTOR ARE STORED
                   factor[j].push_back(i);
                   //ex:- 100%2=0 -> 100/2=50%2 =0 -> 50/2 = 25 -> now,stop
                  //  and search for other prime factor
                   while(nums[i]%j==0) nums[i]/=j; 
               }
           }
           //ex:- 6 -> 6%2=0 -> 6/2=3 
           //now,since 3*3=9>6 therefore out of loop 
           //but,still 3 left to see and store position 
           if(nums[i]>1) factor[nums[i]].push_back(i) ; 
       }
       
       //NOW, APPLY UNION LOGIC
       DisjointSet ds(n);
       for(auto&it:factor){
           vector<int>prime_pos = it.second;
           //DO UNION 
           for(int i=0;i<prime_pos.size()-1;i++){
               ds.UnionBySize(prime_pos[i],prime_pos[i+1]);
           }
       }

       //NOW,SEE FOR LARGEST COMPONENT SIZE 
       int LargestComponent = 0 ;
       for(int i=0;i<n;i++){
        //   cout<<ds.size[i]<<" ";
           LargestComponent=max(LargestComponent,ds.size[i]);
       }
       return LargestComponent;
    }
};

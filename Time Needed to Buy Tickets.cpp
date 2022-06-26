class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int cnt = 0 ;
int n = tickets.size();
        
while(tickets[k]){

	

for(int i = 0; i<tickets.size();i++){

if( tickets[i] > 0 ) {
    tickets[i]-=1;

cnt++;

}
if ( tickets[k] == 0 ) break ;

}}

return cnt ;
    }
};

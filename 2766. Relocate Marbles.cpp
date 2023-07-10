const int mod = 1e9 + 7 ;
#define ll long long
#define ld long double
#define  pl pair<ll, ll>
#define vl vector<ll>
#define rep(i, a, b) for (ll i = a; i < b; ++i)
#define rev(i, a, b) for (ll i = a; i >b; --i)
#define sz(x) x.size();
#define F first
#define S second
#define in insert
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define Sort(x) sort(all(x))
#define mpl map<ll,ll>
#define si set<ll>
#define out(x) cout << x << "\n";
#define os(x) cout << x << " ";
#define MAX(x) *max_element(all(x))
#define MIN(x) *min_element(all(x))
#define SUM(x) accumulate(all(x), 0LL)
#define COUNT(x,u) count(all(x), u)
#define B break 
#define C continue 
#define pq priority_queue<ll>
#define mpq priority_queue<ll,vector<ll>,greater<ll>>



class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        int n = nums.size() , m = moveFrom.size() ; 
        mpl mp; vector<int> v; 
        for(auto&it:nums) mp[it]++;
        rep(i,0,m){
            mp.erase(moveFrom[i]);
            mp[moveTo[i]]++ ; 
        }
        for(auto&it:mp) v.push_back(it.first);
        return v;
    }
};

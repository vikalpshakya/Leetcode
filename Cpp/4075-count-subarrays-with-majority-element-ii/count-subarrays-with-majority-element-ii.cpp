#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
#define ll long long
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    int n,k;
    
    struct PBDS{
        // order_of_key(k): Gives the count of elements smaller than k
        // find_by_order(k): Returns the iterator for the kth element 
        ordered_multiset<int> os;
     
        void insert(int x){
            os.insert(x);
        }
        void erase(int x){
            os.erase(os.find_by_order(os.order_of_key(x)));
        }
        int less_than(int x){
            // returns no of elements < x
            return os.order_of_key(x);
        }
        int less_than_equal(int x){
            return less_than(x+1);
        }
        int greater_than(int x){
            return os.size() - less_than_equal(x);
        }
        int greater_than_equal(int x){
            return os.size() - less_than(x);
        }
        int count(int x){
            // returns the count of element x in the multiset
            return less_than_equal(x) - less_than_equal(x-1);
    
        }
        int between(int l,int r){
            // returns no of elements >=l && <= r
            int big = os.order_of_key(r+1);
            int small = os.order_of_key(l);
            return big - small;
        }
        void print(){
            for(auto it : os){
                cout << it << " ";
            }
            cout << endl;
        }
        void clear(){
            os.clear();
        }
        int size(){
             return (int)(os.size());
        }
    };
    
    ll solve2(vector<int>&a){
        // cin >> n >> k;

        vector<int> pref(n);
        pref[0] = a[0];
        for(int i=1;i<n;i++){
            pref[i] = pref[i-1] + a[i];
        }
        PBDS ms;
        ms.insert(0);
        ll ans = 0;
        for(int i=0;i<n;i++){
            // pref[r] - pref[l-1] > 0
            // pref[l-1] < pref[r]
            ll pref_r = pref[i];
            ll v = ms.less_than(pref_r);
            ans +=(ll) v;
            ms.insert(pref_r);
        }
        return ans;
        cout << ans << endl;
    }
    
    long long countMajoritySubarrays(vector<int>& vec, int K) {

        n = vec.size();
        k = K;

        for(auto &it: vec) {
            if(it == k) it = 1;
            else it = -1;
        }

        // vector<int>pre(n+1,0);
        // pre[0] = vec[0];

        // for(int i = 1; i < n; i++) pre[i] += vec[i] + pre[i-1];


        // ll total = (n*(n+1))/2;
        // ll ans = total - countSubarrays(vec,n,0);
        // return ans;
        return solve2(vec);
    }
};

// [-1 1 1 -1]
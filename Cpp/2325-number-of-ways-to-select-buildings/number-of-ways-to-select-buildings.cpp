#define ll long long
class Solution {
public:
    long long numberOfWays(string s) {
        ll total0 = 0, total1 = 0;

        for (auto it : s) {
            if (it == '1')
                total1++;
            else
                total0++;
        }

        ll ans = 0;
        ll left0 = 0, left1 = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                left0++;

                ll right1 = total1 - left1;
                ans += (left1 * right1);
            } 
            else {
                left1++;

                ll right0 = total0 - left0;
                ans += (left0 * right0);
            }
        }

        return ans;
    }
};

/*
// 101 , 010
// ans = ways(101) + ways(010)

// "011001"

    i = 2, lones = 2 , right = 1
    ans += 2;
    i = 3 , lones = 2, right = 1
    ans += 2;


at each s[i] = '0' , -> '101'
-> left number of ones * right number of ones

number of ones encounter = 2
number of right ones = total ones - numbers ones encountered

ans += lones * r ones


cz = 1, co = 0 , i = 0

cz = 2, co = 0 , i = 1
cz = 2, co = 1 , i = 2
cz = 2, co = 2 , i = 3
cz = 3, co = 2 , i = 4


*/

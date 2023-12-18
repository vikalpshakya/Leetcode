// Time complexity: O(n), Space complexity: O(n)

class Solution {
public:
    int numRabbits(vector<int>& ans) {
        unordered_map<int,int>mp;
        for(int i = 0; i < ans.size(); i++){
            mp[ans[i]]++;
        }
        int sum = 0;

        // for(auto i: mp){
        //     cout << i.first << " -> " << i.second << " ";
        //     cout << "\n";}

        for(auto i: mp){
            if(i.first == 0)
                sum += i.second;
            
            else{
                if(i.second > i.first+1){
                    int mod = i.second % (i.first+1) ;
                    int div = i.second / (i.first+1);
                    if(mod == 0){
                        sum = sum + (i.first+1)*div;
                    }
                    else 
                        sum = sum + (i.first+1)*div + i.first + 1;
                    
                }
                else 
                    sum+= (i.first + 1);
                }
        }
        return sum;
    }
};

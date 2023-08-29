class Solution {
public:
// -------------NAIVE APPROACH ----------------//

// Time complexity: O(n^2) , Space complexity: O(1)

    int bestClosingTime1(string customers) {
        int n = customers.length();
        int minP = INT_MAX;
        int minH = INT_MAX;
        
        for(int i = 0; i < n; i++){
            int currP = 0;
            int j = i;
            
            while(j < n){
                if(customers[j] == 'Y')
                    currP++;
                j++;
            }

            j = i-1;
            while(j >= 0){
                if(customers[j] == 'N')
                    currP++;
                j--;
            }
            if(currP < minP){
                minP = currP;
                minH = i;
            }
        }
            // edge case , when shop closes at nth hour
            int NthP = count(customers.begin(), customers.end(), 'N');
            if(NthP < minP){
                minP = NthP;
                minH = n;
            }
            return minH;
    }
// --------------OPTIMIZED APPROACH ------------//

// Time complexity: O(N) , Space complexity: O(1)

    int bestClosingTime(string customers) {
        int penalty = 0, curPenalty = 0, start = 0;

        for(int i = 0; i < customers.size(); i++){
            
            char ch = customers[i];
            
            if(ch =='Y') curPenalty--;
            else curPenalty++;
            if(penalty > curPenalty){
                start = i + 1;
                penalty = curPenalty;
            }
        }
        return start;
    }
};


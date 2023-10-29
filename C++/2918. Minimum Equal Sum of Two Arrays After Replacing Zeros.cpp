// #define ll long long
// class Solution {
//     int count0(vector<int>& nums){
//         int count = 0;
//         for(auto i: nums){
//             if(i == 0) count++;
//         }
//         return count;
//     }
//     int solve(vector<int>& nums){
//         ll sum = 0;
//         for(auto i : nums){
//             if(i == 0) sum+=1;
//             sum+=i;
//         }
//         return sum;
//     }
// public:
//     long long minSum(vector<int>& nums1, vector<int>& nums2) {
//         ll sum1 = accumulate(nums1.begin(),nums1.end(),0);
//         cout << sum1 << endl;
//         ll sum2 = accumulate(nums2.begin(),nums2.end(),0);
//         cout << sum2 << endl;
//         int count1 = count0(nums1);
//         int count2 = count0(nums2);
//         if(sum1 > sum2 && count2 == 0) return -1;
//         if(sum1 < sum2 && count1 == 0) return -1;
//         if(nums1 == nums2 && (count1 != count2)) return -1;
//         if(sum1 < sum2){
//             if(sum1 + count1 > sum2 && count2 == 0) return -1;
//         }
//         if(sum1 > sum2){
//             if(sum2 + count2 > sum1 && count1 == 0) return -1;
//         }
//         if(sum1 == sum2){
//             if(count1 == 0 || count2 == 0) return -1;
//         }
//         if(sum1 == sum2){
//             return sum1 + max(count1,count2);
//         }
//         if(sum1 > sum2){
//             if(solve(nums1) > solve(nums2)) return solve(nums1);
//                 return solve(nums2);
//         }
//         else{
//             if(solve(nums1) > solve(nums2)) return solve(nums1);
//             return solve(nums2);
//         }
            

    // }
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0;
        int zerosCount1 = 0; 
        int zerosCount2 = 0;  
        long long sum2 = 0;
        for(int i = 0; i < nums1.size(); i++) {
            int element1 = nums1[i]; 
            if (element1 == 0) {
                zerosCount1++;
            }
            sum1 += element1;
        }
        for(int i = 0; i < nums2.size(); i++) {
            int element2 = nums2[i];  
            if (element2 == 0) {
                zerosCount2++;
            }
            sum2 += element2;
        }

        long long sum1WithZeros = sum1 + zerosCount1;
        long long sum2WithZeros = sum2 + zerosCount2;  

        if (sum1WithZeros > sum2 && zerosCount2 == 0) {
            return -1;
        }
        if (sum2WithZeros > sum1 && zerosCount1 == 0) {
            return -1;
        }
        return max(sum1WithZeros, sum2WithZeros);
    }
};


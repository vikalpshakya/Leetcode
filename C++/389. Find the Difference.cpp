class Solution {

  char findTheDifference_approach1(string s, string t) {
  // Time complexity: O(NLogN), Space complexity: O(1) [ N = length of s + length of t]
  sort(s.rbegin(),s.rend());
  sort(t.rbegin(),t.rend());
  int index = t.length()-1;
  int index2 = s.length()-1;
    while(index >=0 && index2 >=0){
      if(t[index] != s[index2])
          return t[index];
      index--;
      index2--;
    }
  return t[0];     
  }

  char findTheDifference_approach2(string s, string t){
    // Time complexity: O(N), Space complexity: O(N) [ N = length of s + length of t]
    unordered_map<char,int>mp;
    for(auto i :s){
        mp[i]++;
    }
    for(auto i :t){
        if(mp.find(i) == mp.end())
            return i;
        if(mp[i] > 1)
            mp[i]--;
        else 
            mp.erase(i);
    }
    return 0;
  }

  char findTheDifference_approach3(string s, string t){
  // Time complexity: O(N), Space complexity: O(1) [ N = length of s + length of t]
    int sSum = 0, tSum = 0;
    for(int i = 0; i < s.size(); i++){
      sSum += s[i];
      tSum += t[i];  
    }
/*   adding ascii value for each char in a 
     string and later subtracting the total individual sum */
    tSum += t[t.size()-1]; 
    return tSum - sSum;
  }

  char findTheDifference_approach4(string s, string t){
  // Time complexity: O(N), Space complexity: O(1) [ N = length of s + length of t]
    int c = 0;
    s += t;
    for(auto x: s){
      c^=x;
    }
    return c;
  }

  public:
  char findTheDifference(string s, string t){
    return findTheDifference_approach2(s,t);
  }
  
};

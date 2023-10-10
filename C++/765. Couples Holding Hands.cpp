class Solution {
public:
    
    void swap_to_make_couple(vector<int>& row, map<int, int> &seating, int i, int j){
        swap(row[i], row[j]);
        seating[row[i]] = i;
        seating[row[j]] = j;
        
    }
    
    int minSwapsCouples(vector<int>& row) {
        map<int, int> seating;
        for(int i=0; i<row.size(); i++){
            seating[row[i]] = i;
        }
        
        int swaps = 0;
        for(int i=0; i<row.size(); i+=2){
            int person1 = row[i];    
            int person2 = row[i] ^ 1;
            if(row[i+1] != person2){
                swaps++;
                swap_to_make_couple(row, seating, seating[person2], i+1);
            }
        }
        return swaps;
    }
};

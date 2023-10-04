
// -------------Approoach 1 ------------------//

  // ---------Time complexity: O(n) [for each func] , Space complexity: O(n) ----------//

class MyHashMap {
    vector<pair<int,int>>vec;
public:
    MyHashMap(){    
    
    }
    void put(int key, int value) {
        for(int i =0; i < vec.size(); i++){
            if( vec[i].first == key){
                vec.erase(vec.begin()+i);
            }
        }
        pair<int,int>p = {key,value};
        vec.push_back(p);
    }
    
    int get(int key) {
        for(auto i: vec){
            if(i.first == key)
                return i.second;
        }
        return -1;
    }
    
    void remove(int key) {
        for(int i = 0; i < vec.size(); i++){
            if(vec[i].first == key){
                vec.erase(vec.begin()+i);
            }
        }
    }
};

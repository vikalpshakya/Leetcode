
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

// ----------------------Approoach 2 ---------------------------------//

// ---------Time complexity: O(1) [for each func] , Space complexity: O(n) [n= 10^6] ----------//
class MyHashMap {
    int arr[1000001];
public:
    MyHashMap() {
        memset(arr,-1,sizeof(arr));
    }
    
    void put(int key, int value) {
        arr[key] = value;
    }
    
    int get(int key) {
        return arr[key];
    }
    
    void remove(int key) {
        arr[key] = -1;
    }
};




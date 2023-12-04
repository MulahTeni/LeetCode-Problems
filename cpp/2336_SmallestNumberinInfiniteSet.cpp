class SmallestInfiniteSet {
private:
    map<int, bool> input;
    int currInt;
public:
    SmallestInfiniteSet() {
        currInt = 1;
    }
    int popSmallest() {
        while(input[currInt])  ++currInt;
        int res = currInt;
        input[currInt++] = true;
        return res;
    }
    
    void addBack(int num) {
        if(input[num])  input[num] = false;
        if(num<currInt) currInt = 1;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    
    unordered_set<int> unused;
    
    PhoneDirectory(int maxNumbers) {
        for (int i = 0; i < maxNumbers; i++) unused.insert(i);
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (unused.size() == 0) return -1;
        int val = *unused.begin();
        unused.erase(val);
        return val;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        //cout << "check" << number << endl;
        return (unused.find(number) != unused.end());
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        unused.insert(number);
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */

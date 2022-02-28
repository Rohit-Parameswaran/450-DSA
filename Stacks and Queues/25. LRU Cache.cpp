class LRUCache
{
    private:
    //to access queue/list elements in constant time
    unordered_map<int, list<pair<int, int>>::iterator> m;
    list<pair<int, int>> l;
    // Most Recently used -> | E1 | E2 | E3 | E4 | E5 | <- Least Recently used
    int n;
    public:

    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        // code here
        n = cap;
    }
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        // if key is not present in the queue return -1
        if(!m.count(key)) return -1;

        auto req = *m[key];
        //remove corresponding element from queue/list
        l.erase(m[key]);
        //and push it back to the front of the queue, since it is being used now
        l.push_front({req.first, req.second});
        //change map to point accordingly
        m[key] = l.begin();
        return l.front().second;
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        // if key is already present remove it from list and reinsert at the beginning
        if(m.count(key)) 
            l.erase(m[key]);
        // if size of the queue is at max capacity then remove least used element(rear of queue) and remove corresponding element from the map 
        else if(l.size() == n){
            m.erase(l.back().first);
            l.pop_back();
        }
        l.push_front({key, value});
        m[key] = l.begin();
    }
};
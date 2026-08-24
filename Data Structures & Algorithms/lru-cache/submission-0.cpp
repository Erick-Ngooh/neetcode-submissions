            class LRUCache {
                int cap_;
                unordered_map<int, list<pair<int, int>>::iterator> cache_;
                list<pair<int, int>> order_;

            public:
                LRUCache(int capacity) : cap_(capacity), cache_(capacity) {
                }
                
                int get(int key) {
                    auto it = cache_.find(key);
                    if (it != cache_.end()) {
                        order_.splice(order_.begin(), order_, it->second);
                        return it->second->second;
                    }
                    return -1;
                }
        
        void put(int key, int value) {
            auto it = cache_.find(key);
    
            if (it != cache_.end()) {
                it->second->second = value;
                order_.splice(order_.begin(), order_, it->second);
                return ;
            }
            if (cache_.size() == cap_) {
                auto it = order_.end();
                it--;
                cache_.erase(it->first);
                order_.erase(it);
            }
            order_.push_front({key, value});
            cache_[key] = order_.begin(); 
        }
    };

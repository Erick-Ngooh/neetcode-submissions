class HashTable {
private:
    vector<list<pair<int, int>>> tabs;
    int size;
    int capacity;

public:
    HashTable(int capacity) {
        this->capacity = capacity > 1 ? capacity : 1;
        size = 0;
        tabs.resize(this->capacity);
    }

    int getIndex(int key) {
        return key % capacity;
    }

    void insert(int key, int value) {

        auto& bucket = tabs[getIndex(key)];
        for (auto& item : bucket) {
            if (item.first == key) {
                item.second = value;
                return;
            }
        }
        bucket.push_back({key, value});
        size++;
        if ((float)size / capacity >= 0.5f) {
            resize();
        }
    }

    int get(int key) {
        auto& bucket = tabs[getIndex(key)];
        for (auto& item : bucket) {
            if (item.first == key) {
                return item.second;
            }
        }
        return -1;
    }

    bool remove(int key) {
        auto& bucket = tabs[getIndex(key)];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                size--;
                return true;
            }
        }
        return false;
    }

    int getSize() const {
        return size;
    }

    int getCapacity() const {
        return capacity;
    }

    void resize() {
        capacity *= 2;
        vector<list<pair<int, int>>> newTabs(capacity);
        for (auto& bucket : tabs) {
            for (auto& item : bucket) {
                int newIndex = getIndex(item.first);
                newTabs[newIndex].push_back(item);
            }
        }
        tabs = newTabs;
    }
};
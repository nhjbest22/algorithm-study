class LRUCache {
private:
    int last_update[10'005] = {0, }; // key to time
    int time;
    queue<pair<int ,int>> Q; // key, 시간
    int data[10'005]; // key to data
    int capacity;

public:
    LRUCache(int capacity) {
        time = 0;
        this->capacity = capacity;
    }
    
    int get(int key) {
        time++;

        if(last_update[key] == 0)
            return -1;

        Q.push({key, time});
        last_update[key] = time;
        
        return data[key];
    }
    
    void put(int key, int value) {
        time++;
        Q.push({key, time});

        if(last_update[key] != 0){
            last_update[key] = time;
            data[key] = value;

            return;
        }

        if(capacity > 0){
            last_update[key] = time;
            data[key] = value;

            capacity--;

            return;
        }

        while(!Q.empty()){
            auto [cur_key, cur_time] = Q.front();
            Q.pop();

            if(last_update[cur_key] != cur_time){
                // 최신 연산이 아님
                continue;
            }

            last_update[cur_key] = 0;
            break;
        }

        last_update[key] = time;
        data[key] = value;

        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
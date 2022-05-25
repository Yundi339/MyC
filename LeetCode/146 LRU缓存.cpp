class LRUCache {
private:
	int _capcity;
	unordered_map<int, list<pair<int, int>>::iterator> lru_map;
	list<pair<int, int>> lru_list;

public:
	LRUCache(int capacity) :_capcity(capacity) {}

	int get(int key) {
		unordered_map<int, list<pair<int, int>>::iterator>::iterator it = lru_map.find(key);
		if (it != lru_map.end()) {
			lru_list.splice(lru_list.begin(), lru_list, it->second);
			return it->second->second;
		}
		return -1;
	}

	void put(int key, int value) {
		unordered_map<int, list<pair<int, int>>::iterator>::iterator it = lru_map.find(key);
		if (it != lru_map.end()) {
			lru_list.splice(lru_list.begin(), lru_list, it->second);
			it->second->second = value;
		}
		else {
			if (lru_list.size() == _capcity) {
				lru_map.erase(lru_list.back().first);
				lru_list.pop_back();
			}
			lru_list.emplace_front(make_pair(key, value));
			lru_map[key] = lru_list.begin();
		}
	}
};
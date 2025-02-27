class LRUCache {
    public:
        class node {
        public:
            int key;
            int val;
            node* next;
            node* prev;
            node(int _key, int _val) {
                key = _key;
                val = _val;
                next = NULL;
                prev = NULL;
            }
        };
    
        node* head = new node(-1, -1);
        node* tail = new node(-1, -1);
    
        int cap;
        unordered_map<int, node*> mp;
    
        LRUCache(int capacity) {
            cap = capacity;
            head->next = tail;
            tail->prev = head;
        }
    
        void addnode(node* newnode) {
            node* temp = head->next;
            newnode->next = temp;
            newnode->prev = head;
            head->next = newnode;
            temp->prev = newnode;
        }
    
        void deletenode(node* delnode) {
            node* delprev = delnode->prev;
            node* delnext = delnode->next;
            delprev->next = delnext;
            delnext->prev = delprev;
        }
    
        int get(int key_) {
            if (mp.find(key_) != mp.end()) {
                node* resnode = mp[key_];
                int res = resnode->val;
                deletenode(resnode);
                addnode(resnode);
                return res;
            }
            return -1;
        }
    
        void put(int key_, int value) {
            if (mp.find(key_) != mp.end()) {
                node* existingnode = mp[key_];
                existingnode->val = value;
                deletenode(existingnode);
                addnode(existingnode);
                return;
            }
            if (mp.size() == cap) {
                node* temp = tail->prev;
                mp.erase(tail->prev->key);
                deletenode(tail->prev);
                delete (temp);
            }
            addnode(new node(key_, value));
            mp[key_] = head->next;
        }
    };
    
    /**
     * Your LRUCache object will be instantiated and called as such:
     * LRUCache* obj = new LRUCache(capacity);
     * int param_1 = obj->get(key);
     * obj->put(key,value);
     */
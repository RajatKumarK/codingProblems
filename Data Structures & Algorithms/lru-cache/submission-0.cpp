class LRUCache {
public:

class ListNode{
    public:
        int key;
        int val;
        ListNode* next;
        ListNode* prev;

        ListNode(int key, int val){
            this->key = key;
            this->val = val;
            next=NULL;
            prev=NULL;
        }
    };

    unordered_map<int, ListNode*> mp;
    ListNode* front;
    ListNode* back;
    int capacity;
    int size;

    LRUCache(int capacity) {
        this->capacity = capacity;
        front = new ListNode(-1, -1);
        back = new ListNode(-1, -1);
        front->next = back;
        back->prev = front;
        size=0;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }
        int val = mp[key]->val;
        deleteKey(key);
        insert(key, val);
        return val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            deleteKey(key);
            insert(key, value);
        }
        else if(size==capacity){
            deleteKey(front->next->key);
            insert(key, value);
        }
        else{
            insert(key, value);
        }
    }

    void deleteKey(int key){
        size--;
        ListNode * curr = mp[key];
        curr->prev->next = curr->next;
        curr->next->prev = curr-> prev;
        mp.erase(key);
        delete(curr);
    }

    void insert(int key, int val){
        size++;
        ListNode *newNode = new ListNode(key, val);
        mp.insert({key, newNode});
        ListNode * currNode = back->prev;
        currNode->next = newNode;
        newNode->next = back;
        newNode->prev = currNode;
        back->prev = newNode;
    }
};
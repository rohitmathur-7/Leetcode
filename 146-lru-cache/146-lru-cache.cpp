class LRUCache {
public:
    class node{
        public:
            int key,val;
            node* next;
            node* prev;
            node(int k,int v){
                key=k;
                val=v;
            }
    };
    
    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);
    
    int cp;
    unordered_map<int,node*> mp;
    LRUCache(int capacity){
        cp=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    void addnode(node* newnode){
        // node* tmp=head->next;
        newnode->next=head->next;
        newnode->prev=head;
        head->next->prev=newnode;
        head->next=newnode;
    }
    
    void deletenode(node* newnode){
        node* delprev=newnode->prev;
        node* delnxt=newnode->next;
        delprev->next=delnxt;
        delnxt->prev=delprev;
    }
    
    int get(int _key){
        if(mp.count(_key)){
            node* resnode=mp[_key];
            int res=resnode->val;
            mp.erase(_key);
            deletenode(resnode);
            addnode(resnode);
            mp[_key]=head->next;
            return res;
        }
        return -1;
    }
    void put(int _key, int _val){
        if(mp.count(_key)){
            node* existingnode=mp[_key];
            mp.erase(_key);
            deletenode(existingnode);
        }    
        if(mp.size()==cp){
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(_key,_val));
        mp[_key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
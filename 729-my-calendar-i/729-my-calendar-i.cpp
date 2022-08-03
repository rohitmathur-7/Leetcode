class MyCalendar {
public:
    map<pair<int,int> ,bool> mp;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(mp.empty()){
            mp[{start,end}]=true;
            return true;
        }
        // cout<<"st: "<<start<<" end: "<<end<<endl;        
        for(auto x:mp){
            // cout<<"p1: "<<x.first.first<<" p2: "<<x.first.second<<endl;
            if(x.first.first==start && x.first.second==end) return false;
            if((start>x.first.first && start<x.first.second) || (end>x.first.first && end<x.first.second)){
                return false;
            }
            if((x.first.first>start && x.first.first<end) || (x.first.second>start && x.first.second<end)){
                return false;
            }
        }
        
        mp[{start,end}]=true;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
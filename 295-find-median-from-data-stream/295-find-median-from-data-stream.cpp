class MedianFinder {
public:
    priority_queue<double> left;
    priority_queue <double, vector<double>, greater<double>> right;
    MedianFinder() {
        
    }
    
    void addNum(int num){
        if(left.empty()) left.push(num);
        else if(left.size()==right.size()){
            if(num<=right.top()) left.push(num);
            else{
                int a=right.top();
                right.pop();
                right.push(num);
                left.push(a);
            }
        }
        else if(left.size()>right.size()){
            if(left.top()>num){
                int a=left.top();
                left.pop();
                left.push(num);
                right.push(a);
            }
            else{
                right.push(num);
            }
        }
    }
    
    double findMedian() {
        if(left.size()>right.size()) return left.top();
        else{
            return (left.top()+right.top())/2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<double, null_type, less_equal<double>, rb_tree_tag, tree_order_statistics_node_update> pbds;

class MedianFinder {
public:
    pbds st;
    int n=0;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        n++;
        st.insert(double(num));
    }
    
    double findMedian() {
        if(n%2==0){
            return ((double)*st.find_by_order(n/2)+*st.find_by_order((n/2)-1))/2;
        }   
        else{
            return *st.find_by_order(n/2);
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
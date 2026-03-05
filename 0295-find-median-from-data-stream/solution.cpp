class MedianFinder {
private:
    priority_queue<int> maxq; //left side
    priority_queue<int, vector<int>, greater<int>> minq; // right side
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxq.push(num);
        minq.push(maxq.top());
        maxq.pop();

        if(minq.size() > maxq.size()){
            maxq.push(minq.top());
            minq.pop();
        }
    }
    
    double findMedian() {
        if(minq.size() > maxq.size()){
            return minq.top();
        }
        else if(maxq.size() > minq.size()){
            return maxq.top();
        }
        double res = (minq.top() + maxq.top()) / 2.0;
        return res;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

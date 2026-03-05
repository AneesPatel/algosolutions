class Twitter {
private:
    int globaltime = 0;
    unordered_map<int, unordered_set<int>> userToFollowing;
    unordered_map<int, vector<pair<int, int>>> userTweets; // userId to pair of global time and tweets

public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        userTweets[userId].push_back({globaltime, tweetId});
        globaltime += 1;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq; //pair of time and tweetid
        int count = 0;
        vector<int> res;
        for(auto cur : userTweets[userId]){
            pq.push(cur);
        }
        for(auto followuser : userToFollowing[userId]){
            for(auto cur : userTweets[followuser]){
                pq.push(cur);
            }
        }
        while(!pq.empty() and count < 10){
            res.push_back(pq.top().second);
            pq.pop();
            count += 1;
        }
        return res;
        

    }
    
    void follow(int followerId, int followeeId) {
        userToFollowing[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        userToFollowing[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

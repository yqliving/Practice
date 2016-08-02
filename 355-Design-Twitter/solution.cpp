/*
这道题让我们设计个简单的推特，具有发布消息，获得新鲜事，添加关注和取消关注等功能。我们需要用两个哈希表来做，第一个是建立用户和其所有好友之间的映射，另一个是建立用户和其所有消息之间的映射。由于获得新鲜事是需要按时间顺序排列的，那么我们可以用一个整型变量cnt来模拟时间点，每发一个消息，cnt自增1，那么我们就知道cnt大的是最近发的。那么我们在建立用户和其所有消息之间的映射时，还需要建立每个消息和其时间点cnt之间的映射。这道题的主要难点在于实现getNewsFeed()函数，这个函数获取自己和好友的最近10条消息，我们的做法是用户也添加到自己的好友列表中，然后遍历该用户的所有好友，遍历每个好友的所有消息，维护一个大小为10的哈希表，如果新遍历到的消息比哈希表中最早的消息要晚，那么将这个消息加入，然后删除掉最早的那个消息，这样我们就可以找出最近10条消息了，参见代码如下：

*/
class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        cnt = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        follow(userId, userId);
        tweets[userId].insert({cnt++, tweetId});
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        map<int, int> top10;
        for (auto it = friends[userId].begin(); it != friends[userId].end(); ++it) {
            int t = *it;
            for (auto a = tweets[t].begin(); a != tweets[t].end(); ++a) {
                if (top10.size() > 0 && top10.begin()->first > a->first && top10.size() > 10) break;
                top10.insert({a->first, a->second});
                if (top10.size() > 10) top10.erase(top10.begin());
            }
        }
        for (auto it = top10.rbegin(); it != top10.rend(); ++it) {
            res.push_back(it->second);
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        friends[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            friends[followerId].erase(followeeId);
        }
    }
    
private:
    int cnt;
    unordered_map<int, set<int>> friends;
    unordered_map<int, map<int, int>> tweets;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
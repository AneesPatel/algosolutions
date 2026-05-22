class Solution {
public:
    int ID = 0;
    // Encodes a URL to a shortened URL.
    string URL = "http://tinyurl.com/";
    unordered_map<string, string> map; //short to long;
    string encode(string longUrl) {
        string temp = URL + to_string(ID);
        ID++;
        map[temp] = longUrl;
        return temp;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return map[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

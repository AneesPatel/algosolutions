class Solution {
public:
    int id = 0;
    string URL = "http://tinyurl.com/";
    unordered_map<string, string> code; //long url to short url conversion
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string convert = URL + to_string(id);
        code[convert] = longUrl;
        id++;
        return convert;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return code[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

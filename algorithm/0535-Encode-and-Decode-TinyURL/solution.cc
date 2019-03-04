class Solution {
 public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        auto search = encode_map_.find(longUrl);
        auto found  = search != encode_map_.end();
        if (not found) {
            size_t id = encode_map_.size();
            encode_map_.insert(std::make_pair(longUrl, id));
            decode_map_.insert(std::make_pair(id, longUrl));
            return prefix_ + std::to_string(id);
        } else {
            return prefix_ + std::to_string(encode_map_[longUrl]);
        }
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        auto s = shortUrl.erase(0, prefix_.size());
        char* end = nullptr;
        size_t id = std::strtoull(s.c_str(), &end, 10);
        return decode_map_[id];
    }

 private:
    const std::string prefix_ = "http://tinyurl.com/";
    std::unordered_map<std::string, size_t> encode_map_;
    std::unordered_map<size_t, std::string> decode_map_;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

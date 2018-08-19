class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        std::unordered_map<std::string, size_t> visit_count;
        for (auto s : cpdomains) {
            std::istringstream iss(s);
            size_t count;
            std::string domain;
            iss >> count >> domain;
            for (size_t cut = 0; cut != std::string::npos; cut = domain.find_first_of("."), domain = domain.substr(cut + 1, std::string::npos)) {
                if (visit_count.find(domain) == visit_count.end()) {
                    visit_count.insert({domain, count});
                } else {
                    visit_count[domain] += count;
                }
            }
        }
        std::vector<std::string> res;
        for (auto iter = visit_count.begin(); iter != visit_count.end(); ++iter) {
            res.emplace_back(std::to_string(iter->second) + " " + iter->first);
        }
        return res;
    }
};

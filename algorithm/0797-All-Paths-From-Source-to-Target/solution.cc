class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        std::vector<std::vector<int>> res;
        std::vector<int> path;
        if (not graph.empty()) {
            graph_dfs(graph, 0, graph.size() - 1, path, &res);
        }
        return res;
    }

private:
    void graph_dfs(const std::vector<std::vector<int>>& graph,
                                              const int src,
                                              const int dst,
                                       std::vector<int> path,
                         std::vector<std::vector<int>>* res) {
        path.push_back(src);
        if (src == dst) {
            res->push_back(path);
            return;
        } else {
            for (auto adj_node : graph[src]) {
                graph_dfs(graph, adj_node, dst, path, res);
            }
        }
    }
};

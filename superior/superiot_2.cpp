/*
C++のSTLを使用して、ディジストラアルゴリズムを実装するプログラムを作成してください。
このプログラムは、与えられた重み付きグラフの頂点間の最短経路を見つける必要があります。
chatgptにより作成．
*/

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <utility>
#include <fstream>
#include <sstream>

class Graph {
public:
    Graph(int num_vertices) : num_vertices_(num_vertices), adj_list_(num_vertices) {}

    void add_edge(int src, int dest, int weight) {
        adj_list_[src].push_back(std::make_pair(dest, weight));
        adj_list_[dest].push_back(std::make_pair(src, weight));
    }
    
    // Add your visualization function here
    void visualize(const std::string& output_filename) const {
        std::ofstream file(output_filename + ".dot");
        if (!file) {
            std::cerr << "Cannot open file for writing." << std::endl;
            return;
        }

        file << "graph G {\n";
        for (int src = 0; src < num_vertices_; ++src) {
            for (const auto& edge : adj_list_[src]) {
                int dest = edge.first;
                int weight = edge.second;
                if (src < dest) {
                    file << "    " << src << " -- " << dest << " [label=\"" << weight << "\"];\n";
                }
            }
        }
        file << "}\n";
        file.close();

        std::stringstream cmd;
        cmd << "dot -Tpng " << output_filename << ".dot -o " << output_filename << ".png";
        int result = std::system(cmd.str().c_str());
        if (result != 0) {
            std::cerr << "Failed to execute Graphviz command." << std::endl;
        }
    }

    std::vector<int> dijkstra(int start_vertex) const {
        std::vector<int> distances(num_vertices_, std::numeric_limits<int>::max());
        distances[start_vertex] = 0;

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        pq.push(std::make_pair(0, start_vertex));

        while (!pq.empty()) {
            int current_vertex = pq.top().second;
            int current_distance = pq.top().first;
            pq.pop();

            if (current_distance <= distances[current_vertex]) {
                for (const auto& edge : adj_list_[current_vertex]) {
                    int neighbor = edge.first;
                    int weight = edge.second;

                    int new_distance = current_distance + weight;
                    if (new_distance < distances[neighbor]) {
                        distances[neighbor] = new_distance;
                        pq.push(std::make_pair(new_distance, neighbor));
                    }
                }
            }
        }

        return distances;
    }

private:
    int num_vertices_;
    std::vector<std::vector<std::pair<int, int>>> adj_list_;
};

int main() {
    int num_vertices = 6;
    Graph graph(num_vertices);

    graph.add_edge(0, 1, 5);
    graph.add_edge(0, 2, 1);
    graph.add_edge(1, 2, 2);
    graph.add_edge(1, 3, 3);
    graph.add_edge(1, 4, 6);
    graph.add_edge(2, 3, 5);
    graph.add_edge(3, 4, 1);
    graph.add_edge(3, 5, 5);
    graph.add_edge(4, 5, 3);
    
    graph.visualize("graph_output");

    int start_vertex = 0;
    std::vector<int> distances = graph.dijkstra(start_vertex);

    std::cout << "Shortest distances from vertex " << start_vertex << ":\n";
    for (int i = 0; i < num_vertices; ++i) {
        std::cout << "To vertex " << i << ": " << distances[i] << std::endl;
    }

    return 0;
}

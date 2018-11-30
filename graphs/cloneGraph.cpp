#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

/*
 * - Problem:
 * Clone graph
 *
 * - Problem description:
 * Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
 */

// graph node definition
struct UndirectedGraphNode {
    string label;
    vector<UndirectedGraphNode*> neighbors;
    UndirectedGraphNode(string s) : label(s) {};
};

UndirectedGraphNode* cloneGraph(UndirectedGraphNode* graph) {
    if (graph == NULL) return NULL;

    queue<UndirectedGraphNode*> border;
    border.push(graph);

    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map;
    UndirectedGraphNode* clone = new UndirectedGraphNode(graph->label);
    map[graph] = clone;

    // for each node
    while (!border.empty()) {
        UndirectedGraphNode* currNode = border.front();
        border.pop();

        // for each neighbor
        for (UndirectedGraphNode* neighbor : currNode->neighbors) {
            // if no copy exists
            if (map.find(neighbor) == map.end()) {
                // create a new node in the cloned graph
                UndirectedGraphNode* neighborClone = new UndirectedGraphNode(neighbor->label);

                // set the created node as one of the neighbors of the current node in the cloned graph
                map[currNode]->neighbors.push_back(neighborClone);

                map[neighbor] = neighborClone; // add the neighbor to the map
                border.push(neighbor); // the neighbor should be cloned later
            // if a copy already exists
            } else {
                map[currNode]->neighbors.push_back(map[neighbor]);
            }
        }
    }

    return clone;
}

void cloneGraphTester() {
    UndirectedGraphNode* A = new UndirectedGraphNode("A");
    UndirectedGraphNode* B = new UndirectedGraphNode("B");
    UndirectedGraphNode* C = new UndirectedGraphNode("C");
    UndirectedGraphNode* D = new UndirectedGraphNode("D");

    A->neighbors.push_back(B);
    A->neighbors.push_back(C);
    B->neighbors.push_back(A);
    B->neighbors.push_back(C);
    C->neighbors.push_back(A);
    C->neighbors.push_back(B);
    C->neighbors.push_back(D);
    D->neighbors.push_back(C);

    cloneGraph(A);
}

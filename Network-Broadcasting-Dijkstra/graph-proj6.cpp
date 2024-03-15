/* CSI 3334
 * Project 6 - Network Broadcasting
 * Filename: graph-proj6.cpp
 * Student Name: Harrison Hassler
 * Due Date: 12/8/2023
 * Description: This file implements the functions in
 *    graph-proj6.h
 */

#include "graph-proj6.h"
#include "arrayheap-student-proj6.h"

/*
 * addEdge
 *
 * This method adds an edge connecting (from -> to) with the given cost
 *
 * Parameters: from: source vertex
 *             to:   destination vertex
 *             cost: cost of traversal
 *
 * Return value: none
 */
void Graph::addEdge(int from, int to, int cost){
    if(inVertexRange(from) && inVertexRange(to)){
        adjacencyList[from].push_back(Edge(to,cost));
    }
}

/*
 * dijkstra
 *
 * This method implements dijkstra's algorithim to find
 * the shortest paths from source to every vertex
 *
 * Parameters: from: source vertex
 *             to:   destination vertex
 *             cost: cost of traversal
 *
 * Return value: A vector of costs
 */
vector<int> Graph::dijkstra(int source) const{

    vector<int> distance(this->adjacencyList.size(), INFINITE_COST),
            keys(this->adjacencyList.size(),-1);
    ArrayHeap<pair<int, int>> front;
    distance[source] = 0;

    pair<int, int> s = {0, source};
    keys[source] = front.insert(s);

    while(front.getNumItems() != 0){
        int currV = front.getMinItem().second;
        front.removeMinItem();

        for(auto i = adjacencyList[currV].begin();
            i != adjacencyList[currV].end(); ++i){

            auto& neighbor = *i;
            int to = neighbor.to;
            int weight = neighbor.cost;
            if(distance[currV] + weight < distance[to]){
                distance[to] = weight + distance[currV];

                if(!front.isOnHeap(keys[to])) {
                    keys[to] = front.insert({distance[to], to});
                } else {
                    front.changeItemAtKey(keys[to], {distance[to], to});
                }
            }
        }
    }

    return distance;
}
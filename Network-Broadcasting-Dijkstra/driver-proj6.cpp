/* CSI 3334
 * Project 6 - Network Broadcasting
 * Filename: driver-proj6.cpp
 * Student Name: Harrison Hassler
 * Due Date: 12/8/2023
 * Description: This file finds the computers
 *              that function as the best servers.
 */


#include "arrayheap-student-proj6.h"
#include "graph-proj6.h"
#include <map>
#include <string>
#include <sstream>

using namespace std;

const int MAX = 1000000000;

const int SERVER_STRING = 7;

/*
 * isServer
 *
 * This method finds if the name is valid
 *
 * Parameters: computerName: a computers name
 *
 * Return value: returns true if the name is valid
 */
bool isServer(const string& computerName) {
    // Check if the computer name ends with "_server"
    return computerName.size() >= SERVER_STRING &&
           computerName.compare(computerName.size() - SERVER_STRING, SERVER_STRING, "_server") == 0;
}

/*  main
 *
 *  This function reads in the amount of edges in the network,
 *  and counts the unique vertices from the input to determine if each vertex
 *  is a server. A graph is created then the edges are added. Dijkstra's
 *  algorithm is used to calculate the shortest paths and stores the minimum
 *  total delay. The valid servers with the least total delay is output or it
 *  outputs that no server can serve the whole network.
 *
 *  Parameters: none
 *
 *  Return value: 0 if successful
 */
int main() {
    int connections;
    int cost;
    int minCost = MAX;
    int vCount = 0;
    map<string, int> Map;
    vector<bool> servers;
    vector<int> Array;
    string name1;
    string name2;
    stringstream inss;

    inss.clear();

    cin >> connections;

    //read information about each edge
    for (int i = 0; i < connections; ++i) {
        cin >> name1 >> name2 >> cost;
        inss << name1 << " " << name2 << " " << cost << endl;

        //finds if name1 is already in map
        if (Map.find(name1) == Map.end()) {
            Map[name1] = vCount;
            servers.push_back(name1.size() >= SERVER_STRING && name1.compare(name1.size()
            - SERVER_STRING, SERVER_STRING, "_server") == 0);
            vCount++;
        }
        //finds if name2 is already in map
        if (Map.find(name2) == Map.end()) {
            Map[name2] = vCount;
            servers.push_back(name2.size() >= SERVER_STRING && name2.compare(name2.size()
            - SERVER_STRING, SERVER_STRING, "_server") == 0);
            vCount++;
        }
    }

    //creates the graph
    Graph g(Map.size());

    for (int i = 0; i < connections; ++i) {
        inss >> name1 >> name2 >> cost;
        g.addEdge(Map[name1], Map[name2], cost);
    }


    for (int i = 0; i < servers.size(); ++i) {
        if (servers[i]) {
            Array.push_back(0);
            vector<int> allEdge = g.dijkstra(i);
            //calculate total delay for server at i
            for (int j = 0; j < servers.size(); ++j) {
                if (allEdge[j] >= 0 && Array[i] < MAX) {
                    Array[i] += allEdge[j];
                }
            }
            //update minimum total delay
            if (Array[i] >= 0) {
                minCost = min(minCost, Array[i]);
            }
        } else {
            Array.push_back(MAX);
        }
    }
    if (minCost >= MAX) {
        cout << "no server can serve the whole network" << endl;
    } else {
        cout << "total delay: " << minCost << endl;
        for (map<string, int>::iterator it = Map.begin(); it != Map.end(); ++it) {
            int ndx = it->second;
            if (servers[ndx] && Array[ndx] == minCost) {
                cout << it->first << endl;
            }
        }
    }

    return 0;
}


//
// Created by 庞泽钊 on 2020/11/9.
//

#ifndef ALNS_NODE_H
#define ALNS_NODE_H
#include <map>

class Node {

public:
    Node();
    int X;
    int Y;
    int C_NUM;
    int E_TIME;
    int L_TIME;
    int DEM;
    int S_TIME;
    bool is_depot = false;
    std::map<int, double>nbr_dis;
    Node(int, int, int, int, int, int, int);
    double GET_DIS(Node node);
    bool operator<(const Node&n)const;

};


#endif //ALNS_NODE_H

//
// Created by 庞泽钊 on 2020/11/9.
//

#include "Node.h"
#include<cmath>

Node::Node() {};
Node::Node(int NUM_, int X_, int Y_, int DEM_, int E_TIME_, int L_TIME_, int S_TIME_) {
    C_NUM = NUM_;
    X = X_;
    Y = Y_;
    DEM = DEM_;
    E_TIME = E_TIME_;
    L_TIME = L_TIME_;
    S_TIME = S_TIME_;
    if(C_NUM == 0)
        is_depot = true;
}

double Node::GET_DIS(Node node) {
    return sqrt(pow(X - node.X, 2) + pow(Y - node.Y, 2));
};

bool Node::operator<(const Node&n)const {
    return E_TIME <= n.E_TIME;
};
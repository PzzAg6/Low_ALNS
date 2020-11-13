//
// Created by 庞泽钊 on 2020/11/10.
//

#ifndef ALNS_SOLUTION_H
#define ALNS_SOLUTION_H
#include "Route.h"
#include <vector>

class Solution {
public:
    Solution(const Node&);
    void Route_Add(Route);
    void Route_Remove(std::vector<Route>::iterator);
    void SHOW_SOL();

private:
    int ROUTE_NUMBER = 0;
    double TOL_DISTANCE = 0.0;
    std::vector<Route>sol;
    Node Depot;
};


#endif //ALNS_SOLUTION_H

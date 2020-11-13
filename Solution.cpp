//
// Created by 庞泽钊 on 2020/11/10.
//

#include "Solution.h"
#include <iostream>
#include <iomanip>
Solution::Solution(const Node &Depot_) {
    Depot = Depot_;
}

void Solution::Route_Add(Route route) {
    sol.emplace_back(route);
    ROUTE_NUMBER++;
    TOL_DISTANCE += route.Tol_Distance();
}

void Solution::Route_Remove(std::vector<Route>::iterator del) {
    ROUTE_NUMBER--;
    TOL_DISTANCE -= del->Tol_Distance();
    sol.erase(del);
}

void Solution::SHOW_SOL() {
    std::cout << std::setw(11) << "Route No. " << std::setw(10) << "Detail" << std::endl;
    for(int i = 0; i < ROUTE_NUMBER; i++){
        std::cout << std::setw(5) << i + 1;
        std::cout << std::setw(10);
        sol[i].SHOW_ROUTE();
    }

}



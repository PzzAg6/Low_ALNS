//
// Created by 庞泽钊 on 2020/11/10.
//
#include <iostream>
#include "Route.h"
#include "Node.h"


Route::Route(Node depot_) {
    Depot = depot_;
    this->add(Depot);
    this->add(Depot);
    extern int V_CAPACITY;
    CUR_LOAD = V_CAPACITY;
    Tol_Time = 0.0;
}

void Route::add(Node node) {
    route.emplace_back(node);
    CUR_LOAD -= node.DEM;

}

void Route::insert(Node node, std::list<Node>::iterator pos) {
    route.insert(pos, node);
    CUR_LOAD -= node.DEM;
}

void Route::swap(Node &node_1, Node &node_2) {
    Node a = node_1;
    node_1 = node_2;
    node_2 = node_1;
}

void Route::remove(std::list<Node>::iterator pos) {
    route.erase(pos);
    CUR_LOAD += pos->DEM;
}

double Route::Tol_Distance(){
    double dist = 0;
    for(auto it = route.begin(); it != --route.end();)
        dist += DISTANCE(it->C_NUM, (++it)->C_NUM);
    //dist += it->GET_DIS(*(++it));
    this->length = dist;
    return dist;
}

void Route::SHOW_ROUTE(){
    auto it = route.begin();
    for(; it != --route.end(); it++)
        std::cout << it->C_NUM << " -> ";
    std::cout << it->C_NUM;
    std::cout << std::endl;
}

void Route::add_depot(){
    route.emplace_back(Depot);
}


double Route::Get_Time(){
    return Tol_Time;
}

void Route::Set_Time(double time) {
    Tol_Time = time;
}

int Route::Get_Load(){
    return CUR_LOAD;
};
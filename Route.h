//
// Created by 庞泽钊 on 2020/11/10.
//

#ifndef ALNS_ROUTE_H
#define ALNS_ROUTE_H
#include "Node.h"
#include <list>
#include "INPUT_DATA.h"

class Route {

public:
    Route();
    Route(Node node);
    void add(Node);
    void insert(Node, std::list<Node>::iterator pos);
    void swap(Node&, Node&);
    void remove(std::list<Node>::iterator pos);
    double Tol_Distance();
    void SHOW_ROUTE();
    void add_depot();
    double Get_Time();
    void Set_Time(double time);
    std::list<Node>route;
    int Get_Load();

private:

    double length;
    Node Depot;
    double Tol_Time;
    int CUR_LOAD;

};


#endif //ALNS_ROUTE_H

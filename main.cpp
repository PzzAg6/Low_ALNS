#include <iostream>
#include "Node.h"
#include "INPUT_DATA.h"
#include<string>
#include "Route.h"
#include "Solution.h"
#include "Gen_Init_Sol.h"
#include <set>
int main() {
    extern std::vector<Node>NODE_GROUP;

    std::string VRP("/Users/pangyusheng/Desktop/PROG/C++/ALNS/c101.txt");
    NODE_GROUP = INPUT(VRP);
//    SHOW_INPUT();
    Solution init(NODE_GROUP[0]);
    init = GEN_INIT(NODE_GROUP);
    std::cout << "Done." <<std::endl;
    init.SHOW_SOL();
    return 0;
}

void test(){
//    Route r1(NODE_GROUP[0]);
//    for(int i = 1; i <= 10; i++)
//        r1.add(NODE_GROUP[i]);
//    r1.add_depot();
//
//    Route r2(NODE_GROUP[0]);
//    for(int i = 1; i <= 10; i++)
//        r2.add(NODE_GROUP[i]);
//    r2.add_depot();
//
//    std::cout << DISTANCE(47, 66)<< std::endl;

//    std::set<Node>unvisited(++NODE_GROUP.begin(), NODE_GROUP.end());
//
//    Solution s;
//    s.Route_Add(r1);
//    s.Route_Add(r2);
//
//    s.SHOW_SOL();
}
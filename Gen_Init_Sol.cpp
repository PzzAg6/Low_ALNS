//
// Created by 庞泽钊 on 2020/11/12.
//

#include "Gen_Init_Sol.h"

#include "Solution.h"
#include "Node.h"
#include "Route.h"
#include "INPUT_DATA.h"
#include <set>
#include <vector>

extern int V_CAPACITY;

Solution GEN_INIT(std::vector<Node>&group){
    std::set<Node>unvisited(++group.begin(), group.end());
    Solution init_sol(group[0]);
    /*
     * 这样做很容易O(n^2)
     * 是不是可以随机选出一组点来加进去就行了
     */
    while(!unvisited.empty()){
        bool change_route = false;
        Route* R = new Route(group[0]);
        std::set<Node>::iterator lb;
        std::list<Node>::iterator ppos;
        while(!change_route && !unvisited.empty()){//change_route = true跳出循环,添加新route,否则保持原有route
            double min_cost = 1e5;
            for(auto unv = unvisited.begin(); unv != unvisited.end(); unv++)
                for(auto r = R->route.begin(); r != --(R->route.end()); r++){
                    int cur = (r++)->C_NUM;
                    int next = (r--)->C_NUM;
                    if(DISTANCE(cur, unv->C_NUM) +
                       DISTANCE(unv->C_NUM, next) -
                       DISTANCE(cur, next) <= min_cost){
                        min_cost = DISTANCE(cur, unv->C_NUM) +
                                   DISTANCE(unv->C_NUM, next) -
                                   DISTANCE(cur, next);
                        lb = unv;
                        ppos = ++r;
                        r--;
                    }

                }
            if(R->Get_Load() - lb->DEM >= 0){
                //指针不能乱用
                unvisited.erase(lb);
                R->insert(group[lb->C_NUM], ppos);//无法使用insert(ppos, *lb)
            }
            else{
                init_sol.Route_Add(*R);
                change_route = true;
                delete R;
            }
        }




    }
    return init_sol;

}


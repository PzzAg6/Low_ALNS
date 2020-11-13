//
// Created by 庞泽钊 on 2020/11/9.
//

#ifndef ALNS_INPUT_DATA_H
#define ALNS_INPUT_DATA_H
#include "Node.h"
#include<string>
#include<vector>
#include <list>


extern std::string VRP_FILE;
static int TOL_CUM_NUM;

std::vector<Node> INPUT(std::string path);
void SHOW_INPUT(int);//int to choose mode
double DISTANCE(int, int);

#endif //ALNS_INPUT_DATA_H

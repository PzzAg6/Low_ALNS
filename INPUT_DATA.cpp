//
// Created by 庞泽钊 on 2020/11/9.
//
#include "Node.h"
#include "INPUT_DATA.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
using namespace std;
int V_NUM;
int V_CAPACITY;
std::vector<Node>NODE_GROUP;


vector<Node> INPUT(std::string path) {
    stringstream num_line;//ss流，用于string 2 int
    ifstream ReadFile;//文件输入流
    ReadFile.open(path);
    string line;//读取行
    bool found = false;
    if (ReadFile.is_open()) {
        cout << "Open Success!" << endl;
        while (!ReadFile.eof()) {
            getline(ReadFile, line, '\n');
            if (line == "VEHICLE\r") {
                int time = 2;
                cout <<"FOUND VEHICLE" << endl;
                while (--time)
                    getline(ReadFile, line);
                getline(ReadFile, line);
                num_line << line;
                num_line >> V_NUM >> V_CAPACITY;
                break;
            }
        }
        while (!ReadFile.eof()) {
            getline(ReadFile, line, '\n');
            if (line == "CUSTOMER\r") {
                cout << "FOUND CUSTOMER!" << endl;
                found = true;
                int time = 2;
                while (time--)
                    getline(ReadFile, line);
                continue;
            }
            if(found) {
                int *p = new int[7];
                num_line << line;
                num_line >> p[0] >> p[1] >> p[2] >> p[3] >> p[4] >> p[5] >> p[6];
                NODE_GROUP.emplace_back(Node(p[0], p[1], p[2], p[3], p[4], p[5], p[6]));
                delete[]p;
                num_line.clear();
            }
            }
        }
    for(auto it = NODE_GROUP.begin(); it != NODE_GROUP.end(); it++)
        for(auto itt = it; itt != NODE_GROUP.end(); itt++){
            if(itt ==it)
                it->nbr_dis[itt->C_NUM] = 0;// it->GET_DIS(*itt);
            else{
                double *ps = new double;
                *ps = it->GET_DIS(*itt);
                it->nbr_dis[itt->C_NUM] = *ps;
                itt->nbr_dis[it->C_NUM] = *ps;
                delete ps;
            }
        }

    ReadFile.close();
    return NODE_GROUP;

//    for(auto it = NODE_GROUP.begin(); it != NODE_GROUP.end(); it++)
//        cout <<"No. " <<  it->C_NUM <<" X: " << it->X << " Y: " << it->Y <<
//        " DEMAND: "<< it->DEM << " E_TIME: "<< it->E_TIME << " L_TIME: "<< it->L_TIME << " S_TIME: "<< it->S_TIME << endl;
}

void SHOW_INPUT(int mode = 1){
    cout << "V_NUM: " << V_NUM << endl;
    cout << "V_CAPACITY: " << V_CAPACITY << endl;
    switch (mode) {
        case 1:{
            cout << right;

            cout << setw(6) << "No. " << setw(6) << "X: " << setw(6) << "Y: " << setw(10) << "DEMAND"
                 << setw(10) << "E_TIME" << setw(10) << "L_TIME" << setw(10)  << "S_TIME" << endl;

            for(auto it = NODE_GROUP.begin(); it != NODE_GROUP.end(); it++)
                cout <<setw(4)<<  it->C_NUM << setw(6) << it->X << setw(6) << it->Y <<
                     setw(10)<< it->DEM << setw(10)<< it->E_TIME << setw(10)<< it->L_TIME << setw(10)<< it->S_TIME << endl;
            break;
        }
        case 2:{
            for(auto it = NODE_GROUP.begin(); it != NODE_GROUP.end(); it++){
                for(auto itt = NODE_GROUP.begin(); itt != NODE_GROUP.end(); itt++)
                    std::cout << DISTANCE(it->C_NUM, itt->C_NUM) << " ";
                std::cout << std::endl;
            }
            break;
        }

    }



}

double DISTANCE(int i, int j){
    return NODE_GROUP[i].nbr_dis[j];
}

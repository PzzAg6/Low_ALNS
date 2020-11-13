# ALNS X VRPTW

## main.h

## Repair.h

## Destroy.h

## Input.h

OK

## Output.h 


## Node.h
OK  

## Route.h
OK，但是待改进.
目前的问题就是迭代器，另外可能需要重载`[]`运算符
## Solution.h
OK，也是迭代器的问题

## Initializing.h

## Accepted.h

Solomon benchmark中，时间与距离相等：  

> The larger problems are 100 customer euclidean problems where travel times equal the corresponding distances.

如何设置节点类，以及路径类是一个关键

关于repair.h和destroy.h里面的函数，都用函数指针调用
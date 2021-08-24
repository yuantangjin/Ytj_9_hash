#pragma once
#include "Search.h"
class DFS :
    public Search
{
public:
    DFS(std::function<bool(int, int)> fun);

    //使用算法寻找路径
    //start     起点坐标
    //end       终点坐标
    std::vector<Pos> find(Pos start, Pos end);
private:
    bool is_end;            //是否达到终点
    Pos end;                //表示终点坐标

    //递归寻找路径
    void _find(Pos now);
};


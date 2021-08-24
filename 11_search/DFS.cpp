#include "DFS.h"

DFS::DFS(std::function<bool(int, int)> fun)
    :Search(fun)
{
}

std::vector<Pos> DFS::find(Pos start, Pos end)
{
    is_end = false;                 //终点设置为false
    path.clear();                   //清理上一次走的路径
    this->end = end;
    path.push_back(start);          //起点坐标加入路径
    _find(start);
    return path;
}

void DFS::_find(Pos now)
{
    static const Pos dir[4] = {
        {0,1},          //下
        {1,0},          //右
        {-1,0},         //左
        {0,-1},         //上
    };


    //判断是否到达终点
    if (now.x==end.x&&now.y==end.y)
    {
        is_end = true;
        return;
    }

    //循环遍历上下左右4个方向
    for (int i = 0; i < 4; i++)
    {
        //准备移动的路径
        Pos move(now.x + dir[i].x, now.y + dir[i].y);
        //判断是否到达终点
        //判断是否是（合法有效）可以移动的位置
        if (!is_end&&inAear(move))
        {
            //保存走过的路径
            path.push_back(move);
            //递归调用自己
            _find(move);
        }
    }
}

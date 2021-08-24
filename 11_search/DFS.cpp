#include "DFS.h"

DFS::DFS(std::function<bool(int, int)> fun)
    :Search(fun)
{
}

std::vector<Pos> DFS::find(Pos start, Pos end)
{
    is_end = false;                 //�յ�����Ϊfalse
    path.clear();                   //������һ���ߵ�·��
    this->end = end;
    path.push_back(start);          //����������·��
    _find(start);
    return path;
}

void DFS::_find(Pos now)
{
    static const Pos dir[4] = {
        {0,1},          //��
        {1,0},          //��
        {-1,0},         //��
        {0,-1},         //��
    };


    //�ж��Ƿ񵽴��յ�
    if (now.x==end.x&&now.y==end.y)
    {
        is_end = true;
        return;
    }

    //ѭ��������������4������
    for (int i = 0; i < 4; i++)
    {
        //׼���ƶ���·��
        Pos move(now.x + dir[i].x, now.y + dir[i].y);
        //�ж��Ƿ񵽴��յ�
        //�ж��Ƿ��ǣ��Ϸ���Ч�������ƶ���λ��
        if (!is_end&&inAear(move))
        {
            //�����߹���·��
            path.push_back(move);
            //�ݹ�����Լ�
            _find(move);
        }
    }
}

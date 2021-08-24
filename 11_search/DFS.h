#pragma once
#include "Search.h"
class DFS :
    public Search
{
public:
    DFS(std::function<bool(int, int)> fun);

    //ʹ���㷨Ѱ��·��
    //start     �������
    //end       �յ�����
    std::vector<Pos> find(Pos start, Pos end);
private:
    bool is_end;            //�Ƿ�ﵽ�յ�
    Pos end;                //��ʾ�յ�����

    //�ݹ�Ѱ��·��
    void _find(Pos now);
};


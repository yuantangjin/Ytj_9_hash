#pragma once
#include<functional>
#include<vector>
//����Ľṹ��
struct Pos
{
	int x;
	int y;
	Pos(int x=0,int y=0):x(x),y(y){}
};
//�����㷨���࣬��װ��һЩ���õĹ���
class Search
{
public:
	//�����㷨
	Search(std::function<bool(int,int)> func);
protected:
	//����һ��������������ͨ���ⲿ�������ݺϷ��Ե��жϺ���
	std::function<bool(int, int)> func;

	//��ʾ�Ѿ��߹���·��
	std::vector<Pos> path;

	//�ж�����·�Ƿ��Ѿ��߹���
	bool isVisited(Pos pos);

	//���·������Ч��
	bool inAear(Pos pos);
};


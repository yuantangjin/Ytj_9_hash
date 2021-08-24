#include<iostream>
#include<Windows.h>
#include"Draw.h"
#include"DFS.h"
using namespace std;

vector<vector<int>> level_map{
	{0,0,1,0,1,0},
	{1,0,0,0,0,0},
	{1,0,1,1,1,0},
	{1,0,0,0,1,1},
	{0,0,1,0,0,0},
	{1,0,1,0,1,0}
};
bool check(int x, int y) {
	auto& l = level_map;
	//��ͼ����Խ��
	//��ͼ����Ϊ1
	if (y < 0 || y >= l.size()
		|| x<0||x>=l[y].size()|| l[y][x]==1)
	{
		return	false;
	}
	return true;
}
void test() {
	Draw draw(600, level_map);
	draw.update();
	system("pause");
}


void test2() {
	DFS dfs(check);
	Pos start;
	Pos end(5, 5);
	Draw draw(600, level_map);
	draw.level[end.y][end.x] = Draw::end;			//�����յ�
	draw.update();
	auto path = dfs.find(start, end);		//��ʼѰ·
	//����·��
	for (auto p:path)
	{
		draw.level[p.y][p.x] = Draw::visit;		//·�������Ѿ��߹���
		draw.update();							//���µ�ͼ
		Sleep(500);
	}
	system("pause");
}
int main() {
	//test();
	test2();
}
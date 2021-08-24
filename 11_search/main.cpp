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
	//地图不能越界
	//地图不能为1
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
	draw.level[end.y][end.x] = Draw::end;			//设置终点
	draw.update();
	auto path = dfs.find(start, end);		//开始寻路
	//遍历路径
	for (auto p:path)
	{
		draw.level[p.y][p.x] = Draw::visit;		//路径设置已经走过了
		draw.update();							//更新地图
		Sleep(500);
	}
	system("pause");
}
int main() {
	//test();
	test2();
}
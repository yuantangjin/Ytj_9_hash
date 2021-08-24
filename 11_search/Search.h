#pragma once
#include<functional>
#include<vector>
//坐标的结构体
struct Pos
{
	int x;
	int y;
	Pos(int x=0,int y=0):x(x),y(y){}
};
//搜索算法的类，封装了一些常用的功能
class Search
{
public:
	//搜索算法
	Search(std::function<bool(int,int)> func);
protected:
	//定义一个函数适配器，通过外部传入数据合法性的判断函数
	std::function<bool(int, int)> func;

	//表示已经走过的路径
	std::vector<Pos> path;

	//判断这条路是否已经走过了
	bool isVisited(Pos pos);

	//检查路径的有效性
	bool inAear(Pos pos);
};


#include "Draw.h"
#include "easyx.h"		//图形库文件
#include <string>
#include "graphics.h"
#include <iostream>
using namespace std;

Draw::Draw(int length, Vec2r& level)
  :length(length)
{
  initgraph(length, length, SHOWCONSOLE);		//初始化图形库,SHOWCONSOLE表示显示控制台
  size = length / level.size();					//动态计算小方块的宽度
  this->level=level;							//从外部传入地图
}

Draw::~Draw()
{
  closegraph();
}

void Draw::update()
{
  draw();
  text();
}

int Draw::getSize()
{
  return size;
}

void Draw::draw()
{
  BeginBatchDraw();
  cleardevice();
  for (size_t i = 0; i < level.size(); i++)
  {
	for (size_t j = 0; j < level[i].size(); j++)
	{
	  if (level[i][j] == road)//路
	  {
		setfillcolor(RGB(0xdd, 0xdd, 0xdd)); //设置路的颜色
	  }
	  else  if (level[i][j] == wall){  //墙
		setfillcolor(RGB(0x33, 0x33, 0xcc));
	  }
	  else  if (level[i][j] == visit) {	  //走过的路
		setfillcolor(RGB(0x33, 0xcc, 0x33));
	  }
	  else  if (level[i][j] == Draw::end) {	  //终点
		setfillcolor(RGB(0xff, 0x33, 0x33));
	  }
	  rect(j, i);	//j代表x  i代表y
	}
  }
  EndBatchDraw();
}

void Draw::text()
{
  string m;
  for (size_t i = 0; i < level.size(); i++)
  {
	for (size_t j = 0; j < level[i].size(); j++)
	{
	  if (level[i][j] == road)//路
	  {
		m += "  "; //设置路的颜色
	  } 
	  else  if (level[i][j] == wall) {  //墙
		m += "+ ";
	  } 
	  else  if (level[i][j] == visit) {	  //走过的路
		m += ". ";
	  } 
	  else  if (level[i][j] == Draw::end) {	  //终点
		m += "= ";
	  }
	}
	m += "\n";
  }
  system("cls");	  //调用命令清屏
  //clrcle();		//清屏函数  Linux上用
  cout << m << endl;
}

void Draw::rect(int x, int y) {
  fillrectangle(x*size, y*size, (x + 1)*size, (y + 1)*size);
}

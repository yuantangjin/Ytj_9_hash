#pragma once
#ifndef DRAW_H
#define DRAW_H

#include <vector>

//给类模板取别名
using Vec2r = std::vector<std::vector<int>>;

//绘制地图的类
class Draw
{
public:
  /*使用图形库的接口实现地图绘制
   *length  屏幕长度
    level   地图关卡
   */
  Draw(int length, Vec2r& level);
  ~Draw();
  /*
  0 路
  1 墙
  2 走过的路径
  3 终点
  */
  enum {
	road=0,
	wall,
	visit,
	end,
  }; 
  Vec2r level;   //绘制的地图上

  //地图更新函数
  void update();

  //获取瓦片大小
  int getSize();

protected:

  int length;			    //宽度和高度
  int size;				    //每个瓦片的大小
  void draw();              //绘制地图
  void text();              //绘制文本
  void rect(int x,int y);   //绘制瓦片

};

#endif // !DRAW_H
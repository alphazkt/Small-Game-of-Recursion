# Small-Game-of-Recursion
A small game of recursion; 一个简单的小代码实现递归
在一个w*h的区域中有若干卡片，寻找两个卡片之间是否有路径相连，路径不能穿越卡片。路径可以在区域外部通行
输入
  棋盘大小w,h， 棋盘内卡片的放置情况， 起始卡片位置，目标卡片位置
输出
  两个卡片之间的最短所需线段数，并非所经过的格子个数，而是连接两个卡片之间所需线段即路径转弯次数。
  
  例：
  4 4 
  
  xxxx 
  xx x 
  xx x  
  xxxx 
  
  2 2 4 2
  output: impossible
  
  2 2 4 3
  output: 2
  
  1 3 4 4
  output: 4
  

#include <iostream>
#include "linkStack.h"
using namespace std;

 void traverse(int arr[12][12])
{
	for (int i = 0; i < 12; ++i)
	{
		for (int j = 0; j < 12; ++j)
			cout << arr[i][j] << " ";
		cout << endl;
	}
}
 int main()
 {
	 int a[12][12] = { {0,0,0,0,0,0,0,0,0,0}, {0,1,1,0,0,0,0,0,1,1,1,0},{0,0,1,0,1,1,1,1,1,0,0,0},{0,0,1,1,1,0,0,1,0,0,0,0},{0,0,0,1,0,0,0,1,0,0,0,0},{0,0,0,1,0,0,0,1,1,1,0,0},{0,0,1,1,0,0,0,1,0,0,0,0},{0,0,0,1,1,1,1,1,0,0,0,0},{0,0,0,1,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,1,1,1,1,1,0},{0,0,0,0,0,0,1,0,0,1,1,0} };
	 cout << "迷宫为：" << endl;
	 traverse(a);
	 cout << "表示方法：(行，列），（1，1）为起点，（11，0）为终点." << endl;
	 cout << "路径为：" << endl;
	 linkStack<int> maze;
	 linkStack<int> dot;
	 int i = 1, j = 1;
	 a[i][j] = 0;
	 while (i != 10 || j != 10)
	 {
		 if (a[i - 1][j] + a[i][j - 1] + a[i + 1][j] + a[i][j + 1] >= 2)
		 {
			 dot.push(10 * i + j);
		 }
		 while (a[i - 1][j] == 1 || a[i][j - 1] == 1 || a[i + 1][j] == 1 || a[i][j + 1] == 1)
		 {

			 maze.push(10 * i + j);
			 if (a[i - 1][j] + a[i][j - 1] + a[i + 1][j] + a[i][j + 1] >= 2)
			 {
				 dot.push(10 * i + j);
			 }
			 if (a[i - 1][j] == 1)
			 {
				 a[i - 1][j] = 0;
				 i = i - 1;
			 }
			 else if (a[i][j - 1] == 1)
			 {
				 a[i][j - 1] = 0;
				 j = j - 1;

			 }
			 else if (a[i + 1][j] == 1)
			 {
				 a[i + 1][j] = 0;
				 i = i + 1;
			 }
			 else if (a[i][j + 1] == 1)
			 {
				 a[i][j + 1] = 0;
				 j = j + 1;
			 }
			 if (i == 10 && j == 10)
			 {
				 break;
			 }

		 }
		 if (i == 10 && j == 10)
		 {
			 break;
		 }
		 maze.push(10 * i + j);
		 while ( i != dot.top() / 10 || j != dot.top() % 10)
		 {
			 maze.pop();
			 i = maze.top() / 10;
			 j = maze.top() % 10;
		 }
	 }
	 maze.push(110);
	 while (!maze.isEmpty())
	 {
		 cout << "(" << maze.top() / 10 << "," << maze.top() % 10 << ")<-";
		 maze.pop();
	 }
	 cout << "迷宫开始";
 }
	

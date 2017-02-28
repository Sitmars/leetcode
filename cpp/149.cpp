/*
149. Max Points on a Line

Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*/
/**
* Definition for a point.
* struct Point {
*     int x;
*     int y;
*     Point() : x(0), y(0) {}
*     Point(int a, int b) : x(a), y(b) {}
* };
*/


#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<time.h>

using namespace std;

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

int maxPoints(vector<Point>&);
int getgcd(int, int);

int main()
{
	srand(time(0));
	vector<Point> points = { {40,-23},{9,138},{429,115},{50,-17},{-3,80},{-10,33},{5,-21},{-3,80},{-6,-65},{-18,26},{-6,-65},{5,72},{0,77},{-9,86},{10,-2},{-8,85},{21,130},{18,-6},{-18,26},{-1,-15},{10,-2},{8,69},{-4,63},{0,3},{-4,40},{-7,84},{-8,7},{30,154},{16,-5},{6,90},{18,-6},{5,77},{-4,77},{7,-13},{-1,-45},{16,-5},{-9,86},{-16,11},{-7,84},{1,76},{3,77},{10,67},{1,-37},{-10,-81},{4,-11},{-20,13},{-10,77},{6,-17},{-27,2},{-10,-81},{10,-1},{-9,1},{-8,43},{2,2},{2,-21},{3,82},{8,-1},{10,-1},{-9,1},{-12,42},{16,-5},{-5,-61},{20,-7},{9,-35},{10,6},{12,106},{5,-21},{-5,82},{6,71},{-15,34},{-10,87},{-14,-12},{12,106},{-5,82},{-46,-45},{-4,63},{16,-5},{4,1},{-3,-53},{0,-17},{9,98},{-18,26},{-9,86},{2,77},{-2,-49},{1,76},{-3,-38},{-8,7},{-17,-37},{5,72},{10,-37},{-4,-57},{-3,-53},{3,74},{-3,-11},{-8,7},{1,88},{-12,42},{1,-37},{2,77},{-6,77},{5,72},{-4,-57},{-18,-33},{-12,42},{-9,86},{2,77},{-8,77},{-3,77},{9,-42},{16,41},{-29,-37},{0,-41},{-21,18},{-27,-34},{0,77},{3,74},{-7,-69},{-21,18},{27,146},{-20,13},{21,130},{-6,-65},{14,-4},{0,3},{9,-5},{6,-29},{-2,73},{-1,-15},{1,76},{-4,77},{6,-29} };
	//vector<Point> points = { {4,0},{4,-1},{4,5} };
	//vector<Point> points = { { 0,0 },{ 94911151,94911150 },{ 94911151,94911152 } };
	//vector<Point> points = { {0, -1}, {0, 3}, {0, -4}, {0, -2}, {0, -4}, {0, 0}, {0, 0}, {0, 1}, {0, -2}, {0, 4} };
	//vector<Point> points = { {0, -12}, {5, 2}, {2, 5}, {0, -5}, {1, 5}, {2, -2}, {5, -4}, {3, 4}, {-2, 4}, {-1, 4}, {0, -5}, {0, -8}, {-2, -1}, {0, -11}, {0, -9} };
	/*for (int i = 0; i < 3; ++i)
	{
		points.push_back(Point(rand()%10, rand()%10));
	}*/
	int num = maxPoints(points);
	cout << num << endl;

	system("pause");
	return 0;
}

int maxPoints(vector<Point>& points)
{
	int num = 0;
	for (int i = 0; i < points.size(); ++i)
	{
		int samepoint = 1;
		unordered_map<int, unordered_map<int, int>> lines;
		for (int j = i + 1; j < points.size(); ++j)
		{
			int x = points[i].x - points[j].x;
			int y = points[i].y - points[j].y;
			if (x == 0 && y == 0)
			{
				samepoint += 1;
				continue;
			}
			int gcd = getgcd(x, y);
			if (gcd != 0)
			{
				x /= gcd;
				y /= gcd;
			}
			if (lines.find(x) == lines.end())
			{
				lines[x].insert(pair<int, int>(y, 1));
			}
			else
			{
				lines.find(x)->second[y] += 1;
			}
		}
		int subnum = 0;
		for (auto itx = lines.begin(); itx != lines.end(); ++itx)
		{
			if (itx->first == 0)
			{
				int horizon = 0;
				for (auto ity = itx->second.begin(); ity != itx->second.end(); ++ity)
				{
					horizon += ity->second;
				}
				subnum = max(subnum, horizon);
				continue;
			}
			for (auto ity = itx->second.begin(); ity != itx->second.end(); ++ity)
			{
				subnum = max(subnum, ity->second);
			}
		}
		subnum += samepoint;
		num = max(num, subnum);
	}
	return num;
}

int getgcd(int x, int y)
{
	if (x == 0)
	{
		return 1;
	}
	if (y == 0)
	{
		return x;
	}
	else
	{
		return getgcd(y, x%y);
	}
}
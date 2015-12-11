/*
 * 面试题8.7.3 给定直角坐标系的两条线，确定这两条线会不会相交。
 */

#include <iostream>
#include <cstdlib>

/*
* 分析：若两条线是相同的（斜率和y轴截距相等），则认为这两条线相交。
* 两条线若不平行则必相交。因此要检查两条线相交与否，只需检查两者斜率是否相等或者是否为同一条。
*/

/************************************************************************/
/* 这类问题需注意：
   多提问，此题存在诸多不明之处，多提问以厘清问题；
   尽量设计并使用数据结构，借此展示了解并注重面向对象设计；
   不要假设斜率和y轴截距就是整数；
   了解浮点表示法的限制，不要用==检查浮点数是否相等，而是应该检查两者差值是否小于某个极小值；
 */
/************************************************************************/
class Line{
public:
	static double epsion;
	double slope; //斜率
	double yintercept; //y轴截距

	Line(double s, double y) :slope(s), yintercept(y){}

	bool isIntersect(Line &line)
	{
		return abs(this->slope - line.slope) > epsion || abs(this->yintercept - line.yintercept) < epsion;
	}
};

double Line::epsion = 0.000001;

int main()
{

}
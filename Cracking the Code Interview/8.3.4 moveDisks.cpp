/*
* 面试题8.3.4 经典汉诺塔问题
* 运用栈编写程序将所有盘子从第一根柱子移到最后一根柱子。
*/

#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;

class Tower{
public:
	Tower(int i)
	{
		idx = i;
	}

	int index()
	{
		return idx;
	}

	void add(int d)
	{
		if (!disks.empty() && disks.top() <= d)
		{
			cout << "error placing disk" << endl;
		}
		else
		{
			disks.push(d);
		}
	}

	void moveTopTo(Tower *t)
	{
		int top = disks.top();
		disks.pop();

		t->add(top);
		cout << "move disk " << top << " from " << this->index() << " to " << t->index() << endl;
	}

	void moveDisks(int n, Tower *destination, Tower *buffer)
	{
		if (n > 0)
		{
			this->moveDisks(n - 1, buffer, destination);
			this->moveTopTo(destination);
			buffer->moveDisks(n - 1, destination, this);
		}
	}

private:
	stack<int> disks;
	int idx;
};

int  main()
{
	Tower *source = new Tower(1);
	Tower *buffer = new Tower(2);
	Tower *des = new Tower(3);

	for (int i = 4; i > 0; --i)
	{
		source->add(i);
	}//for

	source->moveDisks(4, des, buffer);

	system("pause");
	return 0;
}
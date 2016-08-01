/*9.6 ’€÷ΩŒ Ã‚*/

#include <iostream>
#include <cstdlib>

using namespace std;

void printProcess(int i, int n, bool down)
{
	if (i > n)
		return;

	printProcess(i + 1, n, true);
	cout << (down ? "down" : "up") << endl;
	printProcess(i + 1,n, false);
}
void printAllFolds(int n)
{
	printProcess(1, n, true);
}

int main()
{
	printAllFolds(3);

	system("pause");
	return 0;
}
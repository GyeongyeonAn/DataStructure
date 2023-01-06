#include <iostream>
#include <set>

using namespace std;

int main()
{
	// С§Че
	set<int> ints;
	
	for (int i = -100; i <= 100; i++)
	{
		ints.insert(i * i);		// Ignores duplicates: (-3)*(-3) == (3)*(3)
								// insert result : 101 value (0, 1, 4, 9...10000)
	}

	cout << "Size of 'is' : " << ints.size() << endl;

	ints.erase(50);				// Does nothing
	ints.erase(9);				// Remove 9
	cout << "Size of 'is' : " << ints.size() << endl;

	return 0;
}
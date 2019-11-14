// BTS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "BTS.h"

void treeContains(const BST<int> & tree, int value) {
	bool r = tree.contains(value);
	std::cout << "The tree ";

	if (!r) {
		std::cout << "doesn't ";
	}

	std::cout << "contains " << value << std::endl;
}


int main()
{
	BST<int> t{};

	treeContains(t, 5);
	int i = 0;
	printf("STEP %d : ", i++); t.print();
	t.insert(4);
	printf("STEP %d : ", i++); t.print();
	t.insert(2);
	printf("STEP %d : ", i++); t.print();
	t.insert(7);
	printf("STEP %d : ", i++); t.print();
	t.insert(5);
	treeContains(t, 5);
	treeContains(t, 1);
	treeContains(t, 3);
	treeContains(t, 4);

	printf("STEP %d : ", i++); t.print();
	t.insert(3);
	printf("STEP %d : ", i++); t.print();
	t.insert(6);
	printf("STEP %d : ", i++); t.print();
	t.insert(8);
	printf("STEP %d : ", i++); t.print();
	t.remove(7);
	treeContains(t, 3);
	treeContains(t, 6);
	treeContains(t, 7);
	treeContains(t, 8);

	printf("STEP %d : ", i++); t.print();

	std::cout << " iterator ";

	for (int i : t) {
		std::cout << i << " ";
	}

    std::cout << "\n";
}

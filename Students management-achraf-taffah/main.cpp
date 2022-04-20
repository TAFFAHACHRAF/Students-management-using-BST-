#include<stdlib.h>
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<assert.h>
#include"BST.hpp"
#include"ETUDIANTS.hpp"
int main(){
	BST<int> *b=new BST<int>();
	b->add(1);
	b->add(2);
	b->add(3);
	b->add(4);
	b->add(157943);
	b->add(110);
	b->add(777);
	b->add(987);
	b->add(157);
	b->deleteNode(5);
	b->print();
	std::cout << "The root is : " << b->getRoot() << "\n";
	std::cout << "The max is : " << b->getMax() << "\n";
	std::cout << "The min is : " << b->getMin() << "\n";
	std::cout << "The size is : " << b->getSize() << "\n";
	return 0;
}

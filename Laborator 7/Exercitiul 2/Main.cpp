#include <iostream>
#include "Tree.h"
bool compare(int a, int b)
{
	if (a > b)
		return true;
	return false;
}
int main()
{
	Node<int> t(10);
	Node<int>* p1 = &t;
	p1->add_node(2);
	p1->add_node(7);
	Node<int>** ch1 = p1->getChildren();
	Node<int>* p2 = ch1[0]; //primul copil al lui p1
	p2->add_node(13);
	p2->add_node(20);
	p2->add_node(5);
	p2->insert(2, 7);
	Node<int>* p3 = ch1[1]; // al doilea copil al lui p1
	p3->add_node(20);
	p3->add_node(1);
	p3->insert(2, 2);
	p3->add_node(6);
	p3->sort(compare);
	std::cout << p1->getKey() << '\n';
	p1->print();
	std::cout << '\n';
	p2->print();
	p3->print();
	Node<int>* c;
	c = p1->find(2);
	std::cout << '\n';
	c->print();
	std::cout << '\n' << p1->count() << '\n';
	p1->delete_node(p2->getChildren()[1]);
	p1->BFS();
	//p1->BFS();
	return 0;
}
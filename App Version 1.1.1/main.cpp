#include"BST.hpp"
int main(){
	float t[8]={18,7,19,17,15,16,0,20};
	float t2[8]={18,7,11,17,16,16,2.5,10};
	Etudiants *e=new Etudiants("Achraf",t);
	Etudiants *e2=new Etudiants("Anas",t2);
	Etudiants *e3=new Etudiants("Ali",t);
	Etudiants *e4=new Etudiants("Rachid",t);
	
	BST *b=new BST();
	b->add(e);
	b->add(e2);
	b->add(e3);
	b->add(e4);
	
	b->print();
	std::cout<<"__________________\n";
	b->getMin()->data->print();	
	std::cout<<"__________________\n";
	b->getMax()->data->print();	
	return 0;
}

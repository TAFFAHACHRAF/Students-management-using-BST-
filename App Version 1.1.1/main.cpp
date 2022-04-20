#include"BST.hpp"
int main(){
	float t[8]={18,7,19,17,15,16,0,20};
	float t2[8]={11,15,11,0,16,4,2.5,10};
	float t3[8]={5,7,11,5,16,16,2.5,5};
	float t4[8]={11,7,11,11,16,1,2.5,10};
	
	Students *e=new Students("Achraf",t);
	Students *e2=new Students("Anas",t2);
	Students *e3=new Students("Ali",t);
	Students *e4=new Students("Rachid",t);
	
	BST *b=new BST();
	b->add(e);
	b->add(e2);
	b->add(e3);
	b->add(e4);
	
	b->print();
	b->getMax()->data->print();	
	b->getMin()->data->print();	
	b->emptyTree();
//	b->getTreeNode(0)->data->print();
	return 0;
}

#include<iostream>
#include<string>
#include<assert.h>
using namespace std;

class student{
	private:
		int mtr;
		string nom;
		float note[8];
	public:
		static int mtrCourant;
		student(){
			mtr=0;
			nom="";
			for(int i=0;i<8;i++)
				note[i]=0;
		}
		student(string nom,float note[]){
			mtr=mtrCourant++;
			this->nom=nom;
			for(int i=0;i<8;i++)
				this->note[i]=note[i];
		}
		student(student &s){
			mtr=s.mtr;
			nom=s.nom;
			for(int i=0;i<8;i++)
				note[i]=s.note[i];
		}
		int getMtr(){
			return mtr;
		}
		void setMtr(int mtr){
			this->mtr=mtr;
		}
		string getNom(){
			return nom;
		}
		void setNom(string nom){
			this->nom=nom;
		}
		float * getNote(){
			return note;
		}
		void setNote(float note2[]){
			for(int i=0;i<8;i++)
				note[i]=note2[i];
		}
		float getMoy(){
			float somme=0;
			for(int i=0;i<8;i++)
				somme+=getNote()[i];
			return somme/8;
		}
		void print(){
			cout << "Mtr : " << mtr << endl;
			cout << "Nom : " << nom << endl;
			for(int i=0;i<8;i++)
				cout << "Note[" << i << "]=" << getNote()[i] << endl;
			cout << "La moyenne : " << getMoy() << endl << endl;
		}
		~student(){};
};
int student::mtrCourant=0;
class t_node{
	private:
		student stud;
		t_node *left;
		t_node *right;
	public:
		t_node(){
			left=nullptr;
			t_node *right;
		}	
		t_node(student stud){
			this->stud=stud;
			left=nullptr;
			right=nullptr;
		}
		t_node(t_node &t){
			stud=t.stud;
			left=t.left;
			right=t.right;
		}
		student getStud(){
			return stud;
		}
		void setStud(int mtr,string nom,float note2[]){
			stud.setMtr(mtr);
			stud.setNom(nom);
			stud.setNote(note2);
		}
		t_node* getLeft(){
			return left;
		}
		void setLeft(t_node *n){
			left=n;
		}
		t_node* getRight(){
			return right;
		}
		void setRight(t_node *n){
			right=n;
		}
		~t_node(){
			cout << "Destrution t_node..." << endl;
			delete left;
			delete right;
		}
};
class BST{
	private:
		int size;
		t_node* root;
		void printHelper(t_node *r){
			if(r==NULL){
				return;
			}
			else{
				r->getStud().print();
				printHelper(r->getLeft());
				printHelper(r->getRight());
			}
		}
		t_node* addHelper(t_node* r,student s){
			if(r==NULL){
				t_node *n=new t_node(s);
				r=n;
			}
			else if(r->getStud().getMtr() > s.getMtr()){
				r->setLeft(addHelper(r->getLeft(),s));
			}
			else{
				r->setRight(addHelper(r->getRight(),s));
			}
			size++;
			return r;
		}
		t_node* getMaxHelper(t_node *r){
			if(r->getRight()==nullptr){
				return r;
			}
			else{
				return getMaxHelper(r->getRight());
			}
		}
		t_node* getMinHelper(t_node *r){
			if(r->getLeft()==nullptr){
				return r;
			}
			else{
				return getMinHelper(r->getLeft());
			}
		}
		t_node* DeleteHelper(t_node *r,int mtr){
			if(r==nullptr){
				return r;
			}
			else if(r->getStud().getMtr()>mtr){
				r->setLeft(DeleteHelper(r->getLeft(),mtr));
			}
			else if(r->getStud().getMtr()<mtr){
				r->setRight(DeleteHelper(r->getRight(),mtr));
			}
			else{
				if(r->getLeft()==nullptr && r->getRight()==nullptr){
					delete r;
					r=nullptr;
					return r;
				}
				else if(r->getLeft()==nullptr){
					t_node *t=r;
					r=r->getLeft();
					delete t;
				}
				else if(r->getRight()==nullptr){
					t_node *t=r;
					r=r->getRight();
					delete t;
				}
				else{
					t_node *temp=getMinHelper(r->getRight());
					r->setStud(temp->getStud().getMtr(),temp->getStud().getNom(),temp->getStud().getNote());
					r->setRight(DeleteHelper(r->getRight(),temp->getStud().getMtr()));
				}
			}
			return r;
		}
	public:
		BST(){
			size=0;
			root=nullptr;
		}
		BST(t_node *r){
			root=r;
			size++;
		}
		int getSize(){
			return size;
		}
		t_node* getRoot(){
			return root;
		}
		void setRoot(t_node *r){
			this->root=r;
		}
		bool isEmpty(){
			if(root==nullptr)
				return true;
			return false;
		}
		void print(){
			printHelper(root);
		}
		t_node* add(string nom,float n[]){
			student s(nom,n);
			return addHelper(root,s);
		}
		t_node* getMax(){
			return getMaxHelper(root);
		}
		t_node* getMin(){
			return getMinHelper(root);
		}
		t_node* Delete(int mtr){
			return DeleteHelper(root,mtr);
		}
};
int main(){
	float t1[8]={14,18,10,16,17,15,14,11};
	float t2[8]={19,20,10,11,8,13,5,3};
	BST *b=new BST();
	b->setRoot(b->add("Achraf",t1));
	b->setRoot(b->add("Anas",t2));
	b->setRoot(b->add("Ayoub",t2));
	b->setRoot(b->add("Khalid",t2));
   	b->Delete(3);
	b->print();
	return 0;
}

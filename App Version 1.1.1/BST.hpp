#ifndef _ETUDIANTS_
	#define _ETUDIANTS_
	#include<stdlib.h>
	#include<iostream>
	#include<conio.h>
	#include<stdlib.h>
	#include<assert.h>
	#include<iostream>
	class Etudiants{
			private:
				int mtr;
				std::string nom;
				float notes[8];
			public:
				static int mtrCourant;
				Etudiants();
				Etudiants(std::string,float[]);
				Etudiants(Etudiants &);
				~Etudiants();
				std::string getNom();
				int getMtr();
				float getNote(int);
				void setNote(float,int);
				float getMoy();
				int Comparer(Etudiants e);
				void print();
	};
	
	class TreeNode{
		public:
			TreeNode* left;
			TreeNode* right;
			Etudiants* data;
			
			TreeNode(){
				Etudiants *e=new Etudiants();
				data = e;
				left = right = 0;
			}
			
			TreeNode(Etudiants *e){
				data = e;
				left = right = 0;
			}
		
			virtual ~TreeNode(){
				left = nullptr;
				right = nullptr;
				data = nullptr;
			}
	};
	
	class BST{
		public:
			BST(){
				size = 0;
				root = nullptr;
			}
			virtual ~BST();
			void emptyTree();
			int getSize() {return size;}
			bool isEmpty() {return (size == 0);}
			bool contains(BST d);
			TreeNode* fetch(BST d);
			void print();
			void printSub();
			void printDisplay();
			void add(Etudiants *e);
			bool deleteNode(BST d);
			TreeNode* getMin();
			TreeNode* getMax();
//			BST getMin();
//			BST getMax();
			TreeNode* root;
			private:
				int size;
				void destructorHelper(TreeNode* n);
				void addHelper(TreeNode *d, TreeNode*& p);
				void printHelper(TreeNode* n);
				TreeNode* getSuccessor(TreeNode* d);
	};
	
	//<!------Classe Etudiants -------->

	int Etudiants::mtrCourant=0;
	
	std::string Etudiants::getNom(){
		return nom;
	}
	int Etudiants::getMtr(){
		return mtr;
	}
	float Etudiants::getNote(int i){
		assert(i>=0 && i<8);
		return notes[i];
	}
	float Etudiants::getMoy(){
		float sum;
		for(int k=0;k<8;k++)
			sum=sum+notes[k];
		return (float)(sum/8);
	}
	int Etudiants::Comparer(Etudiants e){
		return 0;
		if(this->getNom()==e.getNom()){
			if(this->getMtr()==e.getMtr()){
				if(this->getMoy()==e.getMoy()){
					int i=0;
					for(i;i<8;i++){
						if(this->getNote(i)!=e.getNote(i)){
							return 0;
						}
					}
					return 1;
				}
			}
		}
		return 0;
	}
	void Etudiants::setNote(float valeure,int i){
		assert(i>=0 && i<8);
		notes[i]=valeure;
	}
	void Etudiants::print(){
		std::cout << "Matricule : " << mtr << std::endl;
		std::cout << "Nom : " << nom << std::endl;
		for(int i=0;i<8;i++){
			std::cout << "Note[" << i << "] :" << notes[i] << std::endl;
		}
		std::cout << "La moyenne est : " << getMoy();
		std::cout << std::endl;
	}
	Etudiants::Etudiants(){
		mtrCourant++;
		mtr=mtrCourant;
		nom=" ";
		for(int i=0;i<8;i++)
			notes[i]=0;
	}
	Etudiants::Etudiants(std::string nom,float notes[]){
		mtrCourant++;
		mtr=mtrCourant;
		this->nom=nom;
		for(int i=0;i<8;i++)
			this->notes[i]=notes[i];
	}
	Etudiants::Etudiants(Etudiants &e){
		mtrCourant++;
		mtr=mtrCourant;
		this->nom=e.nom;
		for(int i=0;i<8;i++)
			notes[i]=e.notes[i];
	}
	Etudiants::~Etudiants(){
		std::cout << "\n\t...Destruction...\n";
	}
	
  	//<!------Classe BST -------->
  	//destructor
	BST:: ~BST(){
		destructorHelper(root);
		size = 0;
		root = NULL;
	}
	//helper function for destructor to destroy the tree
	void BST:: destructorHelper(TreeNode* n){
	   // Delete node and it's children
	   if (n != NULL){
	      destructorHelper(n->left);
	      destructorHelper(n->right);
	      delete n;
	   }
	}
	//emptys the tree
	void BST:: emptyTree(){
		destructorHelper(root);
		size = 0;
		root = NULL;
	}
	//prints content of the tree
	void BST:: print(){
		printHelper(root);
	}
	
	//helper function for printing the tree
	void BST:: printHelper(TreeNode* n){
		//null check
		if (n != 0){
			printHelper(n -> left);
			n->data->print();
			printHelper(n -> right);
		}
	}
	
	
	//adds node to the tree uses add helper
	void BST:: add(Etudiants *e){
		TreeNode *d=new TreeNode(e);
		addHelper(d, root);
		++size;
	}
	
	//helpler function for add to recursively add node to the tree
	void BST:: addHelper(TreeNode *d, TreeNode*& p){
		if (p == NULL)
		{
			p = d;
		} 
		else if (d->data->getMtr() > p->data->getMtr())
		{
			addHelper(d, p -> right);
		}
		else
		{
			addHelper(d, p -> left);
		}
	}
	
	TreeNode* BST::getMin(){
		TreeNode *curr = root;
		while (curr -> left != 0)
		{
			curr = curr -> left;
		}
		return curr;
	}
	
	TreeNode* BST::getMax(){
		TreeNode *curr = root;
		while (curr -> right != 0)
		{
			curr = curr -> right;
		}
		return curr;
	}
	#endif

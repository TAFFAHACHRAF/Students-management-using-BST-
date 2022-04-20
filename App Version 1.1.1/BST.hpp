//Achraf TAFFAH : GLSID-1
#ifndef _ETUDIANTS_
	#define _ETUDIANTS_
	#include<stdlib.h>
	#include<iostream>
	#include<conio.h>
	#include<stdlib.h>
	#include<assert.h>
	#include<iostream>
	
	class Students{
			private:
				int mtr;
				std::string Name;
				float notes[8];
			public:
				static int mtrCourant;
				Students();
				Students(std::string,float[]);
				Students(Students &);
				~Students();
				std::string getName();
				int getMtr();
				float getNote(int);
				float getAverage();
				void setNote(float,int);
				void setName(std::string Name);
				int Compare(Students e);
				void print();
	};
	
	class TreeNode{
		public:
			TreeNode* left;
			TreeNode* right;
			Students* data;
			
			TreeNode(){
				Students *e=new Students();
				data = e;
				left = right = 0;
			}
			
			TreeNode(Students *e){
				data = e;
				left = right = 0;
			}
			
			TreeNode(TreeNode *tr){
				this->data=tr->data;
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
			int getSize() {
				return size;
			}
			bool isEmpty() {
				return (size == 0);
			}
			void print();
			void add(Students *e);
			bool deleteNode(BST d);
			TreeNode* getMin();
			TreeNode* getMax();
			TreeNode* getTreeNode(int m);
			void SearchByMtr(int m);
			void SearchByMoy(int m);
			TreeNode* root;
			private:
				int size;
				void destructorHelper(TreeNode* n);
				void addHelper(TreeNode *d, TreeNode*& p);
				void printHelper(TreeNode* n);
				void getHelper(TreeNode*& curr, int);
				TreeNode* getSuccessor(TreeNode* d);
	};
	
	//<!------Classe Students -------->

	int Students::mtrCourant=0;
	
	std::string Students::getName(){
		return Name;
	}
	int Students::getMtr(){
		return mtr;
	}
	float Students::getNote(int i){
		assert(i>=0 && i<8);
		return notes[i];
	}
	float Students::getAverage(){
		float sum;
		for(int k=0;k<8;k++)
			sum=sum+notes[k];
		return (float)(sum/8);
	}
	int Students::Compare(Students e){
		return 0;
		if(this->getName()==e.getName()){
			if(this->getMtr()==e.getMtr()){
				if(this->getAverage()==e.getAverage()){
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
	void Students::setNote(float valeure,int i){
		assert(i>=0 && i<8);
		notes[i]=valeure;
	}
	void Students::setName(std::string Name){
		this->Name=Name;
	}
	void Students::print(){
		std::cout << "Matricule : " << mtr << std::endl;
		std::cout << "Name : " << Name << std::endl;
		for(int i=0;i<8;i++){
			std::cout << "Note[" << i << "] :" << notes[i] << std::endl;
		}
		std::cout << "The Average : " << getAverage();
		std::cout << std::endl;
	}
	Students::Students(){
		mtrCourant++;
		mtr=mtrCourant;
		Name=" ";
		for(int i=0;i<8;i++)
			notes[i]=0;
	}
	Students::Students(std::string Name,float notes[]){
		mtrCourant++;
		mtr=mtrCourant;
		this->Name=Name;
		for(int i=0;i<8;i++)
			this->notes[i]=notes[i];
	}
	Students::Students(Students &e){
		mtrCourant++;
		mtr=mtrCourant;
		this->Name=e.Name;
		for(int i=0;i<8;i++)
			notes[i]=e.notes[i];
	}
	Students::~Students(){
		std::cout << "\n\t...Destruction...\n";
	}
	
  	//<!------Classe BST -------->
  	//destructor
	BST:: ~BST(){
		destructorHelper(root);
		size = 0;
		root = NULL;
	}
	
	//emptys the tree
	void BST:: emptyTree(){
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
	void BST:: add(Students *e){
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
	
	TreeNode* BST::getTreeNode(int m){
		TreeNode *curr=new TreeNode();
		curr=root;
		getHelper(curr,m);
		return curr;
	}
	
	void BST:: getHelper(TreeNode*& curr, int m){
		if(m<curr->data->getMtr()){
			getHelper(curr->left,m);
		}
		else if(m>curr->data->getMtr()){
			getHelper(curr->right,m);
		}
	}
	#endif

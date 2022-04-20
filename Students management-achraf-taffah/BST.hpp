//Meeshaan Shah
//CPSC 350
//Assignment 4
//Header file for generic binary search tree

#ifndef BST_H
#define BST_H


//binary search tree generic class
template <typename T>
class TreeNode
{
	public:
		TreeNode<T>* left;
		TreeNode<T>* right;
		T data;
		
		TreeNode(T d)
		{
			data = d;
			left = right = 0;
		}
		virtual ~TreeNode()
		{
			left = nullptr;
			right = nullptr;
			data = 0;
		}
};

template <typename T>
class BST
{
	public:
		BST()
		{
			size = 0;
			root = 0;
		}
		virtual ~BST();
		void emptyTree();
		int getSize() {return size;}
		bool isEmpty() {return (size == 0);}
		bool contains(T d);
		T get(T d);
		T getRoot();
		TreeNode<T>* fetch(T d);
		void print();
		void printSub();
		void printDisplay();
//		void printToFile(std::ofstream& output);
//		void printSubToFile(std::ofstream& output);
		void add(T d);
		bool deleteNode(T d);
		T getMin();
		T getMax();
	
	private:
		TreeNode<T>* root;
		int size;
		void destructorHelper(TreeNode<T>* n);
		void addHelper(T d, TreeNode<T>*& p);
		void printHelper(TreeNode<T>* n);
		void printSubHelper(TreeNode<T>* n);
		void printDisplayHelper(TreeNode<T>* n);
//		void printToFileHelper(TreeNode<T>* n, std::ofstream& output);
//		void printSubToFileHelper(TreeNode<T>* n, std::ofstream& output);
		TreeNode<T>* getSuccessor(TreeNode<T>* d);
};

//destructor
template <typename T>
BST<T>:: ~BST()
{
	destructorHelper(root);
	size = 0;
	root = NULL;
}

//emptys the tree
template <typename T>
void BST<T>:: emptyTree()
{
	destructorHelper(root);
	size = 0;
	root = NULL;
}

//helper function for destructor to destroy the tree
template <typename T>
void BST<T>:: destructorHelper(TreeNode<T>* n)
{
   // Delete node and it's children
   if (n != NULL)
   {
      destructorHelper(n->left);
      destructorHelper(n->right);
      delete n;
   }
}

//writes content of tree to file, uses print to file helper
//template <typename T>
//void BST<T>:: printToFile(std::ofstream& output)
//{
//	printToFileHelper(root, output);
//}

//helper function for print to file, uses recursion to print bst to file
//template <typename T>
//void BST<T>:: printToFileHelper(TreeNode<T>* n, std::ofstream& output)
//{
//	//null check
//	if (n != 0)
//	{
//		printToFileHelper(n -> left, output);
//		n -> data.printToFile(output);
//		n -> data.printToFileStudent(output);
//		printToFileHelper(n -> right, output);
//	}
//}

//writes a tree to file, specifically implemented for assignment 4 for faculty
//template <typename T>
//void BST<T>:: printSubToFile(std::ofstream& output)
//{
//	printSubToFileHelper(root, output);
//}

//helper function for print sub to file
//template <typename T>
//void BST<T>:: printSubToFileHelper(TreeNode<T>* n, std::ofstream& output)
//{
//	//null check
//	if (n != 0)
//	{
//		printSubToFileHelper(n -> left, output);
//		output << n -> data << std::endl;
//		printSubToFileHelper(n -> right, output);
//	}
//}

//prints content of the tree
template <typename T>
void BST<T>:: print()
{
	printHelper(root);
}

//helper function for printing the tree
template <typename T>
void BST<T>:: printHelper(TreeNode<T>* n)
{
	//null check
	if (n != 0)
	{
		printHelper(n -> left);
		std::cout << n -> data << std::endl;
		printHelper(n -> right);
	}
}

//prints content of the tree
template <typename T>
void BST<T>:: printSub()
{
	printSubHelper(root);
}

//helper function for printing the tree, prints data with space b/n them, used for Faculty 
//in assignment 4
template <typename T>
void BST<T>:: printSubHelper(TreeNode<T>* n)
{
	//null check
	if (n != 0)
	{
		printSubHelper(n -> left);
		std::cout << n -> data << " ";
		printSubHelper(n -> right);
	}
}

//prints content of tree to screen, used in assignment 4 for faculty and student
template <typename T>
void BST<T>:: printDisplay()
{
	printDisplayHelper(root);
}

//helper function for print display
template <typename T>
void BST<T>:: printDisplayHelper(TreeNode<T>* n)
{
	//null check
	if (n != 0)
	{
		printDisplayHelper(n -> left);
		n -> data.print();
		printDisplayHelper(n -> right);
	}
}

//adds node to the tree uses add helper
template <typename T>
void BST<T>:: add(T d)
{
	addHelper(d, root);
	++size;
}

//helpler function for add to recursively add node to the tree
template <typename T>
void BST<T>:: addHelper(T d, TreeNode<T>*& p)
{
	if (p == 0)
	{
		p = new TreeNode<T>(d);
	} 
	else if (d > p -> data)
	{
		addHelper(d, p -> right);
	}
	else
	{
		addHelper(d, p -> left);
	}
}

//gets successor for the node to be deleted, recieved from sexy teacher Dr. Linstead
template <typename T>
TreeNode<T>* BST<T>:: getSuccessor(TreeNode<T>* d)
{
	TreeNode<T>* sp = d;  //successors parent
    TreeNode<T>* successor = d;
    TreeNode<T>* current = d->right;   // go to right first
    while(current != NULL)
    {                                             
        sp = successor;
         successor = current;
         current = current->left;      // go to left
    }
                                           
    if(successor != d->right)
    {  // descendant of right child
         
       	sp->left = successor->right;
       	successor->right = d->right;
   	}
   	return successor;
}

//deletes a node from the tree recieved from sexy teacher Dr. Linstead
template <typename T>
bool BST<T>:: deleteNode(T d)
{
	if (root == NULL) return false;  //like were ever this lucky
                               
      TreeNode<T>* current = root;
      TreeNode<T>* parent = root;
      bool isLeft = true;

      while(current->data != d)
      { //usual code to find the node       
         parent = current;
         if(d < current->data)
         {  //need to go left
            
            isLeft = true;
            current = current->left;
         }
         else
         { //need to go right
            
            isLeft = false;
            current = current->right;
         }
         if(current == NULL)  //the thing isnt in the tree             
            return false;                
      }  

      //no children  this would be nice
      if(current->left==NULL && current->right==NULL)
      {
         
         if(current == root)             // deleting root
            root = NULL;                 
         else if(isLeft)
            parent->left = NULL;     // disconnect from parent
         else                            
            parent->right = NULL;
      }
        
      //one child  still not too bad
      // no right child, replace with left subtree
      else if(current->right==NULL)
      {
         if(current == root)  //always have to check for root
            root = current->left;
         else if(isLeft)
            parent->left = current->left;
         else
            parent->right = current->left;
      }
      // no left child, replace with right subtree
      else if(current->left==NULL)
      {
         if(current == root)
            root = current->right;
         else if(isLeft)
            parent->left = current->right;
         else
            parent->right = current->right;
      }
      else
      {  // two children  things are about to get scary
         
         // find successor of node to delete (current)
         TreeNode<T>* successor = getSuccessor(current);

         // connect parent of current to successor
         if(current == root)  //usual root check
            root = successor;
         else if(isLeft)
            parent->left = successor;
         else
            parent->right = successor;

         // connect successor to current's left child
         successor->left = current->left;
      } 
      --size; 
      return true;                                
}

//returns copy of the node from the tree of type T
template <typename T>
T BST<T>:: get(T d)
{
	TreeNode<T>* curr = root;
	while (curr != 0)
	{
		if (d > curr -> data)
		{
			curr = curr -> right;
		}
		else if (d < curr -> data)
		{
			curr = curr -> left;
		}
		else
		{
			break;
		}
	}
	return curr -> data;
}

//returns copy of the root of the tree
template <typename T>
T BST<T>:: getRoot()
{
	return root -> data;
}

//returns a pointer to a node in the tree
template <typename T>
TreeNode<T>* BST<T>:: fetch(T d)
{
	TreeNode<T>* curr = root;
	while (curr != 0)
	{
		if (d > curr -> data)
		{
			curr = curr -> right;
		}
		else if (d < curr -> data)
		{
			curr = curr -> left;
		}
		else
		{
			break;
		}
	}
	return curr;
}

//returns a boolean if the node is in the tree
template <typename T>
bool BST<T>:: contains(T d)
{
	bool ret = false;
	
	TreeNode<T>* curr = root;
	while (curr != 0)
	{
		if (d > curr -> data)
		{
			curr = curr -> right;
		}
		else if (d < curr -> data)
		{
			curr = curr -> left;
		}
		else
		{
			ret = true;
			break;
		}
	}
	return ret;
}

//gets minimum node in the tree
template <typename T>
T BST<T>::getMin()
{
	TreeNode<T> * curr = root;
	while (curr -> left != 0)
	{
		curr = curr -> left;
	}
	return curr -> data;
}

//gets maximum node in the tree
template <typename T>
T BST<T>::getMax()
{
	TreeNode<T> * curr = root;
	while (curr -> right != 0)
	{
		curr = curr -> right;
	}
	return curr -> data;
}

#endif


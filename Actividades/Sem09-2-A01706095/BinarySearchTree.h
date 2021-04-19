/* 
* Sem09-2 Binary Search Tree (BST) - Operaciones avanzadas
* 14/04/2021 20:46:44
* BinarySearchTree.h
* A01706095 Naomi Nieto Vega
* A01283687 Ramsés Herrera Santiago
*/
#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include <iostream>
#include "NodeTree.h"
#include "Trunk.h"

template <class T>
class BinarySearchTree { 
  private:
    int option;
    char opc;
  public: 
    NodeTree<T> * root;
    BinarySearchTree();
    void menu(BinarySearchTree<T> &);
    bool find(T);
    NodeTree<T> * findNode(T);
    void insert(T);
    NodeTree<T> * remove(NodeTree<T> * ,int);
    NodeTree<T> * insertRecursive(NodeTree<T>*, T);
    void showTrunks(Trunk<T>*);
    void print(NodeTree<T>* ,Trunk<T> *, bool);
    void preorder(NodeTree<T>* nodo);
    void postorder(NodeTree<T>* nodo);
    void inorder(NodeTree<T>* nodo);
    void visit(int);
    void printGivenLevel(NodeTree<T>*,int);
    void printLevelOrder(NodeTree<T>* );
    int height(NodeTree<T>*);
    bool printAncestors( NodeTree<T>*,int);
    NodeTree<T>* newNode(int);
    int getLevel( NodeTree<T> *, int );
    int getLevelUtil( NodeTree<T> *,int , int );
};

template<class T>
BinarySearchTree<T>::BinarySearchTree() {
  root = nullptr;
}

template<class T>
void BinarySearchTree<T>::menu(BinarySearchTree<T> &bst) {
  T value;
  while (option != 9) {
    std::cout << "\n";
    std::cout << "\t\tBinary Search Tree\n";
    std::cout << "═════════════════════════════════════════════════════\n";
    std::cout << "BST Basic Operations: \n";
    std::cout << "\t1. Insert\n\t2. Delete\n\t3. Print\n\t4. Find\n";
    std::cout << "BST Advanced Operations: \n";
    std::cout << "\t5. Visit\n\t6. Height\n\t7. Ancestors\n\t8. What level am I\n";
    std::cout << "System Operations: \n";
    std::cout << "\t9. Exit\n";
    std::cout << "═════════════════════════════════════════════════════\n";
    std::cout << "Option: ";
    std::cin >> option;
    
    switch (option) {
      case 1:
        std::cout << "Introduce el elemento a insertar: ";
        std::cin >> value;
        bst.insert(value);
        std::cout << "El elemento " << value << " se insertó correctamente! ";
        std::cout << "Deseas visualizar el resultado? (Y/N)\n";
        std::cin >> opc;
        if (opc == 'Y') {
          bst.print(bst.root, nullptr, false);
        }
      break;
      case 2:
        std::cout << "Introduce el elemento a borrar: ";
        std::cin >> value;
        bst.remove(bst.root,value);
        std::cout << "El elemento " << value << " se eliminó correctamente! ";
        std::cout << "Deseas visualizar el resultado? (Y/N)\n";
        std::cin >> opc;
        if (opc == 'Y') {
          bst.print(bst.root, nullptr, false);
        }
      break;
      case 3:
        bst.print(bst.root, nullptr, false);
      break;
      case 4:
        std::cout << "Introduce el elemento a buscar: ";
        std::cin >> value;
        bst.find(value);
      break;
      case 5:
        std::cout << "═════════════════════════════════════════════════════\n";
        std::cout << "Tipos de despliegue: \n";
        std::cout << "\t1. Preorder\n\t2. Inorder\n\t3. Postorder\n\t4. Level by level\n";
        std::cout << "═════════════════════════════════════════════════════\n";
        std::cout << "Option: ";
        std::cin >> value;
        std::cout << "\n";
        bst.visit(value);
      break;
      case 6:
        std::cout << "La altura es: " << bst.height(bst.root) << "\n";
      break;
      case 7:
        std::cout << "Introduce el elemento a buscar: ";
        std::cin >> value;
        std::cout << "Ancestors: " ; 
        bst.printAncestors(bst.root, value);
      break;
      case 8: 
        std::cout << "Introduce el elemento a buscar: ";
        std::cin >> value;
        std::cout << "Level of "<< value << " is " << bst.getLevel(bst.root, value) << "\n";
      break;
      case 9:
        std::cout << "Gracias por usar nuestra app. ¡Hasta pronto! :D\n";
      break;
      default:
        std::cout << "Opción inválida. Por favor introduce una opción válida (1-9)\n\n";
      break;
    } // End switch
  } // End while
} // End menu

template<class T>
bool BinarySearchTree<T>::find(T valor) {
  NodeTree<T> *p = root;
  while (p != nullptr) {
    if (p->data == valor) {
      std::cout << "True" << std::endl;
      return true;
    }
    else { 
      p = (valor < p->data ? p->left : p->right);
    }
  }
  std::cout << "False" << std::endl;
  return false;
}

template<class T>
NodeTree<T> * BinarySearchTree<T>::findNode(T valor) {
  NodeTree<T> *p = root;
  while (p != nullptr) {
    if (p->data == valor) {
      return p;
    }
    else { 
      p = (valor < p->data ? p->left : p->right);
    }
  }
  return p;
}

template<class T>
void BinarySearchTree<T>::insert(T valor) {
  root = insertRecursive(root, valor);  
}

template<class T>
NodeTree<T> * BinarySearchTree<T>::insertRecursive(NodeTree<T> *p, T valor) {
  if (p == nullptr) // Arbol vacio
    p = new NodeTree(valor);
  else if (valor < p->data)
    p->left = insertRecursive(p->left, valor);
  else if (valor > p->data)
    p->right = insertRecursive(p->right, valor);
  else
    std::cout << "El elemento " << valor << " ya existe en el árbol" << "\n";
  return p;
}

template<class T>
NodeTree<T> * BinarySearchTree<T>::remove(NodeTree<T> * root, int k) {
  if (root == NULL)
    return root;
  if (root->data > k) {
    root->left = remove(root->left, k);
    return root;
  }
  else if (root->data < k) {
    root->right = remove(root->right, k);
    return root;
  }
  if (root->left == NULL) {
    NodeTree<T>* temp = root->right;
    delete root;
    return temp;
  }
  else if (root->right == NULL) {
    NodeTree<T>* temp = root->left;
    delete root;
    return temp;
  }
  else {
    NodeTree<T> * succParent = root;
    NodeTree<T> * succ = root->right;
    while (succ->left != NULL) {
      succParent = succ;
      succ = succ->left;
    }
    if (succParent != root)
      succParent->left = succ->right;
    else
      succParent->right = succ->right;
    root->data = succ->data;

    delete succ;
    return root;
  }
}


template <class T>
void BinarySearchTree<T>::showTrunks(Trunk<T> *p) {
  if (p == nullptr) {
    return;
  }
  showTrunks(p->prev);
  std::cout << p->str;
}

template <class T>
void BinarySearchTree<T>::print(NodeTree<T>* root, Trunk<T> *prev, bool isLeft) {
  if (root == nullptr) {
    return;
  }
  std::string prev_str = "    ";
  Trunk<T> *trunk = new Trunk<T>(prev, prev_str);
  print(root->right, trunk, true);

  if (!prev) {
    trunk->str = "═══";
  }
  else if (isLeft) {
    trunk->str = "╔═══";
    prev_str = "    ║";
  }
  else {
    trunk->str = "╚═══";
    prev->str = prev_str;
  }
  showTrunks(trunk);
  std::cout << root->data << std::endl;
  if (prev) {
    prev->str = prev_str;
  }
  trunk->str = "    ║";

  print(root->left, trunk, false);
}

template<class T>
void BinarySearchTree<T>::preorder(NodeTree<T>* nodo){
    if(nodo != nullptr){
      std::cout<<nodo->data<<std::endl; // nodo
      preorder(nodo->left); // left
      preorder(nodo->right); // right
    }
}
    

template<class T>
void BinarySearchTree<T>::inorder(NodeTree<T>* nodo){
    if(nodo != nullptr){
    inorder(nodo->left);
    std::cout<<nodo->data<<std::endl;
    inorder(nodo->right);
    }
}

template<class T>
void BinarySearchTree<T>::postorder(NodeTree<T>* nodo){
    if(nodo != nullptr){
    postorder(nodo->left);
    postorder(nodo->right);
    std::cout<<nodo->data<<std::endl;
    }
}

template<class T>
void BinarySearchTree<T>::visit(int option) {
  if (option == 1) {
    this->preorder(this->root);
  }
  else if (option == 2) {
    this->inorder(this->root);
  }
  else if (option == 3) {
    this->postorder(this->root);
  }
  else {
    this->printLevelOrder(this->root);
  }

}
 
template<class T>
void BinarySearchTree<T>::printLevelOrder(NodeTree<T>* root) {
  int h = height(root);
  int i;
  for (i = 1; i <= h; i++)
    printGivenLevel(root, i);
}
 
template<class T>
void BinarySearchTree<T>::printGivenLevel(NodeTree<T>* root, int level) {
  if (root == NULL)
    return;
  if (level == 1)
    cout << root->data << " ";
  else if (level > 1) {
    printGivenLevel(root->left, level-1);
    printGivenLevel(root->right, level-1);
  }
}
 
template<class T>
int BinarySearchTree<T>::height(NodeTree<T>* node) {
  if (node == NULL)
    return 0;
  else {
    /* compute the height of each subtree */
    int lheight = height(node->left);
    int rheight = height(node->right);

    /* use the larger one */
    if (lheight > rheight)
        return(lheight + 1);
    else return(rheight + 1);
  }
}

template<class T>
NodeTree<T>* BinarySearchTree<T>::newNode(int data) {
  NodeTree<T>* Node = new  NodeTree<T>();
  Node->data = data;
  Node->left = NULL;
  Node->right = NULL;

  return(Node);
}

template<class T>
bool BinarySearchTree<T>::printAncestors( NodeTree<T> *root, int target) {
  /* base cases */
  if (root == NULL)
    return false;
  
  if (root->data == target)
    return true;
  if ( printAncestors(root->left, target) || printAncestors(root->right, target) ){
    cout << root->data << " ";
    return true;
  }
  return false;
}

template<class T>
int BinarySearchTree<T>::getLevelUtil( NodeTree<T> *node,int data, int level) {
  if (node == NULL)
    return 0;

  if (node -> data == data)
    return level;

  int downlevel = getLevelUtil(node -> left,data, level + 1);
  if (downlevel != 0)
    return downlevel;

  downlevel = getLevelUtil(node->right, data, level + 1);
  return downlevel;
}
 
template<class T>
int BinarySearchTree<T>::getLevel( NodeTree<T> *node, int data) {
  return getLevelUtil(node, data, 1);
}

#endif // BinarySearchTree_h
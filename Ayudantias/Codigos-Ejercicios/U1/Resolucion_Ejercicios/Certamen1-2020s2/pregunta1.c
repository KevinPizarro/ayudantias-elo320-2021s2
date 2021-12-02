#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int key;
  struct Node *left, *right;
}Nodo;

Nodo * new_node(int key);
Nodo * insert(Nodo * node, int key);
int contar_nodos(Nodo * node);

int main(int argc, char const *argv[])
{
  Nodo * root = NULL;
  root = insert(root, 50);
  root = insert(root, 30);
  root = insert(root, 20);
  root = insert(root, 40);
  root = insert(root, 70);
  root = insert(root, 60);
  root = insert(root, 80);
  root = insert(root, 90);

  printf("El árbol binario tiene %d nodos.\n", contar_nodos(root));

  return 0;
}

Nodo * new_node(int key){
  Nodo * temp = (Nodo *) malloc(sizeof(Nodo));
  temp->key = key;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}

Nodo * insert(Nodo * node, int key){
  if (node == NULL) return new_node(key); //arbol vacío

  if (key < node->key) node->left = insert(node->left, key); // llave menor que la llave del nodo actual -> me voy a la rama izquierda
  else if (key > node->key) node->right = insert(node->right, key); // llave mayor que la llave del nodo actual -> me voy a la rama derecha

  return node;//Regresa el ptr al tope del arbol
}

int contar_nodos(Nodo * node){
  int l_counter = 0, r_counter = 0, counter = 0;
  if (node!=NULL)
  {
    l_counter = contar_nodos(node->left);//0
    r_counter = contar_nodos(node->right);//0
    counter = l_counter + r_counter + 1; //+3+3+1
  }
  return counter;
}
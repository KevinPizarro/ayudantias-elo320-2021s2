#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int key;
  struct Node *left, *right;
}Nodo;

Nodo * new_node(int key);
Nodo * insert(Nodo * node, int key);
int contar_nodos(Nodo * node);
void bst2array (Nodo * nodo);
int mediana(Nodo * root, int n_nodos);
void print_inorder(Nodo * node);

static int index = 0;
static int array [8];
static int counter = 0;

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
  root = insert(root, 100);

  printf("Nuestro árbol ordenado ascendetemente es: \n");
  print_inorder(root);

  int n_nodos = contar_nodos(root);
  printf("\nEl árbol binario tiene %d nodos.\n", n_nodos);
  printf("La mediana es: %d.\n", mediana(root, n_nodos));

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

  return node;
}

//Cuenta los nodos de manera recursiva. Comienza desde "el fondo" y luego en el regreso cuenta los nodos visitados
//Ante la duda es bueno realizar un diagrama junto con un ruteo para poder entender el funcionamiento.
int contar_nodos(Nodo * node){
  int l_counter = 0, r_counter = 0, counter = 0;
  if (node!=NULL)//Caso/condicion de termino
  {
    l_counter = contar_nodos(node->left);
    r_counter = contar_nodos(node->right);
    counter = l_counter + r_counter + 1;
  }
  return counter;
}


/* OJO
Esta solución, con arreglo y variables static, puede no ser la óptima.
Se desperdicia espacio de memoria. Si el árbol es de 1000 nodos (memoria dinámica)
necesitaremos además 1000 espacios en memoria estática para el arreglo
Como ventaja de usar arreglos, la implementación es sencilla y el acceso por índice es directo.*/
void bst2array(Nodo * node){
  if (node!=NULL)
  {
    bst2array(node->left);
    array[counter] = node->key;
    counter ++;
    bst2array(node->right);
  }
  return;
}

int mediana(Nodo * root, int n_nodos){
  int i = 0;
  bst2array(root);

  /*//verifica que el arreglo se construyo correctamente
  printf("Arreglo:\n");
  for  (i = 0; i < 8; ++i)
    printf("%d\n", array[i]);
  */

  int indice = n_nodos/2;
  printf("Indice de la mediana es: %d\n", indice);
  if (n_nodos%2==0)//par
    return array[indice-1];
  else//impar
    return array[indice];
}

void print_inorder(Nodo * node){
  if (node != NULL) {
    print_inorder(node->left);//Entra recursivamente en la rama izquierda, luego pasa a la derecha printeando cuando corresponde
    printf("%d ", node->key);
    print_inorder(node->right);
  }
}
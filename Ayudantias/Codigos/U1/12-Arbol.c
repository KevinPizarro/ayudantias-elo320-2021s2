#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int key;
  struct Node *left, *right;
}Nodo;

Nodo * new_node(int key);
Nodo * insert(Nodo * node, int key);
void print_inorder(Nodo * node);
Nodo * get_min_val(Nodo * node);
Nodo * delete_node(Nodo * root, int key);
void suma(Nodo * node);
int suma2(Nodo * node);

static int result = 0;

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

  suma(root);
  printf("Suma de los valores: %d\n", result);
  printf("Suma de los valores (2do método): %d\n", suma2(root));

  print_inorder(root);
  delete_node(root, 70);
  printf("Se ha borrado el 70.\n");
  print_inorder(root);
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

void print_inorder(Nodo * node){
  if (node != NULL) {
    print_inorder(node->left);//Entra recursivamente en la rama izquierda, luego pasa a la derecha printeando cuando corresponde
    printf("%d \n", node->key);
    print_inorder(node->right);
  }
}

Nodo * get_min_val(Nodo * node)
{
  Nodo * current = node;//Comienza con root, idealmente
  
  //recorre toda la rama izquierda
  while (current && current->left != NULL) current = current->left;

  return current;
}
 
Nodo * delete_node(Nodo * root, int key)
{
  //Caso base/Condición de termino
  if (root == NULL) return root;

  //recursividad en el sub-arbol izquierdo
  if (key < root->key) root->left = delete_node(root->left, key);
  //recursividad en el sub-arbol derecho
  else if (key > root->key) root->right = delete_node(root->right, key);
  //Se ha encontrado el nodo
  else {
      //Nodo con solo 1 hoja o ninguna
      if (root->left == NULL) {
          Nodo * temp = root->right;
          free(root);
          return temp;
      }else if (root->right == NULL) {
          Nodo * temp = root->left;
          free(root);
          return temp;
      }
    //Nodo con 2 hojas
    Nodo * temp = get_min_val(root->right);//valor minimo dentro del sub-arbol de la derecha
    root->key = temp->key;//Copiamos su valor
    root->right = delete_node(root->right, temp->key);//borramos con las siguientes iteraciones
  }
  return root;
}

void suma(Nodo * node){
  if (node != NULL) {
    suma(node->left);
    result += node->key;
    suma(node->right);
  }
}

int suma2(Nodo * node){
  int left = 0, right = 0, result = 0;
  if (node != NULL)
  {
    left = suma2(node->left);
    right = suma2(node->right);
    result = left + right + node->key;
  }
  return result;
}



















/*
#include <stdio.h>
#include <stdlib.h>

typedef  struct moldenodo{
   int clave;
   struct moldenodo *left;
   struct moldenodo *right;
}nodo;

nodo *CreaNodo(int dato);
nodo *InsertaRecursivo(nodo *a, int dato);
void RecorreEnOrden(nodo *arbol);
void RecorreNivel(nodo *p, int nivel);
nodo *BuscaIterativo(nodo *p, int valor);
nodo *BuscaMinimo(nodo *arbol);
nodo *Descartar(nodo*, int);

void main(void){
  int valores[15]={20, 10, 30, 5, 15, 25, 40, 4, 7, 12, 18, 22, 27, 35, 45};
   nodo *arbol = NULL;
  int i = 0;
  for(i = 0; i<15; i++)
    arbol = InsertaRecursivo(arbol,valores[i]);

  RecorreEnOrden(arbol);
  RecorreNivel(arbol, 0);
  nodo *p = BuscaIterativo(arbol, 22);
   if( p!= NULL)
     printf("lo encontre %d\n\"", p->clave);
  printf("Minimo: %d\n", BuscaMinimo(arbol)->clave);

  arbol = Descartar(arbol, 20);
  RecorreNivel(arbol, 0);
  printf("===============================\n");
  arbol = Descartar(arbol, 22);
  RecorreNivel(arbol,0);
}



nodo *CreaNodo(int dato){
  nodo *p = (nodo *)malloc(sizeof(nodo));
  if( p == NULL) exit(1);
  else{
    p->clave = dato;
    p->left = NULL;
    p->right = NULL;
  } 
  return p;
}

nodo *InsertaRecursivo(nodo *a, int dato){
  if(a ==NULL){
    return CreaNodo(dato);
  }else{
     if(a->clave == dato) return a; //dato duplicado
     if(dato < a->clave)
        a->left = InsertaRecursivo(a->left, dato);
     else
        a->right = InsertaRecursivo(a->right, dato);
   return a;
  }
}

void RecorreEnOrden(nodo *arbol){
    if( arbol != NULL){
       RecorreEnOrden(arbol->left);
       printf("%d\n", arbol->clave);
       RecorreEnOrden(arbol->right);
    }

}

void RecorreNivel(nodo *p, int nivel){
  if(p !=NULL){
    RecorreNivel(p->left, nivel + 1);
    printf("nodo: %d, nivel: %d\n", p->clave, nivel);
    RecorreNivel(p->right, nivel + 1);
  }
}

nodo *BuscaIterativo(nodo *p, int valor){
  while(p != NULL){
    if( p->clave == valor) return p;
    else{
      if( p->clave > valor) p = p->left;
      else p = p->right;
    }
  }
}

nodo *BuscaMinimo(nodo *arbol){
  if( arbol == NULL ) return NULL;
  if( arbol->left == NULL ) return arbol;
  return BuscaMinimo(arbol->left);
}

nodo *Descartar(nodo *pn, int valor)
{
  nodo *temp;
  if(pn == NULL) printf("Elemento no encontrado\n");
  else
    if(valor < pn->clave) // por la izquierda 
      pn->left = Descartar(pn->left, valor);
    else
      if(valor > pn->clave) //por la derecha
         pn->right = Descartar(pn->right, valor);
      else //Elemento encontrado 
         if(pn->left && pn->right) // dos hijos 
        {
          temp = BuscaMinimo(pn->right);
          pn->clave = temp->clave;
          pn->right = Descartar(pn->right, temp->clave); //borra hoja
        }else{
          temp = pn;
          if(pn->left == NULL)
            pn = pn->right;
          else
            if(pn->right == NULL)
              pn = pn->left;
          free(temp);
        }
  return pn;        
}
*/
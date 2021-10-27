#include<stdio.h>
#include<stdlib.h>

//Lista simplemente enlazada
typedef struct LNode{
    int data;
    struct LNodo * next;
}LNodo;


typedef struct Node{
  int key;
  struct Node *left, *right;
}Nodo;

void print_array(int array[]);
Nodo * new_node(int key);
Nodo * array2BST(int array[], int start, int end);
void print_inorder(Nodo * node);

void push(LNodo** head_ref, int new_data);
int count_nodes(LNodo *head);
void print_list(LNodo * nodo);
Nodo * list2BSTrec(LNodo **head_ref, int index);
Nodo * list2BST(LNodo * head);

Nodo * BuscaMinimo(Nodo * arbol);
Nodo * BuscaMaximo(Nodo * arbol);


int main(int argc, char const *argv[])
{
	//ARRAY->BST
	int array [7] = {1, 2, 3, 4, 5, 6, 7};//arreglo en orden ascendente
	int start = 0;
	int end = sizeof(array)/sizeof(array[0]) - 1;
	printf("\nArreglo: ");
    print_array(array);
	Nodo * root = array2BST(array, start, end);
	printf("\nBST-array:\n");
	print_inorder(root);

	// LISTA->BST
	LNodo * head = NULL;
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
 
    printf("\nLista:");
    print_list(head);
 
    Nodo * root2 = list2BST(head);
    printf("\nBST-Lista:\n");
    print_inorder(root2);

    //Otros
    printf("\nValor mínimo: %d\n", BuscaMinimo(root2)->key);
    printf("\nValor máximo: %d\n", BuscaMaximo(root2)->key);

	return 0;
}

void print_array(int array[7]){
	//int lenght = sizeof(array)/sizeof(array[0]);
	int i;
	for (i = 0; i < 7; ++i)
		printf("%d ", array[i]);
}

Nodo * array2BST(int array[], int start, int end)
{
	if (start > end) return NULL;

	int middle = (start + end)/2;//root debe ser el elemento del centro (mediana)
	Nodo * root = new_node(array[middle]);
 
	root->left = array2BST(array, start, middle-1);//Construimos desde la rama izquierda recursivamente
	root->right = array2BST(array, middle+1, end);//Construimos la rama de la derecha recursivamente

	return root;
}

Nodo * new_node(int key){
  Nodo * temp = (Nodo *) malloc(sizeof(Nodo));
  temp->key = key;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}

void print_inorder(Nodo * node){
	if (node != NULL) {
		print_inorder(node->left);//Entra recursivamente en la rama izquierda, luego pasa a la derecha printeando cuando corresponde
		printf("%d \n", node->key);
		print_inorder(node->right);
	}
}

/*lista*/
void push(LNodo** head_ref, int new_data){
	LNodo* new_node =(LNodo *) malloc(sizeof(LNodo));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

int count_nodes(LNodo *head){
	int count = 0;
	LNodo * temp = head;
	while(temp){
	    temp = temp->next;
	    count++;
	}
	return count;
}

void print_list(LNodo * nodo){
    while(nodo!=NULL){
        printf("%d ", nodo->data);
        nodo = nodo->next;
    }
}

Nodo * list2BSTrec(LNodo **head_ref, int index){
    if (index <= 0) return NULL;
    Nodo * left = list2BSTrec(head_ref, index/2);//Construye sub-arbol izquierdo
    Nodo * root = new_node((*head_ref)->data);
    root->left = left;
 
    *head_ref = (*head_ref)->next;//Actualizacion de cabeza
    root->right = list2BSTrec(head_ref, index-index/2-1);//Construye sub-arbol derecho
 
    return root;
}

Nodo * list2BST(LNodo * head){
    int n = count_nodes(head);
    return list2BSTrec(&head, n);
}

Nodo * BuscaMinimo(Nodo * arbol){
  if(arbol == NULL ) return NULL;
  if(arbol->left == NULL ) return arbol;
  return BuscaMinimo(arbol->left);
}

Nodo * BuscaMaximo(Nodo * arbol){
  if(arbol == NULL ) return NULL;
  if(arbol->right == NULL ) return arbol;
  return BuscaMinimo(arbol->right);
}
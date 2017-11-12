/* gcc -Wall -o tree blatt2-rahmen.c --std=c99 */
#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
    struct node *left;
    struct node *right;
    int val;
};
struct node *new_node(int val)
{
	struct node *pointer;
	pointer = (struct node*)malloc(sizeof(struct node));
	(*pointer).left = NULL;
	(*pointer).right = NULL;
	(*pointer).val = val;
	return pointer;
}

struct node *insert(struct node *node, int val)
{
	if(node==NULL){return new_node(val);}
	if(val <= (*node).val){
		if((*node).left == NULL){
			(*node).left = new_node(val);
			return node;
		}
		else{
			(*node).left = insert((*node).left, val);
			return node;
		}
	}
	else{
		if((*node).right == NULL){
			(*node).right = new_node(val);
			return node;
		}
		else{
			(*node).right = insert((*node).right, val);
			return node;
		}
	}
}

struct node *make_random_tree(int num_nodes)
{
	struct node *pointer = NULL;
	srand((unsigned int)time(NULL));
	for(int i = 0; i<num_nodes; i++){
		pointer = insert(pointer, rand()%100);
	}
	return pointer;
}

/* Morris in-order traversal. */
void print_elements(struct node *node)
{
	if(node != NULL){
		if((*node).left != NULL){print_elements((*node).left);}
		printf("%d\n",(*node).val);
		if((*node).right != NULL){print_elements((*node).right);}
	}
}

void printPostorder(struct node* node)
{
     if (node == NULL)
        return;
     printPostorder((*node).left); 
     printPostorder((*node).right);
     printf("%d ", (*node).val);
}

void printInorder(struct node* node)
{
     if (node == NULL)
          return;  
     printInorder((*node).left);

     printf("%d ", (*node).val);  
     printInorder((*node).right);
}

void printPreorder(struct node* node)
{
     if (node == NULL)
          return;
     printf("%d ", (*node).val);  
     printPreorder((*node).left);  
     printPreorder((*node).right);
}    

/* Print the node's value */
void print_val(struct node *node)
{
printf("%d", (*node).val) ;
}
/* Add one to the node's value */
void plusone(struct node *node)
{
	node->val++;
}
/* hier habe ich verstanden dass man den Baum invertieren muss */
struct node* invertTree(struct node* node) {
    if (node) {
        node->left = invertTree(node->left), node->right = invertTree(node->right);
        const struct node* tmp = node->left;
        node->left = node->right;
        node->right = tmp;
    }
    return node;
}
void negate(struct node *node)
{
	if (node == NULL)
          return;
//     printf("%d ", (*node).val);  
     node->val = -node->val;
     negate((*node).left);  
     negate((*node).right);
	
}
void magic(struct node *node)
{
	if (node == NULL)
          return;
//     printf("%d ", (*node).val);  
     node->val = ((100-node->val)*(node->val-900));
     magic((*node).left);  
     magic((*node).right);
	
}
void free_node(struct node *node){
{
  if(node!=NULL)
  {
//    free_node(node->left);
//    free_node(node->right);
    free(node);
  }
}
}

int main(int argc, char *argv[])
{
    struct node *root = NULL;

    root = make_random_tree(10);

    printf("Printing in order (Morris Traversal):\n");
    print_elements(root);
    printf("\n");
    
    //Preorder , Inorder & Postorder
    
	printf("\nPreorder traversal of binary tree is \n");
	     printPreorder(root);
	 	
	     printf("\nInorder traversal of binary tree is \n");
	     printInorder(root);  
	 
	     printf("\nPostorder traversal of binary tree is \n");
	     printPostorder(root);
	     
	/* Print the node's value */
	  printf("\n");
	 printf("Printing given node value:\n");
		  print_val(root);   
//	     invertTree(root);
	     printf("\n");
	 printf("Printing plusone to given node value:\n");
	 	plusone(root);
	     print_val(root);
	      printf("\n");
	       printf("Printing negate to given node value:\n");
	      negate(root);
//	      	invertTree(root);
	     print_elements(root);
	      printf("\n");
	       printf("Printing magic to given node value:\n");
	     magic(root);
	     print_elements(root);
	      printf("\n");
	   free_node(root);
	  
	 
	     
    return EXIT_SUCCESS;
}

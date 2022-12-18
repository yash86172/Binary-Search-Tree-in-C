#include <stdio.h>
#include <stdlib.h>

struct node {
	int key;
	struct node *left, *right;
};

struct node* root = NULL;

struct node* newNode(int item)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

struct node* insert(struct node* node, int key)
{
	if (node == NULL)
		return newNode(key);
	if (key <= node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	return node;
}

int search(struct node* root,int key)
{
    struct node *temp = root;
    while (temp != NULL)
    {
        if (key == temp->key)
        {
            return 1;
        }
        else if (key > temp->key)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }
    return 0;
}
 

void inorder(struct node* root)
{
	if (root != NULL) 
    {
		inorder(root->left);
		printf("%d \n", root->key);
		inorder(root->right);
	}
}

void preorder(struct node* root)
{
    if (root != NULL)
    {
        printf("%d \n", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}
  
void postorder(struct node* root)
{
	if (root != NULL) 
    {
		postorder(root->left);
		postorder(root->right);
        printf("%d \n", root->key);
	}
}

struct node* deleteNode(struct node* root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        // node with only one child or no child
        if (root->left == NULL) 
        {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) 
        {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
  
        // node with two children: 
        // Get the inorder successor
        // (smallest in the right subtree)
    struct node* current = root->right;
    while (current && current->left != NULL)
        current = current->left;
    struct node* temp = current;

        // Copy the inorder 
        // successor's content to this node
        root->key = temp->key;
  
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

int main() 
{
    int choice, value;
    while (choice)
    {
        printf("\nEnter Choice:\n1.Create\n2.Insert\n3.Search\n4.In-Order Traversal\n5.Pre-Order Traversal\n6.Post-Order Traversal\n7.Delete\n8.Exit\n");
        scanf("%d", & choice);
        switch (choice) {
            case 1:
                printf("\nEnter the value to create tree: ");
                scanf("%d", & value);
                root = insert(root,value);
                break;
            case 2:
                printf("\nEnter the value to insert: ");
                scanf("%d", & value);
                insert(root,value);
                break;
            case 3:
                printf("\nEnter the value to search: ");
                scanf("%d", & value);
                if(search(root,value)==1)
                    printf("\nValue Found\n");
                else   
                    printf("\nValue Not Found\n");
                break;
            case 4:
                inorder(root);
                break;
            case 5:
                preorder(root);
                break;
            case 6:
                postorder(root);
                break;
            case 7:
                printf("\nEnter the value to be deleted: ");
                scanf("%d", & value);
                root = deleteNode(root, value);
                break;
            case 8:
                exit(0);
                return 0;
            default:
                printf("\nWrong Choice\n");
        }
    }
    return 0;
}





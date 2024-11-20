#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node
{
    char data;
    struct tree_node* lchild;
    struct tree_node* rchild;
} tree_node;

tree_node* make_tree_node()
{
    tree_node* result = (tree_node*) malloc(sizeof(tree_node));

    result->data = 0;
    result->lchild = NULL;
    result->rchild = NULL;

    return result;
}

char get_data(tree_node* target)
{
    return target->data;
}

void set_data(tree_node* target, char data)
{
    if (target == NULL)
    {
        return;
    }
    target->data = data;
}

tree_node* get_left_subtree(tree_node* root)
{
    tree_node* result = NULL;
    if (root != NULL)
    {
        result = root->lchild;
    }
    return result;
}

tree_node* get_right_subtree(tree_node* root)
{
    tree_node* result = NULL;
    if (root != NULL)
    {
        result = root->rchild;
    }
    return result;
}

void delete_tree(tree_node* root)
{
    if (root == NULL)
    {
        return;
    }
    delete_tree(root->lchild);
    delete_tree(root->rchild);
    free(root);
}

void make_left_subtree(tree_node* root, tree_node* sub)
{
    if (root == NULL)
    {
        return;
    }
    if (root->lchild != NULL)
    {
        delete_tree(root->lchild);
    }
    root->lchild = sub;
}

void make_right_subtree(tree_node* root, tree_node* sub)
{
    if (root == NULL)
    {
        return;
    }
    if (root->rchild != NULL)
    {
        delete_tree(root->rchild);
    }
    root->rchild = sub;
}

void print_preorder(tree_node* root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%c", root->data);
    print_preorder(root->lchild);
    print_preorder(root->rchild);
}

void print_inorder(tree_node* root)
{
    if (root == NULL)
    {
        return;
    }
    print_inorder(root->lchild);
    printf("%c", root->data);
    print_inorder(root->rchild);
}

void print_postorder(tree_node* root)
{
    if (root == NULL)
    {
        return;
    }
    print_postorder(root->lchild);
    print_postorder(root->rchild);
    printf("%c", root->data);
}

int main()
{
    int n;
    scanf("%d", &n);

    tree_node nodes[26] = {};

    for (int i = 0; i < n; i++)
    {
        nodes[i].data = 'A' + i;
        char parent, left, right;
        scanf(" %c %c %c", &parent, &left, &right);
        if (left != '.')
        {
            nodes[parent - 'A'].lchild = &nodes[left - 'A'];
        }
        if (right != '.')
        {
            nodes[parent - 'A'].rchild = &nodes[right - 'A'];
        }
    }
    print_preorder(nodes);
    printf("\n");
    print_inorder(nodes);
    printf("\n");
    print_postorder(nodes);

    return 0;
}
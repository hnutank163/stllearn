#include "Tree.h"

void tree_traversal(int *a, int n)
{
    BinaryTree<int> tree;
    for(int i=0; i<n; i++)
        tree.insert(a[i]);

    tree.preOrder();
    cout<<endl;
    tree.midOrder();
    cout<<endl;
    tree.postOrder();
    cout<<endl;
}

int
main()
{
    int a[] = {3,1,4,2,5};
    tree_traversal(a, 5);
    return (0);
}

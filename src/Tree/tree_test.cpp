#include "Tree.h"
#include <string>
#include <cstring>
using namespace std;

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
    tree.levelOrder();
    cout<<endl<<" after invert \n";
    tree.invert_BinaryTree();
    tree.levelOrder();
    cout<<endl<<" after invert recursion again\n";
    tree.invert_BinaryTree_Recur();
    tree.levelOrder();
    cout<<endl;
}

void tree_create()
{
    char pre[] = {'+','+','a','*','b','c','*','+','*','d','e','f','g'};
    string smid = "a+b*c+d*e+f*g";
    string spost = "abc*+de*f+g*+";
    char post[spost.size()+1];
    char mid[smid.size()+1];
    strncpy(mid, smid.c_str(), smid.size());
    strncpy(post, spost.c_str(), spost.size());
    BinaryTree<char> tree, tree2;
    tree.getTree_PreMid(pre, mid, smid.size());
    tree2.getTree_PostMid(post, mid, spost.size());
    tree.postOrder();
    cout<<endl;
    tree.midOrder();
    cout<<endl;
    tree.preOrder();
    cout<<endl;
    tree2.preOrder();
    cout<<endl;
}

int
main()
{
    int a[] = {3,1,4,2,5};
    tree_traversal(a, 5);

    tree_create();

    return (0);
}

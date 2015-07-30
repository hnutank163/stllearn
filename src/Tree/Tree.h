#ifndef _TREE_H_
#define _TREE_H_

#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

template< class Object>
class FsTree   //file system like tree
{
private:
    struct TreeNode
    {
        Object data;
        TreeNode *firstChild;
        TreeNode *nextSibling;
        TreeNode(const Object &obj = Object(), TreeNode *fs=NULL, TreeNode *ns=NULL)
            :data(obj), firstChild(fs), nextSibling(ns)
        {
        }
    };

public:
    FsTree();
    virtual ~FsTree();

    typedef TreeNode * iterator;
    iterator insert(const iterator & iter, const Object & obj)
    {
        if(iter->firstChild == NULL)
            iter->firstChild = new TreeNode(obj);
        else
            iter->nextSibling = new TreeNode(obj, NULL, iter->nextSibling);
    }

private:
    TreeNode *root;
};


template <class Object>
class BinaryTree
{
private:
    struct BinaryNode
    {
        Object data;
        BinaryNode *lchild;
        BinaryNode *rchild;
        BinaryNode(const Object & obj=Object(), BinaryNode *lc=NULL, BinaryNode *rc=NULL )
            :data(obj), lchild(lc), rchild(rc)
        {
        }
    };

public:
    BinaryTree():root(NULL){}

    const BinaryTree & operator=(const BinaryTree  & rhs)
    {
        if( this !=rhs )
        {
            makeEmpty();
            this->root = clone(rhs.root);
        }

        return * this;
    }
    virtual ~BinaryTree(){}
    void makeEmpty()
    {
         makeEmpty(this->root);
    }

    BinaryNode * clone( BinaryNode * t) const
    {
        if( t==NULL )
            return NULL;

        return new BinaryNode(t->data, clone(t->lchild), clone(t->rchild));
    }

    void Create_BinaryTree();
    void Create_BinarySearchTree(Object * obj);
    void insert(const Object & obj)
    {
        insert(obj, this->root);
    }

    void insert(const Object &obj , BinaryNode *& root)
    {
         if( root == NULL )
             root = new BinaryNode(obj);
         else if( obj < root->data )
             insert(obj, root->lchild);
         else
             insert(obj, root->rchild);
    }

    BinaryNode * findMin(BinaryNode * tree)
    {
         if( tree == NULL )
             return NULL;
        if( tree->lchild == NULL )
            return tree;
        findMin(tree->lchild);
    }

    BinaryNode * findMax(BinaryNode * tree )
    {
        if( tree == NULL  )
            return NULL;

        while(tree->rchild)
            tree = tree->rchild;

        return tree;
    }

    BinaryNode * remove(const Object &obj, BinaryNode * tree)
    {
        if(tree == NULL)
            return NULL;
        if( obj < tree->data )
            remove(obj, tree->lchild);
        else if( obj > tree->data )
            remove(obj, tree->rchild);

        if( tree->lchild != NULL && tree->rchild != NULL )  //two children
        {
             tree->data = findMin(tree->rchild)->data;
             remove(tree->data, tree->rchild);
        }
        else
        {
            BinaryNode *old = tree;
            tree = (tree->lchild != NULL) ? tree->lchild : tree->rchild;
            delete old;
        }

    }

    void preOrder(){ preOrder(this->root); }
    void midOrder(){ midOrder(this->root); }
    void postOrder(){ postOrder(this->root); }

    void levelOrder()
    {
        queue<BinaryNode *> que;
        que.push(this->root);

        while( !que.empty() )
        {
            BinaryNode * tmp = que.front();
            cout<<tmp->data<<" ";
            if( tmp->lchild  )
                que.push( tmp->lchild );
            if( tmp->rchild  )
                que.push( tmp->rchild );
            que.pop();
        }

        cout<<endl;
    }

    void preOrder(BinaryNode *tree)
    {
        if( tree==NULL  )
            return;

        cout<<tree->data<<" ";
        preOrder(tree->lchild);
        preOrder(tree->rchild);
    }

    void midOrder(BinaryNode *tree)
    {
         if( tree==NULL  )
             return;

        midOrder(tree->lchild);
        cout<<tree->data<<" ";
        midOrder(tree->rchild);
    }

    void postOrder(BinaryNode *tree)
    {
         if( tree==NULL  )
             return;

         postOrder(tree->lchild);
         postOrder(tree->rchild);
         cout<<tree->data<<" ";
    }

    void makeEmpty(BinaryNode * & tree)
    {
         if( tree != NULL)
         {
             makeEmpty(tree->lchild);
             makeEmpty(tree->rchild);
             delete tree;
         }

         tree = NULL;
    }

    void getTree_PreMid(Object *pre, Object *mid, int len)
    {
        getTree_PreMid(this->root, pre, mid, len);
    }

    void getTree_PostMid(Object *post, Object *mid, int len)
    {
        getTree_PostMid(this->root, post, mid, len);
    }

    void getTree_PreMid(BinaryNode *&pn, const Object *pre, const Object *mid, int len)
    {
        if( len == 0 )
            return;
        pn = new BinaryNode(pre[0]);
        for(int i=0; i<len; ++i)
        {
            if( mid[i] == pre[0] )
            {
                //next four line compare the ltree in mid-traversal and pre-traversal. when repeated element appear.
                vector<Object> vp(pre+1, pre+1+i);
                vector<Object> vm(mid, mid+i);
                sort(vp.begin(), vp.end());
                sort(vm.begin(), vm.end());
                if( vp == vm )
                {
                    getTree_PreMid(pn->lchild, pre+1, mid, i);
                    getTree_PreMid(pn->rchild, pre+1+i, mid+i+1, len-1-i);
                    break;
                }
            }
        }
    }

    void getTree_PostMid(BinaryNode *&pn, const Object *post, const Object *mid, int len)
    {
        if(len == 0)
            return;
        pn = new BinaryNode(post[len-1]);
        for(int i=0; i<len; ++i)
        {
             if( mid[i] == post[len-1] )
             {
                vector<Object> vp(post, post+i);
                vector<Object> vm(mid, mid+i);
                sort(vp.begin(), vp.end());
                sort(vm.begin(), vm.end());
                if( vp == vm )
                {
                     getTree_PostMid(pn->lchild, post, mid, i);
                     getTree_PostMid(pn->rchild, post+i, mid+i+1, len-i-1);
                     break;
                }
             }
        }
    }

private:
    BinaryNode *root;
};

#endif

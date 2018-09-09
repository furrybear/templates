#include <iostream>
using namespace std;

template < class T >
class BinaryTreeNode;

typedef BinaryTreeNode<char> Node;

template < class T >
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    BinaryTreeNode( const T &data = T() ):data(data),left(nullptr),right(nullptr){};
    //功能：从前序遍历、中序遍历恢复二叉树，要求T支持==操作符，并且不能有重复元素
    static BinaryTreeNode<T> * RestoreFromPreorderInorder(
            const T *aPreorder ,const T *aInorder , int len )
    {
        const T dataRoot = *aPreorder;
        BinaryTreeNode<T> *root = new BinaryTreeNode( dataRoot );
        int i;//记录前序遍历中第一个元素（也就是根），在中序遍历中的位置
        for ( i = 0 ; i < len ; i++ )
            if( aInorder[i] == dataRoot ) break;
        const int sizeLeft = i;//左子树元素数量
        const int sizeRight = len - i - 1;//右子树元素数量
        if( sizeLeft != 0 ) root->left = RestoreFromPreorderInorder( aPreorder + 1 , aInorder , sizeLeft );
        if( sizeRight != 0 ) root->right =  RestoreFromPreorderInorder( aPreorder + sizeLeft + 1 , aInorder + sizeLeft + 1 , sizeRight );
        return root;
    }
//功能：打印前序遍历、中序遍历、后序遍历
public:
    void printPreorder() const
    {
        printPreorderRec(this);
        cout << endl;
    }
    void printInorder() const
    {
        printInorderRec(this);
        cout << endl;
    }
    void printPostorder() const
    {
        printPostorderRec(this);
        cout << endl;
    }
private:
    void printPreorderRec(const BinaryTreeNode<T> *root) const
    {
        if( root == nullptr ) return;
        cout << root->data;
        printPreorderRec( root->left );
        printPreorderRec( root->right );
    }
    void printInorderRec(const BinaryTreeNode<T> *root) const
    {
        if( root == nullptr ) return;
        printInorderRec( root->left );
        cout << root->data;
        printInorderRec( root->right );
    }
    void printPostorderRec(const BinaryTreeNode<T> *root) const
    {
        if( root == nullptr ) return;
        printPostorderRec( root->left );
        printPostorderRec( root->right );
        cout << root->data;
    }
};

int main()
{
    char preorder[]="ABDECFGH";
    char inorder[]="DBEACFGH";
    Node *root = Node::RestoreFromPreorderInorder( preorder , inorder , sizeof(inorder)/sizeof(char)-1 );
    root->printPreorder();
    root->printInorder();
    root->printPostorder();
    return 0;
}

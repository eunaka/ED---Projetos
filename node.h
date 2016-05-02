#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
    private:
        Node* left;
        Node* right;
        T info;
      //  void setInfo(T info);

    public:
        Node(T);
        ~Node();
        Node* getLeftNode();
        Node* getRightNode();
        Node* getInfo();
        void setLeftNode(Node<T>*);
        void setRightNode(Node<T>*);
        bool isLeaf();
};

#endif // NODE_H

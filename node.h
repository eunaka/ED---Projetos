#ifndef NODE_H
#define NODE_H

class Node
{
    private:
        Node* left;
        Node* right;
        int info;

    public:
        Node(int);
        ~Node();
        Node* getLeftNode();
        Node* getRightNode();
        int getInfo();
        void setLeftNode(Node*);
        void setRightNode(Node*);
        bool isLeaf();
};

#endif // NODE_H

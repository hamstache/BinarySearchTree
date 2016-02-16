#ifndef __Lab__15__BSTNode__
#define __Lab__15__BSTNode__

#include <iostream>

template <typename Key, typename Value> class BSTNode;

template <typename Key, typename Value>
void print(std::ostream& os, BSTNode<Key, Value>* node, typename BSTNode<Key, Value>::TRAVERSAL order);

template <typename Key, typename Value>
std::ostream& operator<<(std::ostream& os, BSTNode<Key, Value>* node);

template <typename Key, typename Value>
class BSTNode {
public:
    BSTNode(Key key, Value value, int size,
            BSTNode<Key, Value>* left = nullptr, BSTNode<Key, Value>* right = nullptr);
    
    int size() const;
    int& size();
    
    Value value() const;
    Value& value();
    
    Key key() const;
    
    BSTNode<Key, Value>* left() const;
    BSTNode<Key, Value>*& left();
    
    BSTNode<Key, Value>* right() const;
    BSTNode<Key, Value>*& right();
    
    bool operator<(BSTNode<Key, Value> const& other) {return _key < other._key;}
    bool operator>(BSTNode<Key, Value> const& other) {return _key > other._key;}
    bool operator>=(BSTNode<Key, Value> const& other) {return !(_key < other._key);}
    bool operator<=(BSTNode<Key, Value> const& other) {return !(_key > other._key);}
    bool operator==(BSTNode<Key, Value> const& other) {return _key == other._key;}
    
    enum TRAVERSAL {PREORDER, INORDER, POSTORDER, LEVELORDER};
    
    friend void print <Key, Value>(std::ostream& os, BSTNode<Key, Value>* node, TRAVERSAL order);
    
    friend std::ostream& operator<< <Key, Value> (std::ostream& os, BSTNode<Key, Value>* node);
    
private:
    Key _key;
    Value _value;
    int _size;
    BSTNode<Key, Value> *_left, *_right;
};


template <typename Key, typename Value>
BSTNode<Key, Value>::BSTNode(Key key, Value value, int size, BSTNode<Key, Value>* left, BSTNode<Key, Value>* right)
: _key(key), _value(value), _size(size), _left(left), _right(right) { }

template <typename Key, typename Value>
int BSTNode<Key, Value>::size() const                       {return _size;}
template <typename Key, typename Value>
int& BSTNode<Key, Value>::size()                            {return _size;}

template <typename Key, typename Value>
Key BSTNode<Key, Value>::key() const                        {return _key;}

template <typename Key, typename Value>
Value BSTNode<Key, Value>::value() const                    {return _value;}
template <typename Key, typename Value>
Value& BSTNode<Key, Value>::value()                         {return _value;}

template <typename Key, typename Value>
BSTNode<Key, Value>* BSTNode<Key, Value>::left() const      {return _left;}
template <typename Key, typename Value>
BSTNode<Key, Value>*& BSTNode<Key, Value>::left()           {return _left;}

template <typename Key, typename Value>
BSTNode<Key, Value>* BSTNode<Key, Value>::right() const     {return _right;}
template <typename Key, typename Value>
BSTNode<Key, Value>*& BSTNode<Key, Value>::right()          {return _right;}

template <typename Key, typename Value>
void print(std::ostream& os, BSTNode<Key, Value>* node, typename BSTNode<Key, Value>::TRAVERSAL order) {
    if (node == nullptr) {return;}
    
    switch(order) {
        case BSTNode<Key, Value>::TRAVERSAL::PREORDER:
            os<<node<<std::endl;
            print(os, node->_left, order);
            print(os, node->_right, order);
            break;
            
        case BSTNode<Key, Value>::TRAVERSAL::INORDER:
            print(os, node->_left, order);
            os<<node<<std::endl;
            print(os, node->_right, order);
            break;
            
        case BSTNode<Key, Value>::POSTORDER:
            print(os, node->_left, order);
            print(os, node->_right, order);
            os<<node<<std::endl;
            break;
        default:
            throw std::invalid_argument("traversal order incorrect"); break;
    }
}

template <typename Key, typename Value>
std::ostream& operator<<(std::ostream& os, BSTNode<Key, Value>* node) {
    os<<"BSTNode<"; //typeid(Key).name()<<","<<typeid(Value).name()<<">"
    os<<"key="<<node->_key<<",value="<<node->_value;
    return os<<",size="<<node->_size<<"]";
}
#endif /* defined(__Lab__15__BSTNode__) */
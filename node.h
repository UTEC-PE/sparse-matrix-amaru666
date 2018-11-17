#ifndef NODE_H
#define NODE_H

using namespace std;

template <class T>
class Node {
    int x, y;
    T data;

public:
    Node* next = nullptr;
    Node* down = nullptr;
    Node(T data_, int x, int y):data{data_}, x {x}, y{y} {}
    Node(int cant, bool c) {
        if(c)
        { if(cant>0){
                cant--;
                this->next = new Node(cant, true);
        }} else { if(cant>0){
                cant--;
                this->down = new Node(cant, false);
        }}
    }

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    T getData() const {
        return data;
    }
};

#endif
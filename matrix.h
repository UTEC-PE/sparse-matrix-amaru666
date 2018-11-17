#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include "node.h"

using namespace std;

template <typename T>
class Matrix {
    private:
        Node<T>* hRows;
        Node<T>* hColumns;
        int columns;
        int rows;

    public:
        Matrix();
        Matrix(int sizeX, int sizeY):rows{sizeX}, columns{sizeY} {
            hRows = new Node<T>(rows, false);
            hColumns = new Node<T>(columns, true);
        };

        void set(int x, int y, T data) {
                Node<T>* node = new Node<T>(data,x,y);
                Node<T> *temp = hRows;
                Node<T> *temp2 = hColumns;
                for(int i = 0; i < x + 1; i++){
                    temp = temp->down;
                }
                if(!temp->next) temp->next = node;
                else {
                    while(temp->next) {
                        Node<T> *aux;
                        if(y <= temp->next->getY()) {
                            aux = temp->next;
                            temp->next = node;
                            node->next = aux;
                            break;
                        }else if(!temp->next->next){
                            temp->next->next = node;
                            break;
                        } else temp = temp->next;
                    }
                }
                for(int i = 0; i < y + 1 ; i++) {
                    temp2 = temp2->next;
                }
                if(!temp2->down) temp2->down = node;
                else {
                    while(temp2->down) {
                        Node<T> *aux;
                        if( x <= temp2->down->getX()) {
                            aux = temp2->down;
                            temp2->down = node;
                            node->down = aux;
                            break;
                        }else if (!temp2->down->down){
                            temp2->down->down =node;
                            break;
                        } else temp2 = temp2->down;
                    }
                }


            }
        T operator()(T x, T y) {
            if (x >= rows || x < 0) return 0;
            if (y >= columns || y < 0 ) return 0;
            Node<T> *rows_p = hRows;
            for(int i = 0; i < x + 1; i++) rows_p = rows_p->down;
            while (rows_p->next) {
                rows_p = rows_p->next;
                if(rows_p->getY() == y) return rows_p->getData();
                else if (rows_p->getY() > y) return 0;
            }
            return 0;
        };
        Matrix<T> operator*(Matrix<T> other){
        };
        Matrix<T> operator*(T scalar){};
        Matrix<T> operator+(Matrix<T> other){};
        Matrix<T> operator-(Matrix<T> other){};
        Matrix<T> transposed(){};
        Matrix<T> operator=(Matrix<T> other){};

        ~Matrix() {
            delete hRows;
            delete hColumns;
        };
};

#endif
#ifndef HEAP_H
#define HEAP_H

#include "HeapADT.h"

#include <stdlib.h>
#include <iostream>

using namespace std;
template <typename E>
class Heap : public HeapADT<E>
{
private:
    void heapfy(int pos){
        while(!isLeaf(pos)){
            int l = left(pos);
            int r = righ(pos);
            E aux;
            if((r < this->n1) && (this->content1[l] < this->content1[r])){
                l = r;
            }

            if(this->content1[pos] < this->content1[l]){
                aux = this->content1[pos];
                this->content1[pos] = this->content1[l];
                this->content1[l] = aux;
            }
            pos = l;
        }
    }

public:
    int n1;
    int maxsize1;
    E* content1;

    Heap(E *array, int num, int max){
        this->content1 = array;
        this->maxsize1 = max;
        this->n1 = num;
        this->buildMaxHeap();
    }

    int size() const{
        return this->n1;
    }

    bool isLeaf(int pos) const{
        if((pos >= this->n1/2) && (pos < this->n1)){
            return true;
        }
        else{
            return false;
        }
    }

    int left(int pos) const{
        return (2*pos + 1);
    }

    int righ(int pos) const{
        return (2*pos + 2);
    }

    int parent(int pos) const{
        return ((pos - 1) / 2);
    }

    void buildMaxHeap(){
        for (int i = this->parent(this->n1-1); i >= 0; i--){
            this->heapfy(i);
        }
    }

    void insert(const E &it){
        if(this->n1 < this->maxsize1){
            this->content1[this->n1] = it;
            this->n1++;
            this->buildMaxHeap();
        }
        else{
            if(this->n1 == this->maxsize1){
                cout << "Heap is full" << endl;
            }
        }
    }

    E removefirst(){
        if (this->n1 == 0){
            cout << "Heap is empty" << endl;
        }
        else{
            E aux;
            if (this->n1 == 1){
                aux = this->content1[0];
                this->n1--;
                return aux;
            }
            else{
                aux = this->content1[0];
                this->content1[0] = this->content1[this->n1-1];
                this->content1[this->n1-1] = aux;
                this->n1--;
                this->heapfy(0);
                return aux;
            }
        }
    }

    E remove(int pos){
        if(pos < 0 && pos >= this->n1){
            cout << "Bad position" << endl;
        }
        else{
            E aux;
            aux = this->content1[pos];
            this->content1[pos] = this->content1[this->n1-1];
            this->content1[this->n1-1] = aux;
            this->n1--;
            if(this->n1 != 0){
                this->heapfy(pos);
            }
            return aux;
        }
    }
};

#endif // HEAP_H

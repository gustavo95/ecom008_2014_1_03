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
            if((r < this->n) && (this->content[l] < this->content[r])){
                l = r;
            }

            if(this->content[pos] < this->content[l]){
                aux = this->content[pos];
                this->content[pos] = this->content[l];
                this->content[l] = aux;
            }
            pos = l;
        }
    }

public:
    Heap(E *array, int num, int max){
        this->content = array;
        this->maxsize = max;
        this->n = num;
        this->buildMaxHeap();
    }

    int size() const{
        return this->n;
    }

    bool isLeaf(int pos) const{
        if((pos >= this->n/2) && (pos < this->n)){
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
        for (int i = this->parent(this->n-1); i >= 0; i--){
            this->heapfy(i);
        }
    }

    void insert(const E &it){
        if(this->n < this->maxsize){
            this->content[this->n] = it;
            this->n++;
            this->buildMaxHeap();
        }
        else{
            if(this->n == this->maxsize){
                cout << "Heap is full" << endl;
            }
        }
    }

    E removefirst(){
        if (this->n == 0){
            cout << "Heap is empty" << endl;
        }
        else{
            E aux;
            if (this->n == 1){
                aux = this->content[0];
                this->n--;
                return aux;
            }
            else{
                aux = this->content[0];
                this->content[0] = this->content[this->n-1];
                this->content[this->n-1] = aux;
                this->n--;
                this->heapfy(0);
                return aux;
            }
        }
    }

    E remove(int pos){
        if(pos < 0 && pos >= this->n){
            cout << "Bad position" << endl;
        }
        else{
            E aux;
            aux = this->content[pos];
            this->content[pos] = this->content[this->n-1];
            this->content[this->n-1] = aux;
            this->n--;
            if(this->n != 0){
                this->heapfy(pos);
            }
            return aux;
        }
    }
};

#endif // HEAP_H

#include "heap.h"

#include <iostream>

using namespace std;
int main()
{
    int a[7], i;
    a[0] = 3;
    a[1] = 2;
    a[2] = 5;

    Heap<int> *test = new Heap<int>(a, 3, 7);
    if (test->isLeaf(1) == true){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }

    cout << test->left(0)<< endl;

    for(i = 0; i < test->n1; i++){
        cout << test->content1[i] << endl;
    }
    cout << endl;

    test->insert(9);
    test->insert(1);
    test->insert(6);

    for(i = 0; i < test->n1; i++){
        cout << test->content1[i] << endl;
    }
    cout << endl;

    cout << test->removefirst() << endl << endl;

    for(i = 0; i < test->n1; i++){
        cout << test->content1[i] << endl;
    }
    cout << endl;

    test->insert(11);
    test->insert(30);
    test->insert(5);

    test->remove(1);

    for(i = 0; i < test->n1; i++){
        cout << test->content1[i] << endl;
    }
    cout << endl;


}

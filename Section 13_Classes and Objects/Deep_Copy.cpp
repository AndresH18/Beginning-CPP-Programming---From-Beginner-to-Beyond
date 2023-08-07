//
// Created by andre on 6/8/2021.
//

#include "Deep_Copy.h"
#include <iostream>

using namespace std;

Deep_Copy::Deep_Copy(int d) {
    data = new int;
    *data = d;
}

//Deep_Copy::Deep_Copy(const Deep_Copy &source) : Deep_Copy(*source.data) {
//
//    cout << "Copy constructor - deep" << endl;
//}
Deep_Copy::Deep_Copy(const Deep_Copy &source) {
    data = new int;
    *data = *source.data;
    cout << "Copy constructor - deep" << endl;

}

Deep_Copy::Deep_Copy(Deep_Copy &&copy) : Deep_Copy{*copy.data} {
    copy.data = nullptr;
}

Deep_Copy::~Deep_Copy() {
    delete data;
    cout << "Destructor of DeepCopy freeing data" << endl;
}

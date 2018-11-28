//
//  main.cpp
//  DataStructureSamples
//
//  Created by 吴 歆韵 on 2018/11/23.
//  Copyright © 2018 Xavier Woo. All rights reserved.
//

#include <iostream>
#include "Vector.h"
#include "List.h"

void testVector(){
    Vector<int> vec;
    
    vec.insert(vec.size(), 1);
    vec.insert(vec.size(), 2);
    vec.insert(vec.size(), 3);
    vec.insert(vec.size(), 4);
    vec.insert(vec.size(), 5);
    vec.erase(3);
    vec.insert(vec.size(), 4);
    for(int i=0; i<vec.size(); ++i){
        std::cout<<vec.at(i)<<std::endl;
    }
}

void testList(){
    List<int> l;
    l.insert(l.end(), 1);
    List<int>::Iterator i2 = l.insert(l.end(), 2);
    l.insert(l.end(), 3);
    
    l.erase(i2);
    
    List<int>::Iterator itr = l.begin();
    
    while (itr != l.end()) {
        std::cout<<itr.get_data()<<std::endl;
        itr = itr.next();
    }
}

int main(int argc, const char * argv[]) {
    
    //testVector();
    testList();
    
    return 0;
}

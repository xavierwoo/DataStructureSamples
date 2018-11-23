//
//  main.cpp
//  DataStructureSamples
//
//  Created by 吴 歆韵 on 2018/11/23.
//  Copyright © 2018 Xavier Woo. All rights reserved.
//

#include <iostream>
#include "Vector.h"

int main(int argc, const char * argv[]) {
    // insert code here...
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
    
    return 0;
}

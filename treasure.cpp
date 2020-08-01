//
//  main.cpp
//  treasure
//
//  Created by Ciprian Ionescu on 7/28/20.
//  Copyright © 2020 Ciprian Ionescu. All rights reserved.
//

#include <iostream>
#include <fstream>

int main(int argc, const char * argv[]) {
    std::ifstream fin("input.txt");
    
    int x, y, a, b;
    while (fin >> x >> y >> a >> b) {
        x += 2020 * a;
        y += 2020 * b;
        std::cout << '(' << x << ',' << y << ')' << std::endl;
    }
    return 0;
}

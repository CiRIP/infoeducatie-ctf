//
//  main.cpp
//  room
//
//  Created by Ciprian Ionescu on 7/27/20.
//  Copyright © 2020 Ciprian Ionescu. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

std::vector<std::pair<double, double>> m;

bool second(const std::pair<double, double>& a, const std::pair<double, double>& b) {
    return (a.second < b.second);
}

double diff[100];

int main(int argc, const char * argv[]) {
    std::ifstream fin("teams.in");
    int n;
    fin >> n;
    for (int i = 0 ; i < n ; i++) {
        double x, y;
        fin >> x >> y;
        m.emplace_back(x, y);
    }
    std::sort(m.begin(), m.end(), second);
    
    double s = 0, last = 0, sd = 0;
    for (int i = 0 ; i < m.size() ; i++) {
        // std::cout << it.first << ' ' << it.second << std::endl;
        s += m[i].first;
        diff[i] = m[i].second - (m[i].first / 2) - last;
        // std::cout << diff[i] << ' ' << i << '-' << i + 1 << ' ';
        sd += diff[i];
        // std::cout << sd << std::endl;
        last = m[i].second + (m[i].first / 2);
    }
    // std::cout << s << ' ' << sd << std::endl;
    
    sd = diff[35];
    double ss = 0;
    for (int i = 36 ; i < m.size() ; i++) {
        sd += diff[i];
        ss += m[i].first;
        //std::cout << i << ' ' << i + 1 << ' ' << sd << std::endl;
        double sc = sd;
        double ssc = ss;
        for (int j = 34 ; j >= 0 ; j--) {
            sc += diff[j];
            ssc += m[j + 1].first;
            if (sc >= 45) {
                std::cout << j + 1 << ' ' << i << ' ' << i - j << ' ' << ssc << std::endl;
                break;
            }
            //std::cout << i << ' ' << i + 1 << ' ' << sd << std::endl;
        }
    }
    
    std::cout << diff[35];
    return 0;
}

#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdlib>
#include <ctime>

int get_random_int(int from, int to) {
    return from + rand() % (to - from);
}

auto Function(int n){
    srand(time(NULL));
    std::vector<std::vector<int>> v;
    std::set<int> used_sizes;
    int array_size;
    for (int i = 0; i < n; i++) {

        do {
            array_size = get_random_int(1, 100);
        } while (used_sizes.find(array_size) != used_sizes.end());

        used_sizes.insert(array_size);
        v.emplace_back(array_size);
        for (int j = 0; j < array_size; j++) {
            v[i][j] = get_random_int(1, 1000);
        }
        if (i % 2) {
            std::sort(v[i].begin(), v[i].end());
        } else {
            std::sort(v[i].rbegin(), v[i].rend());
        }
    }

    return v;
}

int main() {
    int n;

    std::cin >> n;
    auto v = Function(n);


    for (auto &arr: v) {
        for (auto &elem: arr) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}

/* Code on Python
import numpy as np
[sorted(x, reverse=i % 2==0) for i, x in enumerate([np.random.uniform(0, 1000, size=(np.random.randint(0, 100),)) for i in range(int(input()))])]
 */
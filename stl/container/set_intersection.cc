#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
#include <map>
using std::pair;
using std::set;
using std::string;

int main() {
    // 定义两个集合
    std::set<int> set1 = {1, 2, 3, 4, 5};
    std::set<int> set2 = {3, 4, 5, 6, 7};

    // 定义用于存储交集结果的集合
    std::set<int> result;

    for (int num : result) {
        std::cout << "num = " << num << " ";
    }

    // 使用 std::set_intersection 计算交集
    std::set_intersection(set1.begin(), set1.end(),
                          set2.begin(), set2.end(),
                          std::inserter(result, result.begin()));

    // 输出交集结果
    std::cout << "交集结果: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}


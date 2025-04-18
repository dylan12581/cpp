#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;


void test0()
{
    vector<int> num1{1,2};
    vector<int> num2{3,4};
    vector<int> num3{5,6};
    vector<vector<int>> vec;
    vec.push_back(num1);
    vec.push_back(num2);
    vec.push_back(num3);
    cout <<"vec对象所在地址:"<< &vec << endl;
    cout <<"vec对象占用大小为:"<< sizeof(vec) << endl;
    cout <<"vec对象容量为:"<< vec.capacity() << endl;
    cout <<"vec对象元素个数为:"<< vec.size() << endl;
    cout << endl;

    for(auto & ele : vec){
        for(auto & nu : ele){
            cout << nu << " ";
        }
        cout << endl;
    }
    for(int i = 0;i < vec.size();i++){
        cout << "vec对象中的成员num" <<i + 1<< "所在地址:"<<&vec[i] << endl;
        cout <<"vec对象中的成员num" << i + 1 <<"占用大小为："<< sizeof(vec[i]) << endl;
        cout <<"num容量为:"<< vec[i].capacity() << endl;
        cout <<"num中元素个数为:"<< vec[i].size() << endl;
        for(int j = 0;j < vec[i].size();j++){
            cout <<vec[i][j]<< "此int元素所在地址:"<< &vec[i][j] << endl;
            cout <<"此int元素占用大小为:"<< sizeof(vec[i][j]) << endl;
        }
    }

}

int main()
{
    test0();
    return 0;
}


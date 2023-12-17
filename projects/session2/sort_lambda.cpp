#include <iostream>
#include <algorithm>
#include <array>

inline void print_list(std::array<int,6> &list){
    for(auto element : list) std::cout << "element :" << element << "\n";
}
int main(){
    std::array<int, 6> list{ 70, 120, 15, 33, 2, 1};

    std::sort(list.begin(),list.end(),[](int a,int b)->bool {return a < b;});

    print_list(list);

    return 0;
}
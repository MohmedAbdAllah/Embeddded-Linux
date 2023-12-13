#include <iostream>

void swap(int& x, int& y){
    int temp = x;
    x = y;
    y = temp;

}

int main(){

    int x = 5, y = 10;
    std::cout << "before swap\n";
    std::cout << "x = " << x <<",y = " << y << std::endl;
    swap(x,y);
    std::cout << "after swap\n";
    std::cout << "x = " << x << ",y = " << y << std::endl;

    return 0;
}
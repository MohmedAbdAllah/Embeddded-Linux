#include <iostream>
#include <functional>  
void print(int a){
    std::cout << "a = " << a << "\n";
}
struct generated_lambda{
    void operator() (int a){
        std::cout << "a = " << a << "\n";
    }
};

int main(){
    std::function<void (int)> printer = print;
    generated_lambda ger;
    ger(5);
    printer(8);
    return 0;
}
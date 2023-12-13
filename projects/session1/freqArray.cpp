#include <iostream>
#include <map>
#include <array>
#include <vector>
#include <iterator>
#include <utility>

// int main(){
//     std::array<int,13> a  =  { 3,3,5,8,9,8,9,10,17,10,11,17,10};
//     std::map<int,int> elements;
//     for(auto &num : a){
//         elements[num]++;
//     }

//     for(auto it = elements.begin(); it != elements.end(); ++it){
//         std::cout << it->first << ":" << it->second <<"\n";
//     }

//     return 0;
// }
//***********************************************************************************************
void swap(int&i , int&j){
    int temp = i;
    i = j;
    j = temp;
}
int main(){
    std::array<int,13> a =  { 3,3,5,8,9,8,9,10,17,10,11,17,10};
    std::vector<std::pair<int,int>> element;
    
    for(auto i = 0; i < a.size(); i++){
        int min_index = i;
        for(auto j = i+1; j < a.size();j++){
            if(a.at(min_index) > a.at(j)){
                min_index = j;
            }

        }
        if(a.at(i) > a.at(min_index)){
            swap(a.at(i),a.at(min_index));
        }
    }

    int freq = 1;

    for(auto i = 0;i < a.size()-1; ++i){
        if(a.at(i) != a.at(i+1)){
            element.emplace_back(a.at(i),freq);
            freq =1;
        }else if((i+2) == a.size()){
            freq++;
            element.emplace_back(a.at(i),freq);
        }else{
            freq++;
        }
    }



    for(auto it = element.begin(); it != element.end(); ++it){
       std::cout << it->first << ":" << it->second <<"\n";
    }
    return 0;
}
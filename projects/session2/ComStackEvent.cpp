#include<iostream>
#include <functional>

constexpr unsigned int Ack = 0x77;

void CommStackOnEvent(std::function<void (int&)> changeResponse){
    int response =false;
    changeResponse(response);
    if(response  == 1){
        std::cout << "Data is Sended Successfully and Ack is Received Successfully\n";
    }else if(response  == 0){
        std::cout << "Data is Sended Successfully and Didn't Receive Ack \n";
    }else{
        std::cout << "Failed to Send Data\n";
    }

}

void send(std::function<int (int)> ComDriverSender,int&& data){
    auto onEvent = [&](int& response){
        response = ComDriverSender(data);
    };

    CommStackOnEvent(onEvent);
}

int DriverSender(int x){
    int Data_REG = x;
    if(Ack == 0x11){
        return 1;
    }else if(Ack == 0x22){
        return 0;
    }else{
        return -1;
    }
}

int main(){
    send(DriverSender,5);
    return 0;
}
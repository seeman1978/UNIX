//
// Created by wq on 2021/7/23.
//

#include <unistd.h>
#include <iostream>
#include <thread>

int main(){
    int pid=0;
    pid = fork();
    if (pid < 0){
        std::cout << "fork failed.\n";
    }
    else if (pid == 0){
        std::cout << "Printed from the child process\n";
    }
    else {
        std::cout << "Printed from the parent process\n";
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(2000ms);
    }
}
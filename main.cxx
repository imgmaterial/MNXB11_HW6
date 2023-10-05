#include <cstddef>
#include <cstdio>
#include <iostream>
#include <string>
int main(int argCount, char *argValues[]) {
    printf("%s", "Start");
    if (argCount == 3) {
        printf("%s", "if");
        std::string executableName{argValues[0]};
        std::string arg1{argValues[1]};
        char firstChar{*(argValues[1])};
        size_t exeLen{executableName.size()};
        int arg2{std::atoi(argValues[2])};
        int sum = 0;
        for (int ptr = 0; ptr < (int)arg1.size();ptr++){
            sum += arg1[ptr];
        }
        if ((sum ^ firstChar * 3) << (exeLen & 0x1f) == arg2) {
        std::cout << "Correct!" << std::endl;
        } 
        else {
        std::cout << "Wrong!" << std::endl;
        }
    }
}
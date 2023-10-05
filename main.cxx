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
        char currentArg1Letter{*(argValues[1])};
        size_t exeLen{executableName.size()};
        int arg2{std::atoi(argValues[2])};
        int sum = 0;
        int ptr = 0;
        while (true) {
            sum += arg1[ptr++];
            if (sum >= static_cast<int>(arg1.size())) {
                break;
            }
        }
        printf("integer %lu\n", (exeLen & 0x1f));
        if ((sum ^ currentArg1Letter * 3) << (exeLen & 0x1f) == arg2) {
        std::cout << "Correct!" << std::endl;
        } 
        else {
        std::cout << "Wrong!" << std::endl;
        }
    }
}
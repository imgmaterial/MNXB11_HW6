#include <cstddef>
#include <cstdio>
#include <iostream>
#include <string>
int CalculateKey(int _sum, std::string _inputStringArg1,  std::string _inputStringArg0){
    size_t exeLen{_inputStringArg0.size()};
    char firstChar{*(_inputStringArg1.data())};
    return(int)((_sum ^ firstChar * 3) << (exeLen & 0x1f));
}

int main(int argCount, char *argValues[]) {
    bool correctAmountOfArguments = (argCount == 3);
    if (correctAmountOfArguments) {
        std::string executableName{argValues[0]};
        std::string arg1{argValues[1]};
        int arg2{std::atoi(argValues[2])};
        int sum = 0;
        for (int ptr = 0; ptr < (int)arg1.size();ptr++){
            sum += arg1[ptr];
        }
        if (CalculateKey(sum, arg1, executableName) == arg2) {
        std::cout << "Correct!" << std::endl;
        } 
        else {
        std::cout << "Wrong!" << std::endl;
        }
    } 
}
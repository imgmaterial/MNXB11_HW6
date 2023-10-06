#include <cstddef>
#include <cstdio>
#include <iostream>
#include <string>
int CalculateKey(int _sum, std::string _inputStringArg1,  std::string _inputStringArg0){
    size_t exeLen{_inputStringArg0.size()};
    char firstChar{*(_inputStringArg1.data())};
    return(int)((_sum ^ firstChar * 3) << (exeLen & 0x1f));
}

bool ValidateInput(bool _correctAmountOfArguments, int _arg2){
    if (!_correctAmountOfArguments){
        std::cout << "Wrong amount of arguments! Two arguments should be passes with firstone being a string and second one an integer value i.e. MNXB11 23552" << std::endl;
        return 0;
    }
    
    if (_arg2 == 0){
        std::cout << "The second argument should be a positive integer value" << std::endl;
        return 0;
    }
    return 1;
}

int CalculateSum(std::string _arg1){
    int sum = 0;
    for (int ptr = 0; ptr < (int)_arg1.size();ptr++){
        sum += _arg1[ptr];
    }
    std::cout << "Sum value is " + std::to_string(sum) << std::endl;
    return sum;
}

void ShowOutput(std::string _arg1, std::string _executableName, int _arg2){
    int sum = CalculateSum(_arg1);
    int key = CalculateKey(sum, _arg1, _executableName); 
    if (key == _arg2) {
    std::cout << "Correct!" << std::endl;
    } 
    else {
    std::cout << "Wrong!" << std::endl;
    }
    std::cout << "Expected key is " + std::to_string(_arg2) + ". Calculated key is " + std::to_string(key) <<std::endl;
}

int main(int argCount, char *argValues[]) {
    bool correctAmountOfArguments = (argCount == 3);
    std::string executableName{argValues[0]};
    std::string arg1{argValues[1]};
    int arg2 = std::atoi(correctAmountOfArguments ? (argValues[2]) : "0");
    if (!ValidateInput(correctAmountOfArguments, arg2)){
        return 0;
    }
    ShowOutput(arg1, executableName,arg2);

}
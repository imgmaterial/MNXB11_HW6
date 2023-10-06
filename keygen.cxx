#include <cstddef>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <string>

//Calclates the sum corresponding to the input string.
int CalculateSum(std::string _inputString){
    int sum = 0;
    for (int ptr = 0; ptr < (int)_inputString.size();ptr++){
        sum += _inputString[ptr];
    }
    return sum;
}

int CalculateKey(int _sum, std::string _inputString,  size_t exeLen){
    char firstChar{*(_inputString.data())}; //pointer to a C-style string return the first character of the string
    return(int)((_sum ^ firstChar * 3) << (exeLen & 0x1f));
}

bool ValidateInput(bool _correctAmountOfArguments, int _exeLen){
    if (!_correctAmountOfArguments){
        std::cout << "Wrong amount of arguments! Two arguments should be passes with first one being a string and second one an integer value i.e. MNXB11 6" << std::endl;
        return 0;
    }
    //std::atoi returns 0 if it could not parse the string to integer.
    if (_exeLen == 0){
        std::cout << "The second argument should be a positive integer value" << std::endl;
        return 0;
    }
    return 1;
}

int main(int argCount, char *argValues[]){
    bool correctAmountOfArguments = (argCount == 3); //0: name of the keygen executable, 1: inputString 2: exeLen, length of the executable used to compare the key and the string. Used in the calculate key.
    int exeLen = std::atoi(correctAmountOfArguments ? argValues[2]:"0");
    if (!ValidateInput(correctAmountOfArguments, exeLen)){
        return 0;
    }
    std::string inputString = argValues[1];
    int inputSum = CalculateSum(inputString);
    int resultKey = CalculateKey(inputSum, inputString, exeLen);
    std::cout << resultKey << std::endl;
}
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <string>
//Function for calculating the key from provided arguments
int CalculateKey(int _sum, std::string _inputString,  std::string _inputStringArg0){
    size_t exeLen{_inputStringArg0.size()};
    char firstChar{*(_inputString.data())}; //pointer to a C-style string return the first character of the string
    return(int)((_sum ^ firstChar * 3) << (exeLen & 0x1f));
}
//Checks if the amount of input values is apropriate and that the second argument provided is an integer
bool ValidateInput(bool _correctAmountOfArguments, int _expectedKey){
    if (!_correctAmountOfArguments){
        std::cout << "Wrong amount of arguments! Two arguments should be passes with first one being a string and second one an integer value i.e. MNXB11 23552" << std::endl;
        return 0;
    }
    //std::atoi returns 0 if it could not parse the string to integer.
    if (_expectedKey == 0){
        std::cout << "The second argument should be a positive integer value" << std::endl;
        return 0;
    }
    return 1;
}
//Calclates the sum corresponding to the input string.
int CalculateSum(std::string _inputString){
    int sum = 0;
    for (int ptr = 0; ptr < (int)_inputString.size();ptr++){
        sum += _inputString[ptr];
    }
    std::cout << "Sum value is " + std::to_string(sum) << std::endl;
    return sum;
}
//checks if the key calculated from a provided string is the same as the provided expected key and outputs the result to the CLI.
void ShowOutput(std::string _inputString, std::string _executableName, int _expectedKey){
    int sum = CalculateSum(_inputString);
    int key = CalculateKey(sum, _inputString, _executableName); 
    if (key == _expectedKey) {
        std::cout << "Correct!" << std::endl;
    } 
    else {
        std::cout << "Wrong!" << std::endl;
    }
    std::cout << "Expected key is " + std::to_string(_expectedKey) + ". Calculated key is " + std::to_string(key) <<std::endl;
}

int main(int argCount, char *argValues[]) {
    //initialize all of the provided arguments
    bool correctAmountOfArguments = (argCount == 3);
    int expectedKey = std::atoi(correctAmountOfArguments ? (argValues[2]) : "0"); //if the value of provided arguments is correct then try to convert it from string to integer, else convert "0" to integer. Avoids segfault if the arguments were not provided.
    if (!ValidateInput(correctAmountOfArguments, expectedKey)){//print output form ValidateInput and return early if false.
        return 0;
    }
    std::string executableName{argValues[0]};
    std::string inputString{argValues[1]};
    ShowOutput(inputString, executableName,expectedKey);

}
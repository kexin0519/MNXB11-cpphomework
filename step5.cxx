#include <iostream> 
#include <string>
#include <cstdlib>

int calculatedcheckSum(std::string inputstring) {
    int charSum=0;
    for (std::string::size_type i = 0; i < inputstring.size(); i++) {
        charSum += inputstring[i];
    }   //the function is used to calculate the sum of ASCII values of each characters

    return charSum;
}

int calculateKey(int charSum, char firstparameter, size_t programNameLength) {
    int key = (charSum ^ firstparameter * 3) << (programNameLength & 0x1f);
    return key;   //the functionis used to calculated the value of the key
}

int main(int numbargc, char *grpargv[]) {
  if (numbargc == 3) {
    std::string program_name{grpargv[0]};
    char firstparameter{*(grpargv[1])};
    size_t programNameLength{program_name.size()};
    int inputnumber{std::atoi(grpargv[2])};
    int charSum=calculatedcheckSum (grpargv[1]);  //the function is use to calculate the check sum
    std::cout << "Calculated Key: " << calculateKey << std::endl; //this is use to double check the key
    int calculatedKey = calculateKey(charSum, firstparameter, programNameLength);
    if (calculatedKey== inputnumber) {   //this is use to show the results, if the key we calculated is equal yo the input number
      std::cout << "Correct!" << std::endl;
    } else {  //if not equal, the result will shows wrong!
      std::cout << "Wrong!" << std::endl;
    }
  }
}
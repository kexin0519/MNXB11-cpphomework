#include <iostream> 
#include <string>
#include <cstdlib>

int calculatedcheckSum(std::string inputstring) {
    int charSum=0;
    for (std::string::size_type i = 0; i < inputstring.size(); i++) {
        charSum += inputstring[i];
    }

    return charSum;
}

int calculateKey(int charSum, char firstparameter, size_t programNameLength) {
    int key = (charSum ^ firstparameter * 3) << (programNameLength & 0x1f);
    return key;
}

int main(int numbargc, char *grpargv[]) {
  if (numbargc == 3) {
    std::string program_name{grpargv[0]};
    char firstparameter{*(grpargv[1])};
    size_t programNameLength{program_name.size()};
    int inputnumber{std::atoi(grpargv[2])};
    int charSum=calculatedcheckSum (grpargv[1]);
    std::cout << "Calculated Key: " << calculateKey << std::endl;
    int calculatedKey = calculateKey(charSum, firstparameter, programNameLength);
    if (calculatedKey== inputnumber) {
      std::cout << "Correct!" << std::endl;
    } else {
      std::cout << "Wrong!" << std::endl;
    }
  }
}
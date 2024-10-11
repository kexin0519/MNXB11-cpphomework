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

int main(int numbargc, char *grpargv[]) {
  if (numbargc == 3) {
    std::string program_name{grpargv[0]};
    char firstparameter{*(grpargv[1])};
    size_t programNameLength{program_name.size()};
    int inputnumber{std::atoi(grpargv[2])};
    int charSum{0};
    std::string firstargument{grpargv[1]};
    if ((charSum ^ firstparameter * 3) << (programNameLength & 0x1f) == inputnumber) {
      std::cout << "Correct!" << std::endl;
    } else {
      std::cout << "Wrong!" << std::endl;
    }
  }
}
#include <iostream>
#include <sstream>
#include <string>

namespace safeInputs {
    long long safeBoundedNumberInput(std::string message = "",
                                     long long lowerBound = 0,
                                     long long upperBound = 1000) {
        std::string input_line;
        long long input_temp_number = 0;

        std::cout << message;

        while (std::cin >> input_line) {
            std::istringstream iss(input_line);
            if (!(iss >> input_temp_number)) {
                std::cout << "Input a valid integer:";
                continue;
            }

            if (input_temp_number < lowerBound ||
                input_temp_number > upperBound) {
                std::cout << "Input an integer in range [" << lowerBound << ", "
                          << upperBound << "]: ";
            } else {
                break;
            }
        }

        return input_temp_number;
    }
}  // namespace safeInputs
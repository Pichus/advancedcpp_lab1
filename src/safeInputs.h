#pragma once
#include <string>

namespace safeInputs {
    /*
     Input wrapper for an integer in range [lowerBound, upperBound] with
     optional input message. Retries on failure.
     */

    long long safeBoundedNumberInput(std::string message = "",
                                     long long lowerBound = 0,
                                     long long upperBound = 1000);
}  // namespace safeInputs
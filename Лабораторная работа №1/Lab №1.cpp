#include <iostream>
#include <limits>
#include <iomanip>

template<typename T>
void calculateMachineProperties(const std::string& typeName) {
    T value = 1;
    int zeroExponent = 0;
    while (value / 2 > 0) {
        value /= 2;
        zeroExponent--;
    }

    value = 1;
    int infinityExponent = 0;
    while (value < std::numeric_limits<T>::max()) {
        value *= 2;
        infinityExponent++;
    }

    value = 1;
    int epsilonExponent = 0;
    while ((value + 1) > 1) {
        value /= 2;
        epsilonExponent--;
    }

    std::cout << "[" << typeName << "] Машинный нуль = 2^" << zeroExponent << std::endl;
    std::cout << "[" << typeName << "] Машинная бесконечность = 2^" << infinityExponent << std::endl;
    std::cout << "[" << typeName << "] Машинный эпсилон = 2^" << epsilonExponent << std::endl;
    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << std::fixed << std::setprecision(20);
    calculateMachineProperties<float>("float");
    calculateMachineProperties<double>("double");
    calculateMachineProperties<long double>("long double");

    return 0;
}

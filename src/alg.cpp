// Copyright 2022 NNTU-CS
#include <cstdint>
#include <cmath>
#include <vector>

bool checkPrime(uint64_t value) {
    if (value < 2) return false;
    if (value == 2) return true;
    if (value % 2 == 0) return false;
    
    uint64_t limit = static_cast<uint64_t>(std::sqrt(value));
    for (uint64_t i = 3; i <= limit; i += 2) {
        if (value % i == 0) return false;
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
    if (n == 0) return 0;
    if (n == 1) return 2;
    
    uint64_t count = 1; // уже посчитали 2
    uint64_t candidate = 3;
    
    while (count < n) {
        if (checkPrime(candidate)) {
            count++;
        }
        candidate += 2;
    }
    return candidate - 2;
}

uint64_t nextPrime(uint64_t value) {
    uint64_t candidate = value + 1;
    if (candidate <= 2) return 2;
    
    while (!checkPrime(candidate)) {
        candidate++;
    }
    return candidate;
}

uint64_t sumPrime(uint64_t hbound) {
    if (hbound <= 2) return 0;
    
    uint64_t sum = 2; // включаем 2
    for (uint64_t i = 3; i < hbound; i += 2) {
        if (checkPrime(i)) {
            sum += i;
        }
    }
    return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
    if (hbound <= lbound + 2) return 0;
    
    uint64_t count = 0;
    
    // Находим первое простое число в диапазоне
    uint64_t first = lbound;
    while (first < hbound && !checkPrime(first)) {
        first++;
    }
    
    if (first >= hbound) return 0;
    
    uint64_t second = first + 1;
    while (second < hbound) {
        if (checkPrime(second)) {
            if (second - first == 2) {
                count++;
            }
            first = second;
        }
        second++;
    }
    
    return count;
}

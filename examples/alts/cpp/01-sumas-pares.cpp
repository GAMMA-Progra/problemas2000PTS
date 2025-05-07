// #include <array>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <span>


// Esto funciona. ¿Por qué?
bool isEven(int num) {
    return num % 2 == 0;
}


std::uint64_t nChooseK(std::uint64_t n, std::uint64_t k) {
    if (k == 0) return 1;
    if (n == k) return 1;
    if (k > n) return 0;

    if (k > n / 2)
        k = n - k;

    std::uint64_t res = n;

    for(std::uint64_t idx = 2; idx <= k; ++idx) {
        res *= (n - idx + 1);
        res /= idx;
    }

    return res;
}


std::size_t countEvens(std::span<int> nums) {
    std::size_t evenCount = 0;

    for (int num : nums)
        if (isEven(num))
            evenCount++;

    return evenCount;
}


int main() {
    // Investigar alternativa:
    // std::array arr = { 22, 1, 23, 12, 68 };
    int arr[] = { 22, 1, 23, 12, 68 };

    auto evenCount = countEvens(arr);
    // auto oddCount = arr.size() - evenCount;
    auto oddCount = sizeof(arr) / sizeof(int) - evenCount;

    auto evenSums1 = nChooseK(evenCount, 2);
    auto evenSums2 = nChooseK(oddCount, 2);

    std::cout << evenSums1 + evenSums2 << '\n';
}

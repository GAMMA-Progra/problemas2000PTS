#pragma once

#include <cmath>
#include <cstddef>
#include <cstdint>
#include <limits>
#include <numeric>
#include <type_traits>



// Type aliases
using u8 = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;

using i8 = std::int8_t;
using i16 = std::int16_t;
using i32 = std::int32_t;
using i64 = std::int64_t;

using usize = std::size_t;

template <typename T>
using num_lim = std::numeric_limits<T>;



// Literals
constexpr u8 operator""_u8(unsigned long long value) {
    return static_cast<u8>(value);
}

constexpr u16 operator""_u16(unsigned long long value) {
    return static_cast<u16>(value);
}

constexpr u32 operator""_u32(unsigned long long value) {
    return static_cast<u32>(value);
}

constexpr u64 operator""_u64(unsigned long long value) {
    return static_cast<u64>(value);
}

constexpr i8 operator""_i8(unsigned long long value) {
    return static_cast<i8>(value);
}

constexpr i16 operator""_i16(unsigned long long value) {
    return static_cast<i16>(value);
}

constexpr i32 operator""_i32(unsigned long long value) {
    return static_cast<i32>(value);
}

constexpr i64 operator""_i64(unsigned long long value) {
    return static_cast<i64>(value);
}



// Constants
constexpr u32 MOD = 1000000007;
constexpr float PI = 3.141592653589793f;

constexpr float EPSILON_F = num_lim<float>::epsilon();
constexpr double EPSILON_D = num_lim<double>::epsilon();



// Utils
template <typename T,
         typename = typename std::enable_if<std::is_unsigned<T>::value>::type>
constexpr T mod(i64 k, T n) {
    return static_cast<T>( ( (k %= n) < 0 ) ? k + n : k );
}

template <typename T,
         typename = typename std::enable_if<std::is_signed<T>::value>::type>
constexpr T mod_u(i64 k, T n) {
    return static_cast<T>( ( (k %= n) < 0 ) ? k + n : k );
}


template <typename T>
constexpr T num_max() {
    return num_lim<T>::max();
}

template <typename T>
constexpr T num_min() {
    return num_lim<T>::min();
}


template<typename T>
typename std::enable_if<std::is_floating_point<T>::value, bool>::type
constexpr float_equal(T a, T b, T epsilon = num_lim<T>::epsilon() * 100) {
    return std::fabs(a - b) < epsilon;
}


template <typename T, typename It>
constexpr T sum_all(It begin, It end) {
    return std::accumulate(begin, end, static_cast<T>(0));
}


template <typename T>
constexpr T mod_sum(T first, T second, T mod = MOD) {
    return ( first % mod + second % mod ) % mod;
}

template <typename T>
constexpr T mod_mul(T first, T second, T mod = MOD) {
    return ( (first % mod) * (second % mod) ) % mod;
}


template <typename T>
constexpr T safe_sum(T first) {
    return first;
}

template <typename T, typename... Args>
constexpr T safe_sum(T first, Args... args) {
    return mod_sum(first, safe_sum(args...));
}


template <typename T>
constexpr T safe_mul(T first) {
    return first;
}

template <typename T, typename... Args>
constexpr T safe_mul(T first, Args... args) {
    return mod_mul(first, safe_mul(args...));
}



#ifdef IOSUTILS

#include <iostream>
#include <string>

static void fastio() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cout.sync_with_stdio(false);
}

template <typename T>
T read_next() {
    T val;
    std::cin >> val;
    return val;
}

template <>
u8 read_next() {
    u16 val;
    std::cin >> val;
    return static_cast<u8>(val);
}

template <>
i8 read_next() {
    i16 val;
    std::cin >> val;
    return static_cast<i8>(val);
}

char next_char() {
    char ch;
    std::cin >> ch;
    return ch;
}

char next_char_ws() {
    char ch;
    std::cin.get(ch);
    return ch;
}

std::string next_word() noexcept {
    std::string word;
    std::cin >> std::ws >> word;
    return word;
}

#endif



// Macros
#define COMBINE_HELPER(X, Y) X##Y
#define COMBINE(X, Y) COMBINE_HELPER(X, Y)


#define range_all(cont) std::begin(cont), std::end(cont)
#define range_rall(cont) (cont).rbegin(), (cont).rend()


#define repeat(times) \
    for (usize COMBINE(_idx, __LINE__) = 0; COMBINE(_idx, __LINE__) < times; ++COMBINE(_idx, __LINE__))


#define for_range(var_name, start, end) \
    for (usize var_name = start; var_name < end; ++var_name)


#define forr_enumerate(decl_var, idx_name, container)   \
    for (usize idx_name = 0; idx_name < (container).size(); ++idx_name) {   \
        decl_var = (container)[idx_name]; \


#define for_enumerate(decl, idx, container) \
    for (usize idx = 0, COMBINE(_end, __LINE__) = (container).size(); idx < COMBINE(_end, __LINE__); ++idx) \
        for (bool COMBINE(_once, __LINE__) = true; COMBINE(_once, __LINE__); COMBINE(_once, __LINE__) = false) \
            for (decl = (container)[idx]; COMBINE(_once, __LINE__); COMBINE(_once, __LINE__) = false)


#ifdef DEBUG

#include <array>
#include <iostream>
#include <utility>
#include <vector>

template<typename T, usize SIZE>
std::ostream& operator<<(std::ostream& oss, const std::array<T, SIZE>& arr) {
    oss << "[ ";

    for (usize idx = 0; idx < SIZE - 1; ++idx)
        oss << arr[idx] << ", ";

    return oss << arr[SIZE - 1] << " ]";
}

template<typename T>
std::ostream& operator<<(std::ostream& oss, const std::vector<T>& vec) {
    oss << "[ ";

    for (usize idx = 0; idx < vec.size() - 1; ++idx)
        oss << vec[idx] << ", ";

    return oss << vec[vec.size() - 1] << " ]";
}


#define debug(x) std::cerr << "dbg!("#x")" << ":\t" << (x) << std::endl;


#define dbg(x)   \
    ([&]() {    \
        auto&& _dbg_value = (x);     \
        std::cerr << __FILE__ << ':' << __LINE__    \
            << ": dbg!(" #x ") = " << _dbg_value << std::endl;   \
        return std::forward<decltype(_dbg_value)>(_dbg_value);    \
    })()    \

#endif

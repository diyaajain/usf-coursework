/* Name: Diya Jain
U81673988 */
#include <iostream>
template <typename T1, typename T2>
class Pair {
public:
    Pair(T1 first, T2 second) : first(first), second(second) {}

    T1 first;
    T2 second;
};

int main() {
    Pair<int, std::string> p1(2, "two");
    std::cout << "Pair 1: " << p1.first << ", " << p1.second << std::endl;

    Pair<float, long> p2(3.4, 2000);
    std::cout << "Pair 2: " << p2.first << ", " << p2.second << std::endl;

    Pair<bool, char> p3(true, 'Z');
    std::cout << "Pair 3: " << p3.first << ", " << p3.second << std::endl;

    Pair<double, int> p4(3.14, 42);
    std::cout << "Pair 4: " << p4.first << ", " << p4.second << std::endl;

    Pair<std::string, std::string> p5("hello", "world");
    std::cout << "Pair 5: " << p5.first << ", " << p5.second << std::endl;

    return 0;
}

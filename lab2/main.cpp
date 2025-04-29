#include <iostream>
#include "triangle.h"

int main() {
    Point A, B, C;
    std::cout << "Enter points:\n";
    std::cout << "A (x y): "; std::cin >> A.x >> A.y;
    std::cout << "B (x y): "; std::cin >> B.x >> B.y;
    std::cout << "C (x y): "; std::cin >> C.x >> C.y;

    if (isDegenerateTriangle(A, B, C)) {
        std::cout << "Triangle is degenerate\n";
        return 0;
    }

    int n;
    std::cout << "Enter amount of points to check: ";
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        Point P;
        std::cout << "\n Point" << i + 1 << " (x y): ";
        std::cin >> P.x >> P.y;
        checkPointInTriangle(A, B, C, P);
    }

    return 0;
}

#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <vector>

template<class T>
std::vector<T> generate_random_vector(std::size_t num, T min = -10, T max = 10)
{
    std::random_device rd;
    std::mt19937 e2(rd());
    std::uniform_real_distribution<> dist(min, max);
    auto lambda = [&e2, &dist]() -> T { return dist(e2); };
    std::vector<T> result(num);
    std::generate_n(result.begin(), num, lambda);
    return result;
}

int main() {
    std::cout << "enter the length of 1 massive" << std::endl;
    int n = 0;
    std::cin >> n;
    std::vector<int> massive = generate_random_vector<int>(n, -50, 50);
    for (int i = 0; i < n; ++i) {
        std::cout << massive[i] << " ";
    }
    std::cout << std::endl;
    int tempr1 = 0;
    std::cout << "sorted massive1" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int g = 0; g < n - i - 1; ++g)
        {
            if (massive[g] > massive[g + 1])
            {
                tempr1 = massive[g];
                massive[g] = massive[g + 1];
                massive[g + 1] = tempr1;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        std::cout << massive[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "enter the length of 2 massive" << std::endl;
    int m = 0;
    std::cin >> m;
    std::vector<int> vector = generate_random_vector<int>(m, -50, 50);
    for (int i = 0; i < m; ++i) {
        std::cout << vector[i] << " ";
    }
    int tempr2 = 0;
    std::cout << "sorted massive2" << std::endl;
    for (int i = 0; i < m; ++i)
    {
        for (int g = 0; g < m - i - 1; ++g)
        {
            if (vector[g] > vector[g + 1])
            {
                tempr2 = vector[g];
                vector[g] = vector[g + 1];
                vector[g + 1] = tempr2;
            }
        }
    }
    return 0;
}

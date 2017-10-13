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

int main()
{
    std::cout << "enter the length of massive" << std:: endl;
    int n = 0;
    std::cin >> n;
    std::vector<int> massive = generate_random_vector<int>(n, -50, 50);
    for (int i = 0; i < n - 1; ++i)
    {
        std::cout << massive[i] << " ";
    }
    std::cout << std::endl;
    int tempr = 0;
    std::cout << "sorted massive" << std::endl;
    for (int i = 0; i < n - 1; ++i)
            {
                    for (int g = 0; g < n - i - 1; ++g)
                    {
                        if (massive[g] > massive[g + 1])
                        {
                            tempr = massive[g];
                            massive[g] = massive[g + 1];
                            massive[g + 1] = tempr;
                        }
                    }
            }
            for (int i = 0; i < n - 1; ++i)
            {
                std::cout << massive[i] << " ";
            }
    
    return 0;
}

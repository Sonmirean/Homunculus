/*
 * For now no project structure, nor purpose, just put things here
 */

#include <cassert>
#include <cstddef>
#include <iostream>
#include <vector>

template <typename T>
bool perceptron(std::vector<T>& xs, std::vector<T>& ws, T bias) 
{
    assert(xs.size() == ws.size());
    T sum = 0;

    for (std::size_t i = 0; i < xs.size(); i++) {
        sum += xs[i] * ws[i];
    }

    return sum + bias > 0;
}

int main() 
{
    // For now tests go here

    float bias = -1;
    std::vector<float> xs = {10.940, 20.1209, 1.2032, -126.234};
    std::vector<float> ws = {1.0000, 10.5000, 11.023,   21.000};

    bool is_active = perceptron(xs, ws, bias);
    std::cout << "Is active: " << is_active << '\n';
}
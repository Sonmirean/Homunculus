/*
 * For now no project structure, nor purpose, just put things here
 */

#include <cmath>
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <vector>

#define sigmoid_func(z) (1 / (1 + std::exp(-(z))))

template <typename T>
bool perceptron(std::vector<T>& xs, std::vector<T>& ws, T bias) 
{
    if (xs.size() != ws.size())
        throw std::invalid_argument("Xs an weights must have same size");

    T sum = 0;
    for (std::size_t i = 0; i < xs.size(); i++)
        sum += xs[i] * ws[i];

    return sum + bias > 0;
}

template <typename T>
T sigmoid_neuron(std::vector<T>& xs, std::vector<T>& ws, T bias) 
{
    if (xs.size() != ws.size())
        throw std::invalid_argument("Xs an weights must have same size");

    T sum = 0;
    for (std::size_t i = 0; i < xs.size(); i++)
        sum += xs[i] * ws[i];

    return sigmoid_func(sum + bias);
}

int main() 
{
    // For now tests go here

    int bias = -1;
    std::vector<int> xs = {10, 2, 1,  -12};
    std::vector<int> ws = {1,  1, 11,  21};

    float bias2 = 1.234;
    std::vector<float> xs2 = {112.247, 2.31, 1.98, -102.11};
    std::vector<float> ws2 = {678.122, 1.24, 1.00,  1.56};

    bool is_active = perceptron(xs, ws, bias);
    float coef = sigmoid_neuron(xs2, ws2, bias2);

    std::cout << "(Perceptron) Is active: " << is_active << '\n';
    std::cout << "(Sigmoid) Coefficient: " << coef << '\n';
}
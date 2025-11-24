/*
 * For now no project structure, nor purpose, just put things here
 */

#include <cmath>
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <vector>

inline double sigmoid(double x) 
{
    return 1.0 / (1.0 + std::exp(x));
}

bool perceptron(std::vector<double>& xs, std::vector<double>& ws, double bias) 
{
    if (xs.size() != ws.size())
        throw std::invalid_argument("Xs an weights must have same size");

    double sum = bias;
    for (std::size_t i = 0; i < xs.size(); i++)
        sum += xs[i] * ws[i];

    return sum > 0;
}

double sigmoid_neuron(std::vector<double>& xs, std::vector<double>& ws, double bias) 
{
    if (xs.size() != ws.size())
        throw std::invalid_argument("Xs an weights must have same size");

    double sum = bias;
    for (std::size_t i = 0; i < xs.size(); i++)
        sum += xs[i] * ws[i];

    return sigmoid(sum);
}

int main() 
{
    // For now tests go here

    double bias = -1;
    std::vector<double> xs = {10, 2, 1,  -12};
    std::vector<double> ws = {1,  1, 11,  21};

    double bias2 = 1.234;
    std::vector<double> xs2 = {112.247, 2.31, 1.98, -102.11};
    std::vector<double> ws2 = {678.122, 1.24, 1.00,  1.56};

    bool is_active = perceptron(xs, ws, bias);
    double coef = sigmoid_neuron(xs2, ws2, bias2);

    std::cout << "(Perceptron) Is active: " << is_active << '\n';
    std::cout << "(Sigmoid) Coefficient: " << coef << '\n';
}
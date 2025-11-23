
#include <math.h>

#include "neuron.hpp"

// doubles bc they're more precise

bool Homunculus::perceptron(std::map<bool, double> inputs, long long int id)
{
	double sum = 0;
	for (const auto& [x, w] : inputs) { sum += x * w; } // Σ
	return sum + bias(id) > 0 ? true : false; // If sum of variables multipled by their
											  // weights is more than zero, neuron fires.
}

double Homunculus::sigmoid(std::map<bool, double> inputs, long long int id)
{
	double sum = 0;
	for (const auto& [x, w] : inputs) { sum += x * w; } // Σ
	return 1 / 1 + exp(-sum); // Small changes in inputs -> small changes in output.
}

// TODO
// this function must reach into the loaded neural data and get
// the bias of the neuron with the specified id
constexpr double Homunculus::bias(long long int id)
{
	return 0.0f;
}
// constexpr is to avoid runtime overhead.
// Optimization is crucial in neural networks.

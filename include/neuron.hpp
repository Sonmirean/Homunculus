#pragma once

#include <map>

// Global namespace for the project. For convenience,
// all the project's functions, classes, variables etc.
// must be declared inside of this namespace.
namespace Homunculus
{

	bool perceptron(std::map<bool, double> inputs, long long int id);

	double sigmoid(std::map<bool, double> inputs, long long int id);

	// Get the bias of specified neuron.
	constexpr double bias(long long int id);
}
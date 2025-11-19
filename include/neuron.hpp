#pragma once

#include <map>

// Global namespace for the project. For convenience,
// all the project's functions, classes, variables etc.
// must be declared inside of this namespace.
namespace Homunculus
{

	bool perceptron(std::map<bool, float> inputs, long long int id);

	float sigmoid(std::map<bool, float> inputs, long long int id);

	// Get the bias of specified neuron.
	float bias(long long int id);
}
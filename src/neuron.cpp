
#include "neuron.hpp"

bool Homunculus::perceptron(std::map<bool, float> inputs, long long int id)
{
	float sum = 0;

	for (const auto& [x, w] : inputs)
	{
		sum += x * w;
	}

	return sum + bias(id) > 0 ? true : false;
}

// TODO
float Homunculus::bias(long long int id)
{
	return 0.0f;
}

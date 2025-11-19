#pragma once

#include <string>

// Length of the buffer allocated for neuron's biases.
#define HMC_BUFFER_LENGTH

namespace Homunculus
{

	/*
	 * Saves the changes made to all the neurons to the file.
	 * 
	 * @param std::string path - Path to the folder.
	 */
	void save(std::string path);


	/*
	 * Loads the set of neural layers from the binary file.
	 * Note that the file must be named and formatted according
	 * to the project's convention.
	 * 
	 * @param std::string path - Path to the folder.
	 */
	void load(std::string path);


	class Instance
	{
		float buffer[HMC_BUFFER_LENGTH];


	};
}
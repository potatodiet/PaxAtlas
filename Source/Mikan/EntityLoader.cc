#include "EntityLoader.hh"

#include <fstream>

#include <iostream>

Mikan::EntityLoader::EntityLoader()
{
}

void Mikan::EntityLoader::load_json(const std::string file_location)
{
	Json::Reader reader;

	std::ifstream provinces_file;
	provinces_file.open(file_location);

	bool parsingSuccessful = reader.parse(provinces_file, root);
	if (!parsingSuccessful)
	{
		// Should instead print to a log file
		std::cout
			<< "Failed to parse configuration"
			<< std::endl
			<< reader.getFormattedErrorMessages();
		return;
	}
}

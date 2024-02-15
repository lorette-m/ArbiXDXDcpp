#include <iostream>
#include "Client.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

std::string GetFieldFromJson(std::string json, std::string field)
{
	std::stringstream jsomEncoded(json);
	boost::property_tree::ptree root;
	boost::property_tree::read_json(jsomEncoded, root);

	if (root.empty())
	{
		return "";
	}
	return root.get <std::string> (field);
}

int main()
{
	Client client;
	
	std::cout << client.getResponse();

	return 0;
}
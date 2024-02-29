#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include <nlohmann/json.hpp>
#include <curl/curl.h>
#include <vector>

using json = nlohmann::json;

class Client
{
public:

    bool getResponse();

};

#endif  
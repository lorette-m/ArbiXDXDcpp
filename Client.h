#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include <nlohmann/json.hpp>
#include <curl/curl.h>
#include <vector>
#include <map>
#include <set>
#include "Market.h"
#include <algorithm>

using json = nlohmann::json;

class Client
{
public:

    bool getResponse();

//private:
    /*struct Market
    {
        std::vector <std::string> peres;
        std::map <std::string, std::string> data;

    };*/

};

#endif  
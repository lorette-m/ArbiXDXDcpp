#pragma warning(disable : 4996)
#include "Client.h"
#include < string.h >
#include <errno.h>
#include <stdlib.h>     // for _countof
#include <stdio.h>
#include <cstring> 

size_t write_callback(char* ptr, size_t size, size_t nmemb, std::string* data) {
    data->append(ptr, size * nmemb);
    return size * nmemb;
}

bool Client::getResponse()
{
    

    std::vector<std::string> CRYPTO_CURRENCIES{ "GRIMACEUSDT", "BTCUSDT", "ETHUSDT", "SOLUSDT", "XRPUSDT", "LINKUSDT", "ARBUSDT", "TRXUSDT", "DOGEUSDT", "DOTUSDT", "NEARUSDT"};

    for (int i = 0; i < 11; i++) // len(CRYPTO_CURRENCIES)
    {
        CURL* curl = curl_easy_init();
        CURLcode res;
        std::string readBuffer;
        if (curl) {
            // Set the URL for the API endpoint
            std::string argument = "https://api.bitget.com/api/v2/spot/market/orderbook?symbol=" + CRYPTO_CURRENCIES[i];

            char* carg = new char[argument.length() + 1];
            strcpy(carg, argument.c_str());

            std::cout << argument << std::endl;
            std::cout << curl;
            curl_easy_setopt(curl, CURLOPT_URL, carg);
            // Set the callback function to receive the response
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

            // Perform the request
            res = curl_easy_perform(curl);
            std::cout << res << std::endl;
            std::cout << readBuffer << std::endl;

            // Check for errors
            if (res != CURLE_OK) {
                std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
                curl_easy_cleanup(curl);
                //return 1;
                continue;
            }

            // Cleanup
            curl_easy_cleanup(curl);
        }
        else {
            std::cerr << "Failed to initialize CURL" << std::endl;
            return 1;
        }
    }

        //for (int i = 0; i < 11; i++)
        //{
        //    std::string argument = "https://api.binance.com/api/v3/depth?symbol=" + CRYPTO_CURRENCIES[i];
        //    std::cout << argument << std::endl;
        //    curl_easy_setopt(curl, CURLOPT_URL, argument);
        //    // Set the callback function to receive the response
        //    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        //    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        //    // Perform the request
        //    res = curl_easy_perform(curl);
        //    std::cout << res;

        //    // Check for errors
        //    if (res != CURLE_OK) {
        //        std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        //        curl_easy_cleanup(curl);
        //        return 1;
        //    }

        //    // Cleanup
        //    curl_easy_cleanup(curl);
        //}

        
    
    

    //// Parse the JSON response
    //try {
    //    json jsonData = json::parse(readBuffer);

    //    // Extract information from the JSON response
    //    std::string info = jsonData["code"].get<std::string>(); // Replace "key" with the actual key in your JSON response

    //    // Output the extracted information
    //    std::cout << "Information: " << info << std::endl;
    //}
    //catch (const std::exception& e) {
    //    std::cerr << "Error parsing JSON: " << e.what() << std::endl;
    //    return "1";
    //}
}
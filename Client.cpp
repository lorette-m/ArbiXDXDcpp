#pragma warning(disable : 4996) //для корректной работы strcpy и c_str, компилятор считает их небезопасными
#include "Client.h"

#include "Market.h"

size_t write_callback(char* ptr, size_t size, size_t nmemb, std::string* data) {
    data->append(ptr, size * nmemb);
    return size * nmemb;
}

bool Client::getResponse()
{
    

    std::vector<std::string> CRYPTO_CURRENCIES{ "GRIMACEUSDT", "BTCUSDT", "ETHUSDT", "SOLUSDT", "XRPUSDT", "LINKUSDT", "ARBUSDT", "TRXUSDT", "DOGEUSDT", "DOTUSDT", "NEARUSDT"};

    //bitget
    Market bitget;
    for (int i = 0; i < 11; i++) // len(CRYPTO_CURRENCIES)
    {
        std::string curr = CRYPTO_CURRENCIES[i];
        CURL* curl = curl_easy_init();
        CURLcode res;
        std::string readBuffer;
        if (curl) {
            // Set the URL for the API endpoint
            std::string argument = "https://api.bitget.com/api/v2/spot/market/orderbook?symbol=" + curr;

            char* carg = new char[argument.length() + 1]; // cURL сишная библиотека, она не понимает тип string, поэтому
            strcpy(carg, argument.c_str());               // используем функцию преобразования (argument) в (carg)

            //проверка переменных
            //std::cout << argument << std::endl;
            //std::cout << curl;

            curl_easy_setopt(curl, CURLOPT_URL, carg);
            // Set the callback function to receive the response
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

            // Perform the request
            res = curl_easy_perform(curl); // помним что это переменная типа CURLcode, нужна только для отладки, поиска ошибки

            //проверка переменных
            //std::cout << res << std::endl;
            //std::cout << readBuffer << std::endl;

            //const CURLE_OK = 0
            if (res == CURLE_OK)
            {
                bitget.insertPeres(curr);
                bitget.insertData(curr, readBuffer);

                //bitget.peres[i] = CRYPTO_CURRENCIES[i];
                //bitget->data[CRYPTO_CURRENCIES[i]] = readBuffer;
            }
            else //обработчик исключений
            {
                std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
                curl_easy_cleanup(curl);
                //return 1;
                continue;
            }

            // проверка переменных
            //bitget.printPeres(i+1);
            //bitget.printData(curr);
            // или
            //std::cout << bitget.getPeres(i+1) << std::endl;
            //std::cout << bitget.getData(curr) << std::endl;


            // Cleanup
            curl_easy_cleanup(curl);
        }
        else {
            std::cerr << "Failed to initialize CURL" << std::endl;
            return 1;
        }
    }

    std::cout << "Bitget ready" << std::endl;

    //binance
    Market binance;
    for (int i = 0; i < 11; i++)
    {
        std::string curr = CRYPTO_CURRENCIES[i];
        CURL* curl = curl_easy_init();
        CURLcode res;
        std::string readBuffer;
        if (curl) {
            std::string argument = "https://api.binance.com/api/v3/depth?symbol=" + curr;

            char* carg = new char[argument.length() + 1]; // cURL сишная библиотека, она не понимает тип string, поэтому
            strcpy(carg, argument.c_str());               // используем функцию преобразования (argument) в (carg)

            //проверка переменных
            //std::cout << argument << std::endl;
            //std::cout << curl;

            curl_easy_setopt(curl, CURLOPT_URL, carg);
            // Set the callback function to receive the response
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

            // Perform the request
            res = curl_easy_perform(curl); // помним что это переменная типа CURLcode, нужна только для отладки, поиска ошибки

            //проверка переменных
            //std::cout << res << std::endl;
            //std::cout << readBuffer << std::endl;

            //const CURLE_OK = 0
            if (res == CURLE_OK)
            {
                binance.insertPeres(curr);
                binance.insertData(curr, readBuffer);

                //binance.peres[i] = CRYPTO_CURRENCIES[i];
                //binance->data[CRYPTO_CURRENCIES[i]] = readBuffer;
            }
            else //обработчик исключений
            {
                std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
                curl_easy_cleanup(curl);
                //return 1;
                continue;
            }

            // проверка переменных
            //binance.printPeres(i+1);
            //binance.printData(curr);
            // или
            //std::cout << binance.getPeres(i+1) << std::endl;
            //std::cout << binance.getData(curr) << std::endl;


            // Cleanup
            curl_easy_cleanup(curl);
        }
        else {
            std::cerr << "Failed to initialize CURL" << std::endl;
            return 1;
        }
    }

    std::cout << "Binance ready" << std::endl;
    
    //huobi
    Market huobi;
    for (int i = 0; i < 11; i++)
    {
        std::string curr = CRYPTO_CURRENCIES[i];
        std::transform(curr.begin(), curr.end(), curr.begin(), tolower);

        CURL* curl = curl_easy_init();
        CURLcode res;
        std::string readBuffer;
        if (curl) {
            std::string argument = "https://api.huobi.pro/market/depth?symbol=" + curr + "&depth=20&type=step0";

            char* carg = new char[argument.length() + 1]; // cURL сишная библиотека, она не понимает тип string, поэтому
            strcpy(carg, argument.c_str());               // используем функцию преобразования (argument) в (carg)

            //проверка переменных
            std::cout << argument << std::endl;
            std::cout << curl;

            curl_easy_setopt(curl, CURLOPT_URL, carg);
            // Set the callback function to receive the response
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

            // Perform the request
            res = curl_easy_perform(curl); // помним что это переменная типа CURLcode, нужна только для отладки, поиска ошибки

            //проверка переменных
            //std::cout << res << std::endl;
            //std::cout << readBuffer << std::endl;

            //const CURLE_OK = 0
            if (res == CURLE_OK)
            {
                huobi.insertPeres(curr);
                huobi.insertData(curr, readBuffer);

                //huobi.peres[i] = CRYPTO_CURRENCIES[i];
                //huobi->data[CRYPTO_CURRENCIES[i]] = readBuffer;
            }
            else //обработчик исключений
            {
                std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
                curl_easy_cleanup(curl);
                //return 1;
                continue;
            }

            // проверка переменных
            //binance.printPeres(i+1);
            //binance.printData(curr);
            // или
            //std::cout << binance.getPeres(i+1) << std::endl;
            //std::cout << binance.getData(curr) << std::endl;


            // Cleanup
            curl_easy_cleanup(curl);
        }
        else {
            std::cerr << "Failed to initialize CURL" << std::endl;
            return 1;
        }
    }

    std::cout << "Huobi ready" << std::endl;

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
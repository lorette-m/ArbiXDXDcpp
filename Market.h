#ifndef MARKET_H
#define MARKET_H

class Market
{
public:
    Market()
    {
        peres.reserve(1);
        std::string temp = "";
        peres.push_back(temp);
        data["INIC"] = "INIC";
    }

    void insertPeres(std::string curr)
    {
        size_t size_str = curr.size();
        peres.reserve(size_str);
        peres.push_back(curr);
    }

    void insertData(std::string curr, std::string buffer)
    {
        data[curr] = buffer;
    }

    std::string getPeres(int number_key)
    {
        return peres[number_key];
    }

    std::string getData(std::string string_key)
    {
        return data[string_key];
    }

    void printPeres(int number_key)
    {
        std::cout << peres[number_key] << std::endl;
    }

    void printData(std::string string_key)
    {
        std::cout << data[string_key] << std::endl;
    }

private:
    std::vector<std::string> peres;
    std::map <std::string, std::string> data;
};

#endif
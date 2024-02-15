#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <boost/beast.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <string>
//const static std::string MAIN_API = "ip-api.com";
//const static std::string API_ARG = "/json/";

const static std::string TEST_API_SH = "https://api.bitget.com";
const static std::string TEST_API = "/api/v2/spot/market/tickers?symbol=BTCUSDT";

namespace http = boost::beast::http;

class Client
{
public:
	static std::string getResponse()
	{
		boost::asio::io_context io;
		boost::asio::ip::tcp::resolver resolver(io);
		boost::asio::ip::tcp::socket socket(io);

		boost::asio::connect(socket, resolver.resolve(TEST_API_SH, "80"));

		std::string arg = TEST_API_SH + TEST_API;

		http::request<http::string_body> req(http::verb::get, arg, 11);

		req.set(http::field::host, TEST_API_SH);
		req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

		http::write(socket, req);

		std::string response;
		{
			boost::beast::flat_buffer buffer;
			http::response<http::dynamic_body> res;
			http::read(socket, buffer, res);
			response = boost::beast::buffers_to_string(res.body().data());
		}

		socket.shutdown(boost::asio::ip::tcp::socket::shutdown_both);
		return response;
	}
};

#endif
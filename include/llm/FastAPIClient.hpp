#ifndef FASTAPICLIENT_HPP
#define FASTAPICLIENT_HPP

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/json.hpp>
#include <optional>
#include <iostream>

#include "data/JobApplication.hpp"

class FastAPIClient {
public:
  FastAPIClient(boost::asio::io_context& ioc) 
    : resolver_(ioc), stream_(ioc) {}
  auto connect() -> void;
  auto close() -> void;
  auto sendJobDescription(const std::string& jobDescription) 
    -> std::optional<JobApplication>;

private:
  inline static const std::string DEFAULT_HOST = "fastapi_ner_spacy";
  inline static const std::string DEFAULT_PORT = "8000";
  inline static const std::string DEFAULT_TARGET = "/job_description";
  inline static constexpr int DEFAULT_VERSION = 11;

  std::string host_ = DEFAULT_HOST;
  std::string port_ = DEFAULT_PORT;
  std::string target_ = DEFAULT_TARGET;
  int version_ = DEFAULT_VERSION;
  
  boost::asio::ip::tcp::resolver resolver_;
  boost::beast::tcp_stream stream_;
};

#endif // FASTAPICLIENT_HPP

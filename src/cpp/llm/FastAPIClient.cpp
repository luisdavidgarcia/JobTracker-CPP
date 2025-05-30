#include "llm/FastAPIClient.hpp"

auto FastAPIClient::connect() -> void {
  boost::system::error_code ec;
  auto const results = resolver_.resolve(host_, port_, ec);
  if (ec) {
    throw boost::beast::system_error{ec};
  }
  stream_.connect(results);
}

auto FastAPIClient::close() -> void {
  boost::beast::error_code ec;
  stream_.socket().shutdown(boost::asio::ip::tcp::socket::shutdown_both, ec);

  if (ec && ec != boost::beast::errc::not_connected)
    throw boost::beast::system_error{ec};
}

auto FastAPIClient::sendJobDescription(const std::string& jobDescription) 
  -> std::optional<JobApplication>
{
  boost::beast::http::request<boost::beast::http::string_body> req{
    boost::beast::http::verb::post, 
    target_, 
    version_
  };
  req.set(boost::beast::http::field::host, host_);
  req.set(boost::beast::http::field::user_agent, BOOST_BEAST_VERSION_STRING);
  req.set(boost::beast::http::field::content_type, "application/json");

  boost::json::object payload;
  payload["job_description"] = jobDescription;
  req.body() = boost::json::serialize(payload);
  req.prepare_payload();

  boost::beast::http::write(stream_, req);
  boost::beast::flat_buffer buffer;
  boost::beast::http::response<boost::beast::http::dynamic_body> res;
  boost::beast::http::read(stream_, buffer, res);

  if (res.result() == boost::beast::http::status::ok) {
    boost::json::value jsonResult = boost::json::parse(
      boost::beast::buffers_to_string(res.body().data())
    );
    
    return boost::json::value_to<JobApplication>(jsonResult);
  } else {
    std::cerr << "Failed to send or recieve response: " << res.result_int()
      << " (" << res.reason() << ")\n";
  }

  return std::nullopt;
}

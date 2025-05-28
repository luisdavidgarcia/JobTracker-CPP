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


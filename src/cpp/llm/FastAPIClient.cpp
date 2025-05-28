#include "llm/FastAPIClient.hpp"

auto FastAPIClient::connect() -> void {
  boost::system::error_code ec;
  auto const results = resolver_.resolve(host_, port_, ec);
  if (ec) {
    throw boost::beast::system_error{ec};
  }
  stream_.connect(results);
}


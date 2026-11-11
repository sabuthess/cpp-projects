#include <curlpp/Easy.hpp>
#include <curlpp/Exception.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/cURLpp.hpp>

#include <iostream>
#include <sstream>
#include <string>

using namespace curlpp::options;

int main() {
  std::string username;

  std::cout << "Enter username:\n";

  std::cin >> username;

  try {

    curlpp::Easy myRequest;

    std::string urlWithUsername =
        "https://api.github.com/users/" + username + "/received_events";

    myRequest.setOpt<curlpp::options::Url>(urlWithUsername);

    // this is requiered for the api of GitHub
    myRequest.setOpt<curlpp::options::UserAgent>(
        "Mozilla/5.0 (Windows NT 10.0; Win64; x64) ");

    myRequest.perform();

  } catch (curlpp::RuntimeError &e) {
    std::cout << e.what() << std::endl;
  } catch (curlpp::LogicError &e) {
    std::cout << e.what() << std::endl;
  }

  std::ostringstream os;
  return 0;
}

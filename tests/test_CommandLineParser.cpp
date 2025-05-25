#define BOOST_TEST_MODULE JobTrackerTests
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "cli/CommandLineParser.hpp"
#include <iostream>

BOOST_AUTO_TEST_SUITE(CommandLineParserTests)

BOOST_AUTO_TEST_CASE(parse_model_name_success) {
  CommandLineParser parser;

  const char* argv[] = {"program", "--model", "llama3.2"};
  int argc = sizeof(argv) / sizeof(argv[0]);

  parser.parseModelName(argc, argv);

  BOOST_CHECK_EQUAL(parser.getModelName(), "llama3.2");
}

BOOST_AUTO_TEST_CASE(parse_model_missing_model_args) {
  CommandLineParser parser;

  const char* argv[] = {"program", "--model"};
  int argc = sizeof(argv) / sizeof(argv[0]);
  std::cout << argc << std::endl;
  
  BOOST_CHECK_THROW(parser.parseModelName(argc, argv), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(parse_incomptabile_model) {
  CommandLineParser parser;
  
  const char* argv [] = {"program", "--model", "xyz"};
  int argc = sizeof(argv) / sizeof(argv[0]);

  BOOST_CHECK_THROW(parser.parseModelName(argc, argv), std::runtime_error);
}

BOOST_AUTO_TEST_SUITE_END()


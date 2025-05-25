#ifndef OLLAMAPICLIENT_HPP
#define OLLAMAPICLIENT_HPP

static constexper int DEFAULT_PORT_NUMBER = 11434;

class OllamaAPIClient {
public:
  OllamaAPIClient(JobApplication& jobApp, PostgresDatabaseManager& db)
    : jobApplication_(jobApp), databaseManager_(db) {}

  void processJobDescription();

private:
  int portNumber_ = DEFAULT_PORT_NUMBER;
  JobApplication& jobApplication_;
  PostgresDatabaseManager& databaseManager_;

  void storeJobApplication();
};

#endif // OLLAMAPICLIENT_HPP

#ifndef OLLAMAPICLIENT_HPP
#define OLLAMAPICLIENT_HPP

static constexper int DEFAULT_PORT_NUMBER = 11434;

class OllamaAPIClient {
public:
  OllamaAPIClient(PostgresDatabaseManager& db, JobApplication& jobApp)
    : databaseManager_(db), jobApplication_(jobApp) {}

  void processJobDescription();

private:
  int portNumber_ = DEFAULT_PORT_NUMBER;
  PostgresDatabaseManager& databaseManager_;
  JobApplication& jobApplication_;

  void storeJobApplication();
};

#endif // OLLAMAPICLIENT_HPP

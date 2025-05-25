#ifndef JOBAPPLICATION_HPP
#define JOBAPPLICATION_HPP

static constexpr int DEFAULT_PORT_NUMBER = 5432;

class PostgresDatabaseManager {
public:
  PostgresDatabaseManager(JobApplication& jobApp)
    : jobApplication_(jobApp) {}

  void sumbitQuery();

private:
  int portNumber_ = DEFAULT_PORT_NUMBER;
  JobApplication& jobApplication_;

  void craftQuery();
};

#endif // JOBAPPLICATION_HPP

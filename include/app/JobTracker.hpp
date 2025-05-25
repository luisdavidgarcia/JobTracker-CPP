#ifndef JOBTRACKER_HPP
#define JOBTRACKER_HPP

#include <iostream>

#include "llm/FastAPIClient.hpp"
#include "db/PostgresDatabaseManager.hpp"

class JobTracker {
public:
  JobTracker() : fastAPI_(), databaseManager_() {}
  void run();

private:
  FastAPIClient fastAPI_;
  PostgresDatabaseManager databaseManager_;
};

#endif // JOBTRACKER_HPP

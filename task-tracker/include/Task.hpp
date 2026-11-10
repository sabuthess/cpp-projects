#pragma once

#include <string>

enum Status { DONE, NOT_DONE, PROGRESS };

struct Task {
  int id;
  std::string content;
  Status status;
};

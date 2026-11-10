#include <algorithm>
#include <ios>
#include <iostream>
#include <limits>
#include <string>
#include <tuple>
#include <vector>

#include "../include/Task.hpp"

std::vector<Task> tasks;
int taskId = 0;

int main() {

  int opc;
  std::string userContent;
  int userTaskId;

  do {

    std::cout << "-----------------task tracker-----------------\n";
    std::cout << "1) add new task\n";
    std::cout << "2) update task\n";
    std::cout << "3) delete task\n";
    std::cout << "4) options list\n";
    std::cout << "0) exit\n";

    std::cin >> opc;

    switch (opc) {
    case 1: {
      std::cout << "Enter the content here!\n";

      std::cin.ignore();
      std::getline(std::cin, userContent);

      Task task = Task{
          .id = taskId, .content = userContent, .status = Status::NOT_DONE};

      tasks.push_back(task);

      std::cout << "Task created succesfully\n";

      taskId++;

      break;
    }
    case 2: {
      std::cout << "Enter the task id!\n";
      std::cin >> userTaskId;

      std::string newContent;
      auto it = std::find_if(
          tasks.begin(), tasks.end(),
          [userTaskId](const Task &task) { return task.id == userTaskId; });

      std::cout << "Enter the new content here!\n";
      std::cin.ignore();
      std::getline(std::cin, newContent);

      it->content = newContent;

      std::cout << "Task updated succesfully\n";

      break;
    }
    case 3: {

      std::cout << "Enter the task id!\n";
      std::cin >> userTaskId;
      auto it = std::find_if(
          tasks.begin(), tasks.end(),
          [userTaskId](const Task &task) { return task.id == userTaskId; });

      tasks.erase(tasks.begin(), it);

      break;
    }
    case 4: {

      for (int i = 0; i < tasks.size(); i++) {

        std::cout << tasks[i].id << " | " << tasks[i].content << std::endl;
      }

      break;
    }
    defult:
      std::cout << "Ese no es un dia de la semana\n";
      break;
    }

  } while (opc != 0);

  return 0;
}

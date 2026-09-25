#include <iostream>
#include <ostream>
#include <string>
#include <vector>

struct Contact {
  int id;
  std::string name;
  std::string email;
  std::string phone;
};

class ContactList {
public:
  std::vector<Contact> contacts;

  void add(std::string name, std::string email, std::string phone) {
    int lenth = contacts.size();
    int id = lenth + 1;

    Contact contact = {id, name, email, phone};

    contacts.push_back(contact);
  };

  void list() {
    std::cout << "|" << " ID " << "|" << " NAME " << "|" << " EMAIL " << "|"
              << " PHONE " << std::endl;
    for (const Contact &contact : contacts) {
      std::cout << "| " << contact.id;
      std::cout << " | " << contact.name;
      std::cout << " | " << contact.email;
      std::cout << " | " << contact.phone << std::endl;
    };
  };

  void update(int id) {
    int opc;
    std::string val;

    for (Contact &contact : contacts) {
      if (contact.id == id) {

        do {
          std::cout << "What do you want to change?\n";
          std::cout << "1. Name\n";
          std::cout << "2. Email\n";
          std::cout << "3. Phone\n";
          std::cout << "0. Exit\n";
          std::cin >> opc;

          switch (opc) {
          case 1:
            std::cout << "Enter the name: ";
            std::cin >> val;
            contact.name = val;
            break;

          case 2:
            std::cout << "Enter the email: ";
            std::cin >> val;
            contact.email = val;
            break;

          case 3:
            std::cout << "Enter the phone: ";
            std::cin >> val;
            contact.phone = val;
            break;

          case 0:
            break;

          default:
            std::cout << "Invalid option\n";
          }

        } while (opc != 0);

        return;
      }
    }

    std::cout << "Contact not found\n";
  }
  void deleteContact(int id) {
    for (size_t i = 0; i < contacts.size(); i++) {
      if (contacts[i].id == id) {
        contacts.erase(contacts.begin() + i);
        return;
      }
    }

    std::cout << "Contact not found\n";
  };
};

int main() {
  int opc;
  std::string name, email, phone;
  int id;

  ContactList contact;

  do {

    std::cout << "---contact list---" << std::endl;
    std::cout << "1. Add a new contact" << std::endl;
    std::cout << "2. View all contacts" << std::endl;
    std::cout << "3. Update a contact" << std::endl;
    std::cout << "4. Delete a contact" << std::endl;
    std::cout << "0. Exit" << std::endl;

    std::cin >> opc;

    switch (opc) {
    case 1:
      std::cout << "Enter your name" << std::endl;
      std::cin >> name;

      std::cout << "Enter your email" << std::endl;
      std::cin >> email;

      std::cout << "Enter your phone" << std::endl;
      std::cin >> phone;

      contact.add(name, email, phone);
      std::cout << "Contact saved" << std::endl;

      break;

    case 2:
      contact.list();
      std::cout << "Contact saved" << std::endl;

      break;

    case 3:

      std::cout << "Enter contact id " << std::endl;
      std::cin >> id;

      contact.update(id);
      std::cout << "Contact updated" << std::endl;

      break;

    case 4:
      std::cout << "Enter contact id " << std::endl;
      std::cin >> id;

      contact.deleteContact(id);
      std::cout << "Contact updated" << std::endl;

      break;
    default:
      std::cout << "This isn't a option";
      break;
    }
  } while (opc != 0);

  return 0;
}

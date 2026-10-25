#include "../include/Contact.hpp"
#include <string>
#include <vector>

class I_ContactsManager {
public:
  virtual ~I_ContactsManager() = default;

  virtual std::vector<Contact *> getContacts(const std::string &pref) = 0;
  virtual void addContact(Contact *c) = 0;
};
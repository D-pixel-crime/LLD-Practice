#include "../interface/I_ContactsManager.hpp"
#include "Contact.hpp"
#include <string>
#include <unordered_map>
#include <vector>

class TrieContactsManager : I_ContactsManager {
private:
  struct Node {
    std::unordered_map<char, Node> nxt;
    // assuming duplication
    std::vector<Contact *> contacts;

    Node() = default;
  };

  Node firstName, lastName, phone;

  void addToTree(const std::string &s, Contact *c, Node &root) {
    Node *curr = &root;

    for (auto &ch : s) {
      curr->contacts.emplace_back(c);
      if (!curr->nxt.count(ch)) {
        curr->nxt[ch] = Node();
      }
      curr = &curr->nxt[ch];
    }

    curr->contacts.emplace_back(c);
  }

  std::vector<Contact *> _getContacts(const std::string &s, Node &root) {
    Node *curr = &root;

    for (auto &ch : s) {
      if (!curr->nxt.count(ch)) {
        return {};
      }
      curr = &curr->nxt[ch];
    }

    return curr->contacts;
  }

public:
  TrieContactsManager() {
    firstName = Node();
    lastName = Node();
    phone = Node();
  }

  ~TrieContactsManager() = default;

  std::vector<Contact *> getContacts(const std::string &pref);
  void addContact(Contact *c);
};
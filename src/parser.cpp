#include "parser.hpp"
#include <cstdint>
#include <iostream>

using namespace std;

enum Action { idle, search, assign, insert, merge, extend };

Action decode_node(size_t name, size_t node, size_t n_match) {
  if (name == node && n_match == name) {
    return Action::assign;
  }

  if (n_match == node && name > node) {
    return Action::search;
  }

  if (n_match == name && name < node) {
    return Action::insert;
  }

  if (n_match != 0) {
    return Action::merge;
  }
  return Action::idle;
}

size_t n_match(string query, string key) {
  size_t search_size = min(query.size(), key.size());
  for (size_t n = 0; n < search_size; n++) {
    if (query[n] != key[n]) {
      return n;
    }
  }
  return search_size;
}

Parser::Parser() : root{} {}
Parser::Parser(string name, int value) : root{{name, value, {}}} {}

void Parser::add(string name, int value) {
  vector<Node> *selected_root = &root;

search:
  for (Node &nd : *selected_root) {
    size_t n_same = n_match(name, nd.key);
    Action action = decode_node(name.size(), nd.key.size(), n_same);

    if (action == Action::search) {
      name = name.substr(n_same);
      selected_root = &nd.next;

      goto search;
    }

    if (action == Action::insert) {
      nd.key = nd.key.substr(n_same);
      Node new_nd{name, value, {nd}};
      swap(nd, new_nd);


      return;
    }

    if (action == Action::merge) {
      nd.key = nd.key.substr(n_same);
      Node new_branch = Node{name.substr(n_same), value};
      Node new_root{name.substr(0, n_same), -1, vector<Node>{nd, new_branch}};
      swap(new_root, nd);

      return;
    }

    if (action == Action::assign) {
      nd.key = name;

      return;
    }
  }
  // extend node
  selected_root->push_back({name, value, {}});

}

int Parser::parse(string name) {
  vector<Node> &selected_root = root;
search:
  for (Node &nd : selected_root) {
    size_t n_same = n_match(name, nd.key);
    if (n_same == name.size()) {
      return nd.value;
    }
    if (n_same == nd.key.size()) {
      name = name.substr(n_same);
      selected_root = nd.next;
      goto search;
    }
  }
  return -1;
}

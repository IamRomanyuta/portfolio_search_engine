#ifndef SEARCH_ENGINE_INCLUDE_SEARCHSERVER_H_
#define SEARCH_ENGINE_INCLUDE_SEARCHSERVER_H_

#include <vector>
#include <string>
#include "InvertedIndex.h"
#include "RelativeIndex.h"

class SearchServer {
 public:

  explicit SearchServer(InvertedIndex& idx) : _index(idx){ };

  std::vector<std::vector<RelativeIndex>> search(
      const std::vector<std::string>& queries_input,
      size_t ResponsesLimit = 5);
 private:
  InvertedIndex _index;
};

#endif //SEARCH_ENGINE_INCLUDE_SEARCHSERVER_H_

#ifndef SEARCH_ENGINE_INCLUDE_INVERTEDINDEX_H_
#define SEARCH_ENGINE_INCLUDE_INVERTEDINDEX_H_

#include <unordered_map>

struct Entry {
  size_t doc_id, count;
// This operator is required for test scenarios
  bool operator ==(const Entry& other) const {
    return (doc_id == other.doc_id &&
        count == other.count);
  }
};

class InvertedIndex {
 public:
  InvertedIndex() = default;

  void UpdateDocumentBase(const std::vector<std::string>& input_docs);

  std::vector<Entry> GetWordCount(const std::string& word);
 private:
  std::vector<std::string> mDocs;
  std::unordered_map<std::string, std::vector<Entry>> freq_dictionary;

  auto findEntryInDictionary(const std::string& word, size_t doc_id);
};

#endif //SEARCH_ENGINE_INCLUDE_INVERTEDINDEX_H_

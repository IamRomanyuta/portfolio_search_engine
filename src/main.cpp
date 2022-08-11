#include <iostream>
//
#include "ConverterJSON.h"
#include "InvertedIndex.h"
#include "SearchServer.h"

int main() {

  try {
    ConverterJSON converter_json("../config.json", "../requests.json", "../answers.json");

    InvertedIndex inverted_index;


    inverted_index.UpdateDocumentBase(converter_json.GetTextDocuments());

    SearchServer search_server(inverted_index);


    converter_json.putAnswers(
        search_server.search(
          converter_json.GetRequests(),
          converter_json.GetResponseLimit()
          )
        );

  } catch (std::invalid_argument &x) { // Exception Handling
    std::cout << x.what() << std::endl;
  }

  return 0;
}

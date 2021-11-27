#include <iostream>
#include "HTMLWriter.h"
using namespace std;

void showFileContent(const DocWriter& doc) {
	doc.readFile();
}

int main() {
	DocWriter doc1("doctest.txt", "hanjyoon");
	HTMLWriter html1("htmltest.html", "konkuk");

	//doc1 = html1;
	//doc1.write();

	//DocWriter* doc2 = &html1;
	//DocWriter& doc3 = html1;

	//doc1.write();
	//html1.write();

	//doc1.readFile();
	//html1.readFile();

	showFileContent(doc1);
	showFileContent(html1); //DocWriter doc = html1;
}
#include <iostream>
#include "HTMLWriter.h"
using namespace std;

int main() {

	//DocWriter doc1;
	//doc1.setFileName("text1.txt");
	//doc1.setContent("greenjoa!");
	//doc1.write();

	//DocWriter doc2("text2.txt","bluejoa!");
	//doc2.write();

	//HTMLWriter html1("index.html", "hanjyoon");
	//html1.setFont("蹈框眉", 20, "blue");
	//html1.write();

	//DocWriter doc1("test.txt", "hanjyoon");
	//doc1 << "户" << 2 << "目乔" << 1;
	//doc1.write();

	HTMLWriter html1("test.html", "hanjyoon");
	html1 << "户" << 2 << "目乔" << 1;
	html1.write();
}
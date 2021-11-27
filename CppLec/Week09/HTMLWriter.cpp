#include "HTMLWriter.h"
#include <iostream>
#include <fstream>
using namespace std;
HTMLWriter::HTMLWriter()
	:HTMLWriter("noFileName.html", "noContent") {
}

HTMLWriter::~HTMLWriter(){
	cout << "HTMLWriter º“∏Í¿⁄" << endl;
}

//HTMLWriter::HTMLWriter(const string& fileName, const string& content)
//	:DocWriter(fileName, content) {
//	cout << "HTMLWriter ª˝º∫¿⁄" << endl;
//}


void HTMLWriter::setFont(const string& fontName, int fontSize, const string& fontColor){
	this->fontName = fontName;
	this->fontSize = fontSize;
	this->fontColor = fontColor; 
}

void HTMLWriter::write(){
	ofstream fout(fileName);
	fout << "<html><head><title>hanjyoon</title></head>" << endl;
	fout << "<body>" << endl;
	fout << "<H1>### 2020211390 «—¿Á¿± ###</H1>" << endl;
	fout << "<font face='" << fontName << "' size='" << fontSize;
	fout << "' color='" << fontColor << "'>" << content << "</font>" << endl;
	fout << "</body></html>" << endl;
}

HTMLWriter& HTMLWriter::operator<<(const string& str)
{
	content += "<br>" + str + "<br>";
	return *this;
}

HTMLWriter& HTMLWriter::operator<<(const int& num)
{
	content += to_string(num) + "<br>";
	return *this;
}
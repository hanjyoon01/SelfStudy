#pragma once
#include "DocWriter.h"
#include <string>
using std::string;

class HTMLWriter : public DocWriter
{
protected:
	string fontName = "µ¸¿ò";
	int fontSize = 15;
	string fontColor = "blue";
public:
	HTMLWriter();
	~HTMLWriter();
	using DocWriter::DocWriter;
	//HTMLWriter(const string& fileName, const string& content);

	void setFont(const string& fontName, int fontSize, const string& fontColor);
	void write();

	HTMLWriter& operator<<(const string& str);
	HTMLWriter& operator<<(const int& num);
};


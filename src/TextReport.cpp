// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <TextReport.h>
#include <iostream>
#include <sstream>
#include <Report.h>
#include <Result.h>
#include <Test.h>

using namespace std;
using namespace oout;

// @todo #57:15min TextReportStream is a bad name
class TextReportStream final : public Report {
public:
	TextReportStream()
		: text()
	{
	}

	void prolog()
	{
		// @todo #57:15min Test counts show in preample
		text << "[==========] Running" << endl;
	}

	void begin(const string &tag, const map<string, string> &attributes) override
	{
		if (tag == "testcase") {
			text << "[ RUN      ] " << attributes.at("name") << endl;
			if (attributes.at("failures") == "0") {
				text << "[       OK ] ";
			} else {
				text << "[  FAILED  ] ";
			}
			text << attributes.at("name") << endl;
		} else {
			// @todo #53:15min gtest text format for "cases"
			text << tag << ": ";
			for (const auto &ap : attributes) {
				text << ap.first << "='" << ap.second << "' ";
			}
			text << endl;
		}
	}
	void end(const string &) override
	{
	}

	void epilog()
	{
		// @todo #65:15min Count of tests
		text << "[==========] tests run" << endl;
		// @todo #65:15min status of test run
	}

	string asString() const
	{
		return text.str();
	}

private:
	ostringstream text;
};

TextReport::TextReport(const std::shared_ptr<const Result> &result)
	: result(result)
{
}

// @todo #65:15min Need to Introduce TextReportFormat as Visitor
//  who help to transform report to string.
//  (TextReportFormat has other method for different report type)
//  Some technique used for test counting and failure counting.
string TextReport::asString() const
{
	TextReportStream rep;
	rep.prolog();
	result->print(&rep);
	rep.epilog();
	return rep.asString();
}

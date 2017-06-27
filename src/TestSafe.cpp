// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <TestSafe.h>
#include <Error.h>
#include <ResSimple.h>

using namespace std;
using namespace oout;

TestSafe::TestSafe(const shared_ptr<const Test> &test)
	: test(test)
{
}

shared_ptr<const Result> TestSafe::result() const
{
	shared_ptr<const Result> r;
	try {
		r = test->result();
	} catch (const exception &e) {
		// @todo #158:15min We don't know autogenerated test name in this point.
		//  We loose this info. TestNamed need use on upper level.
		//  Decorated test can wrap name in exception... Hm... Need think about it.
		//  In other side decorated test cannot generate name, if except.
		r = make_shared<const ResSimple>("Test error", make_shared<Error>());
	}
	return r;
}
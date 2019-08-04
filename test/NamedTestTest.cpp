// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "NamedTestTest.h"
#include <2out/2out.h>
#include "ReprTest.h"

using namespace std;
using namespace oout;

class ReprNamedTest final : public Representation {
public:
	explicit ReprNamedTest(const shared_ptr<const Test> &test)
		: test(test)
	{
	}

	string asString() const override
	{
		return JUnitXmlReport(test->result()).asString();
	}
private:
	const shared_ptr<const Test> test;
};

NamedTestTest::NamedTestTest()
	: tests(
		make_unique<NamedTest>(
			"NamedTestTest",
			make_shared<const NamedTest>(
				"NamedTest in TestNamed is a Suite",
				make_shared<ContainTest>(
					make_shared<ReprNamedTest>(
						make_unique<NamedTest>(
							"Root test",
							make_shared<const NamedTest>(
								"Concrete test",
								make_shared<EqualTest>("a", "a")
							)
						)
					),
					"Concrete test"
				)
			)
		)
	)
{
}

unique_ptr<const Result> NamedTestTest::result() const
{
	return tests->result();
}
// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <iostream>
#include <2out/2out.h>
#include "MoneyText.h"
#include "RealMoney.h"
#include "TimesMoney.h"

using namespace std;
using namespace oout;

int main(int, char **)
{
	const SuiteTest tests{
		make_shared<EqualTest>(
			make_shared<MoneyText>(
				make_shared<RealMoney>(5, "USD")
			),
			"5 USD"
		),
		make_shared<NamedTest>(
			"$5 * 2 = $10",
			make_shared<EqualTest>(
				make_shared<MoneyText>(
					make_shared<TimesMoney>(
						make_shared<RealMoney>(5, "USD"),
						2
					)
				),
				"10 USD"
			)
		)
	};
	const shared_ptr<const Result> result = tests.result();

	cout << TextReportText(result).asString() << endl;

	return (
		CountFailure(result).count() == 0 &&
		CountError(result).count() == 0
	) ? 0 : -1;
}

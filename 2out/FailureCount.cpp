// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <FailureCount.h>
#include <numeric>
#include <AssertionResult.h>
#include <Format.h>
#include <ResSuite.h>
#include <Result.h>

using namespace std;
using namespace oout;

class FmtFailure final : public Format {
public:
	string success(const string &) const override
	{
		return {};
	}

	string failure(const string &) const override
	{
		return "F";
	}

	string error(const string &) const override
	{
		return {};
	}

	string test(
		const string &,
		const shared_ptr<const AssertionResult> &assertion_result,
		float
	) const override
	{
		return assertion_result->print(*this);
	}

	string suite(
		const string &,
		float,
		const list<shared_ptr<const Result>> &results
	) const override
	{
		return accumulate(
			results.begin(),
			results.end(),
			string{},
			[this](const string &v, const auto &r){
				return v + r->print(*this);
			}
		);
	}
};

FailureCount::FailureCount(const list<shared_ptr<const Result>> &results)
	: FailureCount(make_unique<ResSuite>(results))
{
}

FailureCount::FailureCount(const shared_ptr<const Result> &result)
	: result(result)
{
}

size_t FailureCount::count() const
{
	return result->print(FmtFailure()).size();
}
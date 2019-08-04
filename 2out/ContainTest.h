// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Representation.h"
#include <list>
#include "ReprString.h"
#include "Test.h"

namespace oout {

/// Test for substring present in string
class ContainTest final : public Test {
private:
	/// Primary ctor
	ContainTest(
		const std::shared_ptr<const Representation> &text,
		const std::list<std::shared_ptr<const Representation>> &subs
	);

public:
	// Multiple ctor with reprs
	template<typename ... S>
	ContainTest(
		const std::shared_ptr<const Representation> &text,
		const std::shared_ptr<const Representation> &sub,
		S ... subs
	) : ContainTest(text, std::list<std::shared_ptr<const Representation>>{sub, subs...})
	{
	}

	// Multiple ctor with strings
	template<typename ... S>
	ContainTest(
		const std::shared_ptr<const Representation> &text,
		const std::string &sub,
		S ... subs
	) : ContainTest(text, subs..., std::make_shared<ReprString>(sub))
	{
	}

	/// Secondary ctor from strings
	template<typename ... S>
	ContainTest(
		const std::string &text,
		S ... subs
	) : ContainTest(std::make_shared<ReprString>(text), subs...)
	{
	}

	/// Test result
	std::unique_ptr<const Result> result() const override;

private:
	const std::shared_ptr<const Representation> text;
	const std::list<std::shared_ptr<const Representation>> subs;

	std::unique_ptr<const Result> result(
		const std::shared_ptr<const Representation> &sub
	) const;
};

}
// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "SuccessResult.h"
#include "Format.h"

using namespace std;
using namespace oout;

SuccessResult::SuccessResult(const string &text)
	: text(text)
{
}

string SuccessResult::print(const Format &format) const
{
	return format.success(text);
}

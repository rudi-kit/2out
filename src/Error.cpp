// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <Error.h>

using namespace std;
using namespace oout;

Error::Error(const string &)
{
}

string Error::print(const Format &) const
{
	// @todo #109:15min Invoke Format From Error::print
	return {};
}

Error::operator bool() const
{
	return false;
}
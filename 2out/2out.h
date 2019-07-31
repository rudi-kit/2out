// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once

// Core
#include "Result.h"

// Report formatters
#include "TextReport.h"
#include "JUnitXmlReport.h"

// Result statistics
#include "CountError.h"
#include "CountFailure.h"
#include "CountTest.h"

// Representation
#include "Representation.h"
#include "ReprCallable.h"
#include "ReprPrintable.h"
#include "ReprSigned.h"
#include "ReprString.h"

// Tests
#include "EqualTest.h"
#include "SuiteTest.h"
#include "TestContainText.h"
#include "TestEndsWith.h"
#include "TestNamed.h"
#include "TestSafe.h"
#include "TestSkipped.h"
#include "TestStartsWith.h"
#include "TestTimed.h"

// Deprecated names (since 0.6)
#include "TestEqual.h"
#include "TestSuite.h"

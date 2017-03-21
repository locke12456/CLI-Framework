/* 
 * File name : 
 * Author    : Locke Chen
 * E-Mail    : locke12456@gmail.com
 * Language  : C plus plus 
 */
#ifndef __SETUP_TEARDOWN__
#define __SETUP_TEARDOWN__
#include "gtest/gtest.h"
using namespace testing;
typedef bool AssertValue;
class SetupTeardown :
	public testing::Test
{
public:
	virtual void SetUp(void)
	{
	};
	virtual void TearDown(void)
	{
	};

protected:
};
#endif // !__SETUP_TEARDOWN__

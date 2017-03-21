/* 
 * File name : Utilities
 * Author    : Locke Chen
 * E-Mail    : locke12456@gmail.com
 * Language  : C plus plus 
 */
#include "gtest/gtest.h"
#include "Utilities.hpp"
#include "setup.h"
using namespace CLI;
/*                                                                                                                
 *  Utilities                                                                                                           
 */                 
class interface_for_test {
public:
	virtual ~interface_for_test() {}
	virtual bool command() = 0;
};
class command_for_test : public interface_for_test {
public:
	command_for_test() {}
	virtual bool command() { return true; }
};
class other_command_for_test : public interface_for_test {
public:
	other_command_for_test() {}
	virtual bool command() { return false; }
};
class T_Utilities :                                                                                                     
     public SetupTeardown, public testing::WithParamInterface<AssertValue>
{                                                                                                                 
public:                                                                                                           
	T_Utilities() {};
                                                                                                                  
    testing::AssertionResult AssertUtilities(const char* Value_exp, AssertValue Value);  
};    

AssertionResult T_Utilities::AssertUtilities(const char* Value_exp, AssertValue Value)   
{
     Message msg( " NOT IMPL " );
     AssertValue result = command_for_test().command();
    // CLI::Utilities* test = new CLI::Utilities();
     return (result == Value) ? AssertionSuccess() : AssertionFailure(msg);
}
TEST_F(T_Utilities,Utilities_Case_1)
{
     AssertValue Value;
	 CLI::Utilities::CommandFactory<interface_for_test, command_for_test> factory;
	 auto cmd = factory.Create();
	 Value = cmd()->command();
     EXPECT_PRED_FORMAT1(AssertUtilities, Value);
}

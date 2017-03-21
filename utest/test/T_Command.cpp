/* 
 * File name : Command
 * Author    : Locke Chen
 * E-Mail    : locke12456@gmail.com
 * Language  : C plus plus 
 */
#include "gtest/gtest.h"
#include "Command.h"
#include ".h"
using namespace CLI;
/*                                                                                                                
 *  Command                                                                                                           
 */                                                                                                               
class T_Command :                                                                                                     
     public  , public testing::WithParamInterface<AssertValue>                                                 
{                                                                                                                 
public:                                                                                                           
    T_Command();                                                                                                      
                                                                                                                  
    testing::AssertionResult AssertCommand(const char* Value_exp, AssertValue Value);  
};                                                                                                                
AssertionResult T_Command::AssertCommand(const char* Value_exp, AssertValue Value)   
{
     Message msg( " NOT IMPL " );
     AssertValue result;
     CLI::Command* test = new CLI::Command();
     return (result == Value) ? AssertionSuccess() : AssertionFailure(msg);
}
TEST_F(T_Command,Command_Case_1)
{
     AssertValue Value;
     EXPECT_PRED_FORMAT1(AssertCommand, Value);
}

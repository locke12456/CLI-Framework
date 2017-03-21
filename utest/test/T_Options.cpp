/* 
 * File name : Options
 * Author    : Locke Chen
 * E-Mail    : locke12456@gmail.com
 * Language  : C plus plus 
 */
#include "gtest/gtest.h"
#include "Options.h"
#include ".h"
using namespace CLI;
/*                                                                                                                
 *  Options                                                                                                           
 */                                                                                                               
class T_Options :                                                                                                     
     public  , public testing::WithParamInterface<AssertValue>                                                 
{                                                                                                                 
public:                                                                                                           
    T_Options();                                                                                                      
                                                                                                                  
    testing::AssertionResult AssertOptions(const char* Value_exp, AssertValue Value);  
};                                                                                                                
AssertionResult T_Options::AssertOptions(const char* Value_exp, AssertValue Value)   
{
     Message msg( " NOT IMPL " );
     AssertValue result;
     CLI::Options* test = new CLI::Options();
     return (result == Value) ? AssertionSuccess() : AssertionFailure(msg);
}
TEST_F(T_Options,Options_Case_1)
{
     AssertValue Value;
     EXPECT_PRED_FORMAT1(AssertOptions, Value);
}

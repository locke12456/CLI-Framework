/* 
 * File name : CommandAdaptor
 * Author    : Locke Chen
 * E-Mail    : locke12456@gmail.com
 * Language  : C plus plus 
 */
#include "gtest/gtest.h"
#include "CommandAdaptor.h"
#include ".h"
using namespace CLI;
/*                                                                                                                
 *  CommandAdaptor                                                                                                           
 */                                                                                                               
class T_CommandAdaptor :                                                                                                     
     public  , public testing::WithParamInterface<AssertValue>                                                 
{                                                                                                                 
public:                                                                                                           
    T_CommandAdaptor();                                                                                                      
                                                                                                                  
    testing::AssertionResult AssertCommandAdaptor(const char* Value_exp, AssertValue Value);  
};                                                                                                                
AssertionResult T_CommandAdaptor::AssertCommandAdaptor(const char* Value_exp, AssertValue Value)   
{
     Message msg( " NOT IMPL " );
     AssertValue result;
     CLI::CommandAdaptor* test = new CLI::CommandAdaptor();
     return (result == Value) ? AssertionSuccess() : AssertionFailure(msg);
}
TEST_F(T_CommandAdaptor,CommandAdaptor_Case_1)
{
     AssertValue Value;
     EXPECT_PRED_FORMAT1(AssertCommandAdaptor, Value);
}

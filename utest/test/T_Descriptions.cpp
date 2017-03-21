/* 
 * File name : Descriptions
 * Author    : Locke Chen
 * E-Mail    : locke12456@gmail.com
 * Language  : C plus plus 
 */
#include "gtest/gtest.h"
#include "Descriptions.h"
#include ".h"
using namespace CLI;
/*                                                                                                                
 *  Descriptions                                                                                                           
 */                                                                                                               
class T_Descriptions :                                                                                                     
     public  , public testing::WithParamInterface<AssertValue>                                                 
{                                                                                                                 
public:                                                                                                           
    T_Descriptions();                                                                                                      
                                                                                                                  
    testing::AssertionResult AssertDescriptions(const char* Value_exp, AssertValue Value);  
};                                                                                                                
AssertionResult T_Descriptions::AssertDescriptions(const char* Value_exp, AssertValue Value)   
{
     Message msg( " NOT IMPL " );
     AssertValue result;
     CLI::Descriptions* test = new CLI::Descriptions();
     return (result == Value) ? AssertionSuccess() : AssertionFailure(msg);
}
TEST_F(T_Descriptions,Descriptions_Case_1)
{
     AssertValue Value;
     EXPECT_PRED_FORMAT1(AssertDescriptions, Value);
}

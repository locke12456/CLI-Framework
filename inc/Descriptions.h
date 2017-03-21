/* 
 * File name : Descriptions
 * Author    : Locke Chen
 * E-Mail    : locke12456@gmail.com
 * Language  : C plus plus 
 */
#ifndef __DESCRIPTIONS_H__
#define __DESCRIPTIONS_H__

#include "boost/program_options.hpp"
namespace CLI {
	class Descriptions 
	{
	public:
		typedef boost::program_options::options_description Description;
		Descriptions();
		virtual ~Descriptions();
		//Descriptions::Description & Description();
	private:
		Descriptions::Description description;
	};
};
#endif

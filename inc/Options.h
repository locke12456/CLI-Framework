/* 
 * File name : Options
 * Author    : Locke Chen
 * E-Mail    : locke12456@gmail.com
 * Language  : C plus plus 
 */
#ifndef __OPTIONS_H__
#define __OPTIONS_H__
#include "boost/program_options.hpp"
namespace CLI {
	class Options 
	{
	public:
		Options();
		virtual ~Options();
		bool Setup(int argc, char **argv);
	private:
		typedef boost::program_options::variables_map Variables;
		Variables variables;
	};
};
#endif

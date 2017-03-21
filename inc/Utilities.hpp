/* 
 * File name : Utilities
 * Author    : Locke Chen
 * E-Mail    : locke12456@gmail.com
 * Language  : C plus plus 
 */
#ifndef __UTILITIES_H__
#define __UTILITIES_H__
#include <map>
#include <unordered_map>
#include <memory>
#include <functional>
#include <typeinfo>
#include <typeindex>
#include <boost/shared_ptr.hpp>
#include <boost/function.hpp>
#include <boost/lambda/bind.hpp> // !
#include <boost/lambda/construct.hpp>
namespace CLI {
	namespace Utilities {

		template<typename Interface, typename Type >
		class CommandFactory
		{
		public:
			typedef boost::shared_ptr< Interface > ComandPtr;
			typedef boost::function < ComandPtr() > Command;
			CommandFactory() {};
			~CommandFactory() {};
			Command Create() {
				namespace la = boost::lambda;
				return la::bind(
					la::constructor<ComandPtr>(),
					la::bind(la::new_ptr<Type>()));
			};
		};

		template<typename Interface, class Type>
		class Mapping {
		public:
			typedef std::unordered_map<std::string, std::type_index> IdentifierMap;
			typedef std::unordered_map<std::type_index, std::unique_ptr<Interface>> TypeMap;
			Mapping() {};
			virtual ~Mapping() {};
			static void toIdentifierMap(IdentifierMap & map, const std::string &name) {
				map.insert(std::make_pair(name, std::type_index(typeid(Type))));
			}
			static void toTypeMap(TypeMap & map) {
				map.insert(std::make_pair(std::type_index(typeid(Type)), std::unique_ptr<Type>(new Type())));
			}
		};
	};
};
#endif

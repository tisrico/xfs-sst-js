#include <time.h>
#include <windows.h>
#include <sstream>
#include <iomanip>
#include <vector>

#include "json.hpp"
using json = nlohmann::json;

//##############################################################################
//##############################################################################
std::string XSJ_SystemTime2String(const SYSTEMTIME *st) {
	std::stringstream oss;
	oss << st->wYear << ":" 
	<< std::setw(2) << std::setfill('0') << st->wMonth << ":" 
	<< std::setw(2) << std::setfill('0') << st->wDay << " "
	<< std::setw(2) << std::setfill('0') << st->wHour << ":"
	<< std::setw(2) << std::setfill('0') << st->wMinute << ":"
	<< std::setw(2) << std::setfill('0') << st->wSecond << ":"
	<< std::setw(3) << std::setfill('0') << st->wMilliseconds;

	return oss.str();
}

//##############################################################################
//##############################################################################
std::vector<std::string> XSJ_List2Strings(LPCSTR pList) {
	std::vector<std::string> list;
	LPCSTR pp = pList;
	while(pp && *pp) {
		std::string name;
		while(*pp) {
			name += *pp;
			pp++;
		}
		pp++;
		list.push_back(name);
	}

	return list;
}

//##############################################################################
//##############################################################################
template <typename T, typename R=json>
json XSJ_ListNullTerminatedPointers(T* const * pp, R(*converter)(const T*)) {
	std::vector<R> js;
	if(!pp) {
		return json(js);
	}

	while(*pp) {
		T* p = *pp;
		if(converter) {
			js.push_back(converter(p));
		}
		else {
			js.push_back(json(p));	
		}
		pp++;
	}

	return json(js);
}

//##############################################################################
//##############################################################################
template <typename T, typename R=json>
json XSJ_ListNullTerminatedPointersValue(T* const * pp, R(*converter)(const T)) {
	std::vector<R> js;
	if(!pp) {
		return json(js);
	}

	while(*pp) {
		T* p = *pp;
		if(converter) {
			js.push_back(converter(*p));
		}
		else {
			js.push_back(json(*p));	
		}
		pp++;
	}

	return json(js);
}

//##############################################################################
//##############################################################################
template <typename T, typename W, typename R=json>
json XSJ_ListArray(const T* p, R(*mc)(const T), std::string(*ic)(W), int len) {
	std::map<std::string, R> jsm;
	std::vector<std::string> jsa;
	if(!p) {
		return json(js);
	}

	for(int i=0; i<len; i++) {

		if(mc) {
			if(ic) {
				std::string sidx = ic(i);
				jsm[sidx] = mc(p[i]);
			}
			else {
				jsa.push_back(mc(p));
			}
		}
		else {
			if(ic) {
				std::string sidx = ic(i);
				jsm[sidx] = joson(p);
			}
			else {
				jsa.push_back(joson(p));
			}
		}
	}

	if(ic) {
		return jsm;
	}
	else {
		return jsa;
	}
}


/*
// xfs-sst-js:{name:"data", type: "SYSTEMTIME", codeName: "SysteTime", leading:1, output:true, input:false, command:"", directCopy:true}
	j = XSJ_SystemTime2String(p);
// xfs-sst-js:{name:"end"}
*/

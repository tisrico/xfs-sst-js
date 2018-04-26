#ifndef pseduo_h
#define pseduo_h

#include <time.h>
#include <windows.h>
#include <sstream>
#include <iomanip>
#include <vector>
#include "xfsadmin.h"
#include <string>

#include "json.hpp"
using json = nlohmann::json;

//##############################################################################
//##############################################################################
typedef CHAR __CHARRAY;

//##############################################################################
//##############################################################################
typedef json (*Translate2JS)(const LPVOID);

//##############################################################################
//##############################################################################
typedef LPVOID (*Translate2XFS)(const json&);


//##############################################################################
//##############################################################################
struct Translator {
	std::string strCommand;
	std::string strCodeName;
	Translate2XFS fpToXFS;
	Translate2JS fpToJS;
};

//##############################################################################
//##############################################################################
inline std::string XSJ_SystemTime2String(const SYSTEMTIME& st) {
	std::stringstream oss;
	oss << st.wYear << "-" 
	<< std::setw(2) << std::setfill('0') << st.wMonth << "-" 
	<< std::setw(2) << std::setfill('0') << st.wDay << " "
	<< std::setw(2) << std::setfill('0') << st.wHour << ":"
	<< std::setw(2) << std::setfill('0') << st.wMinute << ":"
	<< std::setw(2) << std::setfill('0') << st.wSecond << "."
	<< std::setw(3) << std::setfill('0') << st.wMilliseconds;

	return oss.str();
}

//##############################################################################
//##############################################################################
inline std::string XSJ_SystemTime2String(const SYSTEMTIME *st) {
	std::stringstream oss;
	oss << st->wYear << "-" 
	<< std::setw(2) << std::setfill('0') << st->wMonth << "-" 
	<< std::setw(2) << std::setfill('0') << st->wDay << " "
	<< std::setw(2) << std::setfill('0') << st->wHour << ":"
	<< std::setw(2) << std::setfill('0') << st->wMinute << ":"
	<< std::setw(2) << std::setfill('0') << st->wSecond << "."
	<< std::setw(3) << std::setfill('0') << st->wMilliseconds;

	return oss.str();
}

//##############################################################################
//##############################################################################
inline std::vector<std::string> XSJ_List2Strings(LPCSTR pList) {
	std::vector<std::string> list;
	LPCSTR pl = pList;
	while(pl && *pl) {
		std::string name(pl);
		list.push_back(name);
		pl += name.length() + 1;
	}

	return list;
}

//##############################################################################
//##############################################################################
template <typename T, typename R = json>
json XSJ_ListNullTerminatedValues(const T* p, R(*converter)(const T&) = nullptr) {
	std::vector<R> js;
	if (!p) {
		return js;
	}

	while (p && *p != NULL) {
		T v = *p;
		if (converter) {
			js.push_back(converter(v));
		}
		else {
			js.push_back(R(v));
		}
		p++;
	}

	return js;
}

//##############################################################################
//##############################################################################
template <typename T, typename R=json>
json XSJ_ListNullTerminatedPointers(const T** pp, R(*converter)(const T*)=nullptr) {
	std::vector<R> js;
	if(!pp) {
		return js;
	}

	while(*pp) {
		const T* p = *pp;
		if(converter) {
			auto x = converter(p);
			js.push_back(x);
		}
		else {
			js.push_back(R(p));	
		}
		pp++;
	}

	return js;
}

//##############################################################################
//##############################################################################
template <typename T, typename R=json>
json XSJ_ListNullTerminatedPointersValue(const T** pp, R(*converter)(const T)) {
	std::vector<R> js;
	if(!pp) {
		return js;
	}

	while(*pp) {
		const T* p = *pp;
		if(converter) {
			js.push_back(converter(*p));
		}
		else {
			js.push_back(json(*p));	
		}
		pp++;
	}

	return js;
}

//##############################################################################
// tranlsate p[idx] of len length, idx is coded in ic, the value is coded in mc
//##############################################################################
template <typename T, typename S, typename W, typename R=json>
json XSJ_ListArray(const T* p, R(*mc)(const S), std::string(*ic)(const W), int len) {
	std::map<std::string, json> jsm;
	std::vector<json> jsa;
	if(!p) {
		if(ic) {
			return jsm;
		}
		else {
			return jsa;
		}
	}

	for(int i=0; i<len; i++) {

		if(mc) {
			if(ic) {
				std::string sidx = ic(i);
				jsm[sidx] = mc(p[i]);
			}
			else {
				jsa.push_back(mc(p[i]));
			}
		}
		else {
			if(ic) {
				std::string sidx = ic(i);
				jsm[sidx] = p[i];
			}
			else {
				jsa.push_back(p[i]);
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


//##############################################################################
//##############################################################################
template <typename T, typename S, typename W, typename R=json>
json XSJ_ListArrayValue(const T* p, R(*mc)(const S), std::string(*ic)(const W), int len) {
	std::map<std::string, json> jsm;
	std::vector<json> jsa;
	if(!p) {
		if(ic) {
			return jsm;
		}
		else {
			return jsa;
		}
	}

	for(int i=0; i<len; i++) {
		if(!p[i]) {
			continue;
		}

		if(mc) {
			if(ic) {
				std::string sidx = ic(i);
				jsm[sidx] = mc(*p[i]);
			}
			else {
				jsa.push_back(mc(*p[i]));
			}
		}
		else {
			if(ic) {
				std::string sidx = ic(i);
				jsm[sidx] = *p[i];
			}
			else {
				jsa.push_back(*p[i]);
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

//#############################################################################
//#############################################################################
inline char* HexToBytes(const std::string& hex, char* pData) {
	std::vector<char> bytes;

	for (unsigned int i = 0; i < hex.length(); i += 2) {
		std::string byteString = hex.substr(i, 2);
		char byte = (char)strtol(byteString.c_str(), NULL, 16);
		*pData = byte;
		pData++;
	}

	return pData;
}

//#############################################################################
//#############################################################################
class XSJAllocator {
public:
	XSJAllocator(bool autoRelease = false) 
		:m_pHead(nullptr), m_bAutoRelease(autoRelease) {

		}

	~XSJAllocator() {
		if (nullptr != m_pHead && m_bAutoRelease) {
			WFMFreeBuffer(m_pHead);
		}		
	}

	LPVOID Get(int size) {
		if (size == 0) {
			return m_pHead;
		}

		if (nullptr == m_pHead) {
			if (WFS_SUCCESS != WFMAllocateBuffer(size, WFS_MEM_ZEROINIT, &m_pHead)) {
				throw "XFS allocator failed";
			}
			return m_pHead;
		}

		LPVOID result;
		if (WFS_SUCCESS != WFMAllocateMore(size, m_pHead, &result)) {
			throw "XFS allocator failed";
		}

		return result;		
	}

	LPSTR Get(const std::string& str, bool isHex=false) {

		if (!isHex) {
			auto len = (int)str.length();
			if (len) {
				auto pointer = Get(len + 1);
				memcpy(pointer, str.c_str(), len);
				return (LPSTR)pointer;
			}
		}
		else {
			auto len = (int)str.length()/2;
			auto pointer = Get(len + 1);
			HexToBytes(str, (LPSTR)pointer);
			return (LPSTR)pointer;
		}

		return nullptr;		
	}

	template<typename T>
	T* Get() {
		return (T*)Get(sizeof(T));
	}

	LPVOID Get(void) {
		return m_pHead;
	}

protected:
	LPVOID	m_pHead;
	bool	m_bAutoRelease;
};

//#############################################################################
//#############################################################################
inline LPSTR XSJStringArrayToNullTerminated(std::vector<std::string> fields, XSJAllocator* a) {
	int totalSize = 0;
	for(auto it=fields.begin(); it != fields.end(); it++) {
		totalSize += (int)it->length() + 1;
	}
	totalSize++;
	LPSTR ret = (LPSTR)a->Get(totalSize);
	LPSTR p = ret;
	for(auto it=fields.begin(); it != fields.end(); it++) {
		strncpy(p, it->c_str(), it->length());
		p+=it->length();
		p++;
	}
	return ret;
}

//#############################################################################
//#############################################################################
inline LPSTR XSJDecodePtrFields(const json &j, XSJAllocator* a) {
	std::vector<std::string> fields;

	for (auto it = j.begin(); it != j.end(); ++it) {
		auto key = it.key();
		auto value = it.value();
		if(value.is_array()) {
			int i = 0;
			for (auto ix = value.begin(); ix != value.end(); ++ix) {
				std::stringstream oss;
				auto subvalue = *ix;
				oss << key << "[" << i << "]=" << subvalue;
				fields.push_back(oss.str());
				i++;
			}
		}
		else {
			std::stringstream oss;
			oss << key << "=";
			oss << value;
			fields.push_back(oss.str());
		}
	}
	return XSJStringArrayToNullTerminated(fields, a);
}

//#############################################################################
//#############################################################################
inline json XSJ_Stringify(LPCSTR string) {
	if(!string) {
		return json(nullptr);
	}
	return json(std::string(string));
}

//#############################################################################
//#############################################################################
inline json XSJ_Stringify(LPCWSTR string) {
	if(!string) {
		return json(nullptr);
	}
	return json(std::wstring(string));
}

//#############################################################################
//#############################################################################
inline json XSJ_Stringify(LPBYTE string) {
	if(!string) {
		return json(nullptr);
	}
	return json(std::wstring((LPCWSTR)string));
}

#endif
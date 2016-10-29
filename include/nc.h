#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <cstdarg>

template <typename T, bool bitwise>
class NamedCodeBase {
public:
	NamedCodeBase(bool bw = bitwise) :m_bIsBitwised(bw) {
	}

	~NamedCodeBase() {
	}

	void Add(T key, const std::string& name) {
		m_forMap[(int)key] = name;
		m_revMap[name] = (int)key;
	}

	std::string Lookup(T key, bool compond = true) const {
		if (compond && m_bIsBitwised) {
			std::ostringstream result;

			for (short i = 0; i<32; i++) {
				int bkey = 1 << i;
				if (bkey & key) {
					std::string name = Lookup((T)bkey, false);
					if (result.str() != "") {
						result << "|";
					}
					if (name != "") {
						result << name;
					}
					else {
						result << bkey;
					}
				}
			}
			return result.str();
		}

		auto px = m_forMap.find((int)key);
		if (px != m_forMap.end()) {
			return px->second;
		}

		return "";
	}

	T Lookup(std::string name, bool compond = true) const {
		if (compond && m_bIsBitwised) {
			int result = 0;
			std::stringstream ss(name);
			std::string bname;

			while (std::getline(ss, bname, '|')) {
				result |= (int)Lookup(bname, false);
			}
			return (T)result;
		}


		auto px = m_revMap.find(name);
		if (px != m_revMap.end()) {
			return (T)px->second;
		}

		return (T)0;
	}

protected:
	bool m_bIsBitwised;
	std::map<int, std::string> m_forMap;
	std::map<std::string, int> m_revMap;
};

struct SingletonEmptyStruct {};

template <typename T, typename V = SingletonEmptyStruct>
class Singleton {
public:
	static T* Instance() {
		CreateInstance();
		return _instance;
	}

protected:
	virtual ~Singleton() {}
	inline explicit Singleton() {}

private:
	static T* _instance;
	static T* CreateInstance() {
		if (!_instance) {
			return _instance = new T();
		}

		return _instance;
	}
};

template<typename T, typename V>
T* Singleton<T, V>::_instance = 0;

#define NC_ADDER(item) \
        holder->Add(item, #item);

#define DEFINE_NAMEDCODE(name, type, bitwise, nc_list) \
    struct __##name##Triat {\
        __##name##Triat() {\
            auto holder = Singleton<NamedCodeBase<type, bitwise>, __##name##Triat>::Instance(); \
            nc_list(NC_ADDER); \
        } \
     }; \
    inline NamedCodeBase<type, bitwise>* Get##name##Instance() { \
    	static __##name##Triat initializer; \
    	return Singleton<NamedCodeBase<type, bitwise>, __##name##Triat>::Instance(); \
    } \
    inline std::string Get##name##Name(type key) { \
        return Get##name##Instance()->Lookup(key); \
    } \
    inline type Get##name##Id(const std::string& _name) { \
        return Get##name##Instance()->Lookup(_name); \
    }

#define DNCODE(name, type) \
    DEFINE_NAMEDCODE(name, type, false, List##name);

#define DBWNCODE(name, type) \
    DEFINE_NAMEDCODE(name, type, true, List##name);

#define DNICODE(name) \
    DNCODE(name, int);

#define DBWNICODE(name) \
    DBWNCODE(name, int);


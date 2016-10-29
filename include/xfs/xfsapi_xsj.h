#include "xfsapi.h"
#include "json.hpp"
using json = nlohmann::json;


//##############################################################################
//##############################################################################
inline json XSJTranslate(const HAPP p) {
	json j;
	if(!p) return j;

	j = (int)p;

	return j;
}

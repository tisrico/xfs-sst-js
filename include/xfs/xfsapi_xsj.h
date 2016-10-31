#include "xfsapi.h"
#include "json.hpp"
using json = nlohmann::json;


//##############################################################################
//##############################################################################
inline json XSJTranslate(const HAPP p) {
	json j;

	j["handle"] = (int)p;

	return j;
}

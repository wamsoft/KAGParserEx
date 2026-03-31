#ifndef KAGParserExHPP
#define KAGParserExHPP

#include "tp_stub.h"

#define TVP_KAGPARSER_EX_PLUGIN

#include "tjsHashSearch.h"
using namespace TJS;
#include <vector>

#define TVP_KAGPARSER_EX_PLUGIN
#define TVP_KAGPARSER_EX_CLASSNAME TJS_W("KAGParser")

#define TVP_KAGPARSER_CONCAT(a,b) a ## b

#define TVP_KAGPARSER_MESSAGEMAP(name) (TJSGetMessageMapMessage(TJS_W(#name)).c_str())
#define TVPThrowInternalError TVPThrowExceptionMessage(TVP_KAGPARSER_MESSAGEMAP(TVPInternalError), __FILE__,  __LINE__)

#include "KAGParser.h"
#endif

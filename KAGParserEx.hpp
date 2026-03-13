#ifndef KAGParserExHPP
#define KAGParserExHPP

#include "tp_stub.h"

#define TVP_KAGPARSER_EX_PLUGIN

#include "tjsHashSearch.h"
using namespace TJS;
#include <vector>

#define TVP_KAGPARSER_EX_PLUGIN
#define TVP_KAGPARSER_EX_CLASSNAME TJS_W("KAGParser")

// 正規のプラグインの場合の細工
#ifdef __TP_STUB_H__

#define TVP_KAGPARSER_MESSAGEMAP(name) (TJSGetMessageMapMessage(TJS_W(#name)).c_str())

#ifdef _WIN32
// Windows original string function macros (mapped to wchar_t functions)
#define TJS_strchr			wcschr
#define TJS_strcmp			wcscmp
#define TJS_strncpy			wcsncpy
#define TJS_strlen          wcslen

#endif

// from MsgIntf.h (and MESSAGEMAP modified)
#define TVPThrowInternalError TVPThrowExceptionMessage(TVP_KAGPARSER_MESSAGEMAP(TVPInternalError), __FILE__,  __LINE__)

#endif

#include "KAGParser.h"
#endif
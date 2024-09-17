#ifndef KAGParserExHPP
#define KAGParserExHPP

#ifndef NO_V2LINK
#include <windows.h>
#endif


#include "tp_stub.h"

#define TVP_KAGPARSER_EX_PLUGIN

#include "tjsHashSearch.h"
using namespace TJS;
#include <vector>

#define TVP_KAGPARSER_EX_PLUGIN
#define TVP_KAGPARSER_EX_CLASSNAME TJS_W("KAGParser")

#define TVP_KAGPARSER_CONCAT(a,b) a ## b

// 正規のプラグインの場合の細工
#ifdef __TP_STUB_H__

#define TVP_KAGPARSER_MESSAGEMAP(name) (TJSGetMessageMapMessage(TVP_KAGPARSER_CONCAT(L,#name)).c_str())
// from tjsConfig.h
#define TJS_strchr			wcschr
#define TJS_strcmp			wcscmp
#define TJS_strncpy			wcsncpy
#define TJS_strlen          wcslen

// from MsgIntf.h (and MESSAGEMAP modified)
#define TVPThrowInternalError TVPThrowExceptionMessage(TVP_KAGPARSER_MESSAGEMAP(TVPInternalError), __FILE__,  __LINE__)

#endif

#include "KAGParser.h"
#endif

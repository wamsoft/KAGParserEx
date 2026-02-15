#include "KAGParserEx.hpp"

static iTJSDispatch2 *origKAGParser = NULL;

void kagparserex_init()
{
	tTJSNI_KAGParser::initMethod();
	
	iTJSDispatch2 * global = TVPGetScriptDispatch();
	if (global) {
		tTJSVariant val;
		if (TJS_SUCCEEDED(global->PropGet(0, TVP_KAGPARSER_EX_CLASSNAME, NULL, &val, global))) {
			origKAGParser = val.AsObject();
			val.Clear();
		}
		iTJSDispatch2 * tjsclass = tTJSNC_KAGParser::CreateNativeClass();
		val = tTJSVariant(tjsclass);
		tjsclass->Release();
		global->PropSet(TJS_MEMBERENSURE, TVP_KAGPARSER_EX_CLASSNAME, NULL, &val, global);
		global->Release();
	}
}

#ifdef TVP_STATIC_PLUGIN

#define EXPORT(hr) static hr STDCALL

#else

#if defined(_MSC_VER)
    #define DLL_EXPORT  __declspec(dllexport)
#else
	#define DLL_EXPORT  __attribute__((visibility("default")))
#endif

#define EXPORT(hr) extern "C" DLL_EXPORT hr STDCALL

#ifdef _MSC_VER
# if defined(_M_AMD64) || defined(_M_X64)
#  pragma comment(linker, "/EXPORT:V2Link")
#  pragma comment(linker, "/EXPORT:V2Unlink")
# else
#  pragma comment(linker, "/EXPORT:V2Link=_V2Link@4")
#  pragma comment(linker, "/EXPORT:V2Unlink=_V2Unlink@0")
# endif
#endif
#ifdef __GNUC__
asm (".section .drectve");
# if defined(__x86_64__) || defined(__x86_64)
asm (".ascii \" -export:V2Link=V2Link -export:V2Unlink=V2Unlink\"");
# else
asm (".ascii \" -export:V2Link=V2Link@4 -export:V2Unlink=V2Unlink@0\"");
# endif
#endif


int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
	return 1;
}

#endif

//---------------------------------------------------------------------------
static tjs_int GlobalRefCountAtInit = 0;
EXPORT(HRESULT) V2Link(iTVPFunctionExporter *exporter)
{
	TVPInitImportStub(exporter);

	kagparserex_init();

	GlobalRefCountAtInit = TVPPluginGlobalRefCount;
	return S_OK;
}
//---------------------------------------------------------------------------
EXPORT(HRESULT) V2Unlink()
{
	if(TVPPluginGlobalRefCount > GlobalRefCountAtInit) return E_FAIL;

	iTJSDispatch2 * global = TVPGetScriptDispatch();
	if (global)	{
		global->DeleteMember(0, TVP_KAGPARSER_EX_CLASSNAME, NULL, global);
		if (origKAGParser) {
			tTJSVariant val(origKAGParser);
			origKAGParser->Release();
			origKAGParser = NULL;
			global->PropSet(TJS_MEMBERENSURE, TVP_KAGPARSER_EX_CLASSNAME, NULL, &val, global);
		}
		global->Release();
	}

	tTJSNI_KAGParser::doneMethod();
	
	TVPUninitImportStub();
	return S_OK;
}

#ifdef TVP_STATIC_PLUGIN

#if defined(_MSC_VER)
    #define EXPORT_USED __declspec(dllexport)
#else
	#define EXPORT_USED __attribute__((visibility("default"), used))
#endif

#define str(x) TJS_W(#x)
#define strx(x) str(x)
#define CAT(a, b) a##b
#define XCAT(a, b) CAT(a, b)
#define MAKE_FUNC(name) XCAT(krkrz_plugin_, name)

// リンク用エントリ関数
// _krkrz_plugin_プロジェクト名 で関数が作られる
extern "C" EXPORT_USED void STDCALL MAKE_FUNC(TVP_PLUGIN_NAME)() {
	static iTVPStaticPlugin plugin;
    plugin.name = strx(TVP_PLUGIN_NAME);
	plugin.link = (int32_t (STDCALL *)(iTVPFunctionExporter *))V2Link;
	plugin.unlink = (int32_t (STDCALL *)(void))V2Unlink;
	TVPRegisterPlugin(&plugin);
}

#endif

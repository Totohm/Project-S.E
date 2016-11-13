//
// MATLAB Compiler: 6.2 (R2016a)
// Date: Sun Nov 13 12:14:28 2016
// Arguments: "-B" "macro_default" "-W" "cpplib:planar_plane_remover" "-T"
// "link:lib" "-d"
// "D:\Scanner_3D\3Dphoto\background_C++_library\planar_plane_remover\for_testin
// g" "-v" "D:\Scanner_3D\3Dphoto\planar_plane_remover.m" 
//

#include <stdio.h>
#define EXPORTING_planar_plane_remover 1
#include "planar_plane_remover.h"

static HMCRINSTANCE _mcr_inst = NULL;


#if defined( _MSC_VER) || defined(__BORLANDC__) || defined(__WATCOMC__) || defined(__LCC__)
#ifdef __LCC__
#undef EXTERN_C
#endif
#include <windows.h>

static char path_to_dll[_MAX_PATH];

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, void *pv)
{
    if (dwReason == DLL_PROCESS_ATTACH)
    {
        if (GetModuleFileName(hInstance, path_to_dll, _MAX_PATH) == 0)
            return FALSE;
    }
    else if (dwReason == DLL_PROCESS_DETACH)
    {
    }
    return TRUE;
}
#endif
#ifdef __cplusplus
extern "C" {
#endif

static int mclDefaultPrintHandler(const char *s)
{
  return mclWrite(1 /* stdout */, s, sizeof(char)*strlen(s));
}

#ifdef __cplusplus
} /* End extern "C" block */
#endif

#ifdef __cplusplus
extern "C" {
#endif

static int mclDefaultErrorHandler(const char *s)
{
  int written = 0;
  size_t len = 0;
  len = strlen(s);
  written = mclWrite(2 /* stderr */, s, sizeof(char)*len);
  if (len > 0 && s[ len-1 ] != '\n')
    written += mclWrite(2 /* stderr */, "\n", sizeof(char));
  return written;
}

#ifdef __cplusplus
} /* End extern "C" block */
#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_planar_plane_remover_C_API
#define LIB_planar_plane_remover_C_API /* No special import/export declaration */
#endif

LIB_planar_plane_remover_C_API 
bool MW_CALL_CONV planar_plane_removerInitializeWithHandlers(
    mclOutputHandlerFcn error_handler,
    mclOutputHandlerFcn print_handler)
{
    int bResult = 0;
  if (_mcr_inst != NULL)
    return true;
  if (!mclmcrInitialize())
    return false;
  if (!GetModuleFileName(GetModuleHandle("planar_plane_remover"), path_to_dll, _MAX_PATH))
    return false;
    {
        mclCtfStream ctfStream = 
            mclGetEmbeddedCtfStream(path_to_dll);
        if (ctfStream) {
            bResult = mclInitializeComponentInstanceEmbedded(   &_mcr_inst,
                                                                error_handler, 
                                                                print_handler,
                                                                ctfStream);
            mclDestroyStream(ctfStream);
        } else {
            bResult = 0;
        }
    }  
    if (!bResult)
    return false;
  return true;
}

LIB_planar_plane_remover_C_API 
bool MW_CALL_CONV planar_plane_removerInitialize(void)
{
  return planar_plane_removerInitializeWithHandlers(mclDefaultErrorHandler, 
                                                    mclDefaultPrintHandler);
}

LIB_planar_plane_remover_C_API 
void MW_CALL_CONV planar_plane_removerTerminate(void)
{
  if (_mcr_inst != NULL)
    mclTerminateInstance(&_mcr_inst);
}

LIB_planar_plane_remover_C_API 
void MW_CALL_CONV planar_plane_removerPrintStackTrace(void) 
{
  char** stackTrace;
  int stackDepth = mclGetStackTrace(&stackTrace);
  int i;
  for(i=0; i<stackDepth; i++)
  {
    mclWrite(2 /* stderr */, stackTrace[i], sizeof(char)*strlen(stackTrace[i]));
    mclWrite(2 /* stderr */, "\n", sizeof(char)*strlen("\n"));
  }
  mclFreeStackTrace(&stackTrace, stackDepth);
}


LIB_planar_plane_remover_C_API 
bool MW_CALL_CONV mlxPlanar_plane_remover(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                          *prhs[])
{
  return mclFeval(_mcr_inst, "planar_plane_remover", nlhs, plhs, nrhs, prhs);
}

LIB_planar_plane_remover_CPP_API 
void MW_CALL_CONV planar_plane_remover(int nargout, mwArray& background, mwArray& object, 
                                       const mwArray& plyimage)
{
  mclcppMlfFeval(_mcr_inst, "planar_plane_remover", nargout, 2, 1, &background, &object, &plyimage);
}


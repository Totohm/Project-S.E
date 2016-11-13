//
// MATLAB Compiler: 6.2 (R2016a)
// Date: Sun Nov 13 12:14:28 2016
// Arguments: "-B" "macro_default" "-W" "cpplib:planar_plane_remover" "-T"
// "link:lib" "-d"
// "D:\Scanner_3D\3Dphoto\background_C++_library\planar_plane_remover\for_testin
// g" "-v" "D:\Scanner_3D\3Dphoto\planar_plane_remover.m" 
//

#ifndef __planar_plane_remover_h
#define __planar_plane_remover_h 1

#if defined(__cplusplus) && !defined(mclmcrrt_h) && defined(__linux__)
#  pragma implementation "mclmcrrt.h"
#endif
#include "mclmcrrt.h"
#include "mclcppclass.h"
#ifdef __cplusplus
extern "C" {
#endif

#if defined(__SUNPRO_CC)
/* Solaris shared libraries use __global, rather than mapfiles
 * to define the API exported from a shared library. __global is
 * only necessary when building the library -- files including
 * this header file to use the library do not need the __global
 * declaration; hence the EXPORTING_<library> logic.
 */

#ifdef EXPORTING_planar_plane_remover
#define PUBLIC_planar_plane_remover_C_API __global
#else
#define PUBLIC_planar_plane_remover_C_API /* No import statement needed. */
#endif

#define LIB_planar_plane_remover_C_API PUBLIC_planar_plane_remover_C_API

#elif defined(_HPUX_SOURCE)

#ifdef EXPORTING_planar_plane_remover
#define PUBLIC_planar_plane_remover_C_API __declspec(dllexport)
#else
#define PUBLIC_planar_plane_remover_C_API __declspec(dllimport)
#endif

#define LIB_planar_plane_remover_C_API PUBLIC_planar_plane_remover_C_API


#else

#define LIB_planar_plane_remover_C_API

#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_planar_plane_remover_C_API 
#define LIB_planar_plane_remover_C_API /* No special import/export declaration */
#endif

extern LIB_planar_plane_remover_C_API 
bool MW_CALL_CONV planar_plane_removerInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_planar_plane_remover_C_API 
bool MW_CALL_CONV planar_plane_removerInitialize(void);

extern LIB_planar_plane_remover_C_API 
void MW_CALL_CONV planar_plane_removerTerminate(void);



extern LIB_planar_plane_remover_C_API 
void MW_CALL_CONV planar_plane_removerPrintStackTrace(void);

extern LIB_planar_plane_remover_C_API 
bool MW_CALL_CONV mlxPlanar_plane_remover(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                          *prhs[]);


#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

/* On Windows, use __declspec to control the exported API */
#if defined(_MSC_VER) || defined(__BORLANDC__)

#ifdef EXPORTING_planar_plane_remover
#define PUBLIC_planar_plane_remover_CPP_API __declspec(dllexport)
#else
#define PUBLIC_planar_plane_remover_CPP_API __declspec(dllimport)
#endif

#define LIB_planar_plane_remover_CPP_API PUBLIC_planar_plane_remover_CPP_API

#else

#if !defined(LIB_planar_plane_remover_CPP_API)
#if defined(LIB_planar_plane_remover_C_API)
#define LIB_planar_plane_remover_CPP_API LIB_planar_plane_remover_C_API
#else
#define LIB_planar_plane_remover_CPP_API /* empty! */ 
#endif
#endif

#endif

extern LIB_planar_plane_remover_CPP_API void MW_CALL_CONV planar_plane_remover(int nargout, mwArray& background, mwArray& object, const mwArray& plyimage);

#endif
#endif

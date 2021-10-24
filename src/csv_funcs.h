/*****************************************************************************/
/**                      Funciones visibles por Gemix                       **/
/*****************************************************************************/
#ifndef __CSV_FUNCS_H_
#define __CSV_FUNCS_H_

#ifdef __cplusplus
extern "C" {
#endif


/**
 * Reads a CSV file and put's it on a INT8 array
 */
GMXvoid GMXEXT_CSV_readToInt8Array();


/**
 * Reads a CSV file and put's it on a INT16 array
 */
GMXvoid GMXEXT_CSV_readToInt16Array();

/**
 * Reads a CSV file and put's it on a INT32 array
 */
GMXvoid GMXEXT_CSV_readToInt32Array();

/**
 * Reads a CSV file and put's it on a UINT32 array
 */
GMXvoid GMXEXT_CSV_readToUInt32Array();

#ifdef __cplusplus
}
#endif

#endif //__CSV_FUNCS_H_

/* vim: set ts=2 sw=2 tw=0 et fileencoding=utf-8 :*/

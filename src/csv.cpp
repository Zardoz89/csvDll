/*****************************************************************************/
/**                 Lector de ficheros CSV para GEMIX                       **/
/*****************************************************************************/

#include "csv.h"

GMXDEFINE_LIBRARY_PROPERTIES(GMXEXT_mod_csv,
    /* CATEGORY */
    GMXDEFINE_PROPERTY_CATEGORY(GMXCATEGORY_GENERIC);
    /* SYSTEM */
    GMXDEFINE_PROPERTY_SYSTEM(GMXSYSTEM_COMMON);
);

GMXDEFINE_LIBRARY_EXPORTS(GMXEXT_mod_csv,
    GMXDEFINE_FUNCTIONS(
      "CSV_ReadToArray(S,I,I8P)",   "I", 1, GMXEXT_CSV_readToInt8Array,
      "CSV_ReadToArray(S,I,UI8P)",  "I", 1, GMXEXT_CSV_readToUInt8Array,
      "CSV_ReadToArray(S,I,I16P)",  "I", 1, GMXEXT_CSV_readToInt16Array,
      "CSV_ReadToArray(S,I,UI16P)", "I", 1, GMXEXT_CSV_readToUInt16Array,
      "CSV_ReadToArray(S,I,I32P)",  "I", 1, GMXEXT_CSV_readToInt32Array,
      "CSV_ReadToArray(S,I,UI32P)", "I", 1, GMXEXT_CSV_readToUInt32Array,
      "CSV_ReadToArray(S,I,I64P)",  "I", 1, GMXEXT_CSV_readToInt64Array,
      "CSV_ReadToArray(S,I,UI64P)", "I", 1, GMXEXT_CSV_readToUInt64Array
      );
    );

/* vim: set ts=2 sw=2 tw=0 et fileencoding=utf-8 :*/

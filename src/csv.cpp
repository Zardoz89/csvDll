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
      "csv_readtoarray(S,I,I8P=0)",  "I", 1, GMXEXT_CSV_readToInt8Array,
    //  "csv_readtoarray(S,I,I16P=0)", "I", 1, GMXEXT_CSV_readToInt16Array,
      "csv_readtoarray(S,I,I32P=0)", "I", 1, GMXEXT_CSV_readToInt32Array
    // "CSV_ReadToArray(S,I,U32P)", "I", 1, GMXEXT_CSV_readToUInt32Array
  );
);

/* vim: set ts=2 sw=2 tw=0 et fileencoding=utf-8 :*/

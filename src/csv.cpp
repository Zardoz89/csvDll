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
    "CSV_readToIntArray(S,I32P,I)", "I", 1, GMXEXT_CSV_readToInt32Array
  /* prototipo Gemix, retType, is_timing, ptrFunción  */
  );
);

/* vim: set ts=2 sw=2 tw=0 et fileencoding=utf-8 :*/

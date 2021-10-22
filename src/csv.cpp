/*****************************************************************************/
/**                 Lector de ficheros CSV para GEMIX                       **/
/*****************************************************************************/

#include "csv.h"

//INIT_LOG();

/**
 * Tamaño del tipo de dato
 *
typedef enum {
  BYTE,
  WORD,
  INT
} DataSize;

uint8_t isValueSeparatorWithEOLFilled = 0; // Flag para saber si ya hemos rellenado valueSeparatorWithEOL
const char* valueSeparator = ",";
char valueSeparatorWithEOL[BUFFER_SIZE]; // El elemento separador concatenado con EOL

void dropBufferFrom(char *buf,char dropCharacter);
void tokenizeLine(DataSize dataSize, char *buf, uint32_t offset, uint32_t numberOfElements, uint32_t *index);
void putValueInt(const char *token, uint32_t offset, uint32_t index);
void putValueWord(const char *token, uint32_t offset, uint32_t index);
void putValueByte(const char *token, uint32_t offset, uint32_t index);

**
 * Elimina del buf todo el contenido posterior a un caracter si este est?
 * presente
 * @param buf Ptr. al buf
 * @param dropCharacter Caracter a buscar el punto desde donde eliminar
 *
void dropBufferFrom(char *buf,char dropCharacter)
{
  char* position = strchr(buf, dropCharacter);
  if (position != NULL) {
    // Insertamos un caracter nulo en dicha posici?n para "cortar" la cadena por ahi
    *position = 0;
  }
}

**
 * Tokeniza el buf usando el separador ';' y procesa cada token
 * @param dataSize Tama?o del tipo de dato
 * @param buf Ptr. al buf
 * @param offset Offset del array de Ints de DIV
 * @param numberOfElements N? maximo de elementos del array
 * @param *index Indice del elemento del array a guardar
 *
void tokenizeLine(DataSize dataSize, char *buf, uint_32_t offset, uint_32_t numberOfElements, uint_32_t *index)
{
  const char* token = strtok(buf, valueSeparator);
  while (*index < numberOfElements && token != NULL && *token != 0) {
    if (offset != 0) {
      switch (dataSize) {
        case BYTE:
          putValueByte(token, offset, *index);
          break;

        case WORD:
          putValueWord(token, offset, *index);
          break;

        case INT:
        default:
          putValueInt(token, offset, *index);
      }
    }
    token = strtok(NULL, valueSeparatorWithEOL);
    // El indice lo aumentamos desde aqui para contar solo los tokens validos
    *index = *index + 1;
  }
}

**
 * Mete un valor int 32bits en la memoria de DIV
 *
void putValueInt(const char *token, uint_32_t offset, uint_32_t index)
{
  int_32_t val = 0;
  int_32_t* ptr = &mem[offset];
  if (token != NULL) {
    val = (int_32_t) strtol(token, NULL, 0);

    // mem es un array de int_32_t con toda la memoria del programa DIV
    // si DIV2 esta compactando cuando el tipo del array es byte o word, entonces
    // habra que hacer magia con punteros
    ptr[index] = val;
  }
}

**
 * Mete un valor word 16bit en la memoria de DIV
 *
void putValueWord(const char *token, uint_32_t offset, uint_32_t index)
{
  int_16_t val = 0;
  int_16_t* ptr = (int_16_t*) &mem[offset];
  if (token != NULL) {
    val = (int_16_t) strtol(token, NULL, 0);
    ptr[index] = val;
  }
}

**
 * Mete un valor byte en la memoria de DIV
 *
void putValueByte(const char *token, uint_32_t offset, uint_32_t index)
{
  int_8_t val = 0;
  int_8_t* ptr = (int_8_t*) &mem[offset];
  if (token != NULL) {
    val = (int_8_t) strtol(token, NULL, 0);
    ptr[index] = val;
  }
}
*/

GMXDEFINE_LIBRARY_PROPERTIES(GMXEXT_mod_csv,
    /* CATEGORY */
    GMXDEFINE_PROPERTY_CATEGORY(GMXCATEGORY_GENERIC);
    /* SYSTEM */
    GMXDEFINE_PROPERTY_SYSTEM(GMXSYSTEM_COMMON);
);

GMXDEFINE_LIBRARY_EXPORTS(GMXEXT_mod_csv,
  GMXDEFINE_FUNCTIONS(
    "csv_readToIntArray(S,IP,I)", "I", 1, GMXEXT_CSV_readToIntArray
  //  "csv_readtointarray(S,IP,I)", "I", 1, GMXEXT_CSV_readToIntArray
  /* prototipo Gemix, retType, is_timing, ptrFunción  */
  );
);

/* vim: set ts=2 sw=2 tw=0 et fileencoding=utf-8 :*/

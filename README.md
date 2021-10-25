Modulo Gemix para lectura de ficheros CSV simples
-------------------------------------------------

v0.4.0

Version ported/re-write for Gemix v8.0

This module implements functions to read CSV files and fill Gemix arrays. The
"," character it's used as a separator between values. And only numeric values
are allowed. The character "#" it's uses as a begin comment indicator. So after
a "#" everything on the same line will be ignored.

If a number begins with "0x" or "0X", it will interpreted as hexadecimal. If it
begins with "0", then will be interpreted as octal number (base 8). If a FLOAT
or DOUBLE array it's being filled, then would accept exponential notation
values and float/double values using a "." as decimal separator.

The internal buffers are of 512 bytes, so lines longer that 512 bytes will be
chomp to 512 bytes.

The allowed data types are : INT8, UINT8, INT16, UINT16, INT32, UINT32, INT64,
UINT64, FLOAT and DOUBLE. Mixed types on the same array aren't allowed.

## How build

Simply run `make` and will build 32bit and 64bit versions of the module using
gcc.

## Functions list


`INT CSV_ReadToArray(STRING fileName, INT maxSize, INT8* pointer)`
`INT CSV_ReadToArray(STRING fileName, INT maxSize, UINT8* pointer)`
`INT CSV_ReadToArray(STRING fileName, INT maxSize, INT16* pointer)`
`INT CSV_ReadToArray(STRING fileName, INT maxSize, UINT16* pointer)`
`INT CSV_ReadToArray(STRING fileName, INT maxSize, INT32* pointer)`
`INT CSV_ReadToArray(STRING fileName, INT maxSize, UINT32* pointer)`
`INT CSV_ReadToArray(STRING fileName, INT maxSize, INT64* pointer)`
`INT CSV_ReadToArray(STRING fileName, INT maxSize, UINT64* pointer)`
`INT CSV_ReadToArray(STRING fileName, INT maxSize, FLOAT* pointer)`
`INT CSV_ReadToArray(STRING fileName, INT maxSize, DOUBLE* pointer)`

Reads a CSV file on the path stored on the string *fileName*, and stores the
values in an integer array or struct pointed by *pointer*. The max number of 
elements read will be determined by *maxSize* (`sizeof(array)`). The return
value by the function, it's the number of elements read or -1 if there was an 
error.
If *pointer* is null or 0, then will not store any read element. It only will
return the number of elements that are on the CSV file.

## Examples

Typical use case:

```div2
/**
 * Genera la ruta relativa a los ficheros del juego
 */
function pathResolve(file)
begin
  return (/* "\foo\bar\" + */ file);
end

/**
 * Reads a CSV file and fills a int32 array
 */
function int loadData(string dataFile, int _size, int32* _data)
private
  string _path;
  int _retVal = 0;
  string _msg;
begin
  _path = pathResolve(dataFile);
  _retVal = CSV_ReadToArray(_path, _size, _data);
  if (_retVal <= 0)
    _msg = "Error al abrir fichero de datos: " + _path;
    write(0, 0, 0, 0, _msg);
    loop
      // abortamos ejecución
      if (key(_q) || key(_esc))
        let_me_alone();
        break;
      end

      frame;
    end
  end
  return(_retVal);
end

...

loadData("dat\mydata.dat", sizeof(myArray), &myArray);
```

Generating a dynamic array to load all data from CSV file:

```div2
typedef
  type DynArray
    int length;
    int32* data;
  end
end

/**
 * Reads a CSV file with data and allocates a dynamic array to store all the data
 * Returns a pointer to the dynamic array
 */
function DynArray loadAndAllocateData(string dataFile)
private
  string _path;
  int _retVal = 0;
  string _msg;
  DynArray _data;
begin
  _path = pathResolve(dataFile);
  _data.length = CSV_ReadToArray(_path, MAX_INT, _data.data);
  if (_data->length <= 0)
    _msg = "Error al abrir fichero de datos: " + _path;
    write(0, 0, 0, 0, _msg);
    loop
      // abort execution
      if (key(_q) || key(_esc))
        let_me_alone();
        break;
      end

      frame;
    end
  end

  _data->data = memory_new(_data.length * sizeof(int32));
  CSV_ReadToArray(_path, _data.length * sizeof(int32), _data.data);
  return(_data);
end
```


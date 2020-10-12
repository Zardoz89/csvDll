DLL para lectura de ficheros CSV simples
----------------------------------------

v0.3.1

Esta DLL implementa funciones para parsear ficheros CSV, donde se utiliza el
carácter ',' como elemento separador, y solo contienen valores numéricos. El
carácter '#' marca que el resto de la linea se ignore, siendo útil para agregar
comentarios y cabeceras en los ficheros.

Si un número comience con "0x" se interpretará en hexadecimal. Si comienca
precedido de un 0, entonces se interpretará en base octal.

Todos los buffers internos son de 256 bytes, con lo puede que no pueda procesar
correctamente lineas mas largas de 255 bytes;

## How build

### Original DIV 2 for MS-DOS

Requires Watcom C 10.6 installed on a DOS enviroment (dosbox, dosemu, virtual
machine or native install of MS-DOS/PC-DOS/DR-DOS, FreeDOs or OpenDOS).

To compile, simply launch make2.bat like if it was make coommand :

```
make2 all
```

A *debug* version could be generated. The debug version generates a CSV.LOG
file with information about the data being readed by the DLL. On every
invocation or execution, new content its append at the end of the log file.

```
make2 csv_dbg.dll
```

### DIV DX

Actually only works with @CicTek fork on Linux (64 bit). Simple launch
`./makeDll.sh` and it will generate a `csv.so` that could be used on DIV DX.

## Functions list

`INT setCSVSeparator(STRING separator)`

Sets the seperator token. The string it's used by C's strok function.


`INT readCSVToIntArray(STRING fileName, OFFSET offset, INT numberOfElements)`

Reads a CSV file on the path stored on the string *fileName*, and stores the
values in an integer array or struct pointed by *offset*. The max number of elements
read will be determinated by *numberOfElements*. The return value by the
function, it's the number of elements read or -1 if there was an error.
If *offset* is 0, then will not store any read element. It only will return the
number of elements that are on the CSV file.

`INT readCSVToWordArray(STRING fileName, OFFSET offset, INT numberOfElements)`

Reads a CSV file on the path stored on the string *fileName*, and stores the
values in an word array pointed by *offset*. The max number of elements
read will be determinated by *numberOfElements*. The return value by the
function, it's the number of elements read or -1 if there was an error.
If *offset* is 0, then will not store any read element. It only will return the
number of elements that are on the CSV file.

`INT readCSVToByteArray(STRING fileName, OFFSET offset, INT numberOfElements)`

Reads a CSV file on the path stored on the string *fileName*, and stores the
values in an byte array pointed by *offset*. The max number of elements
read will be determinated by *numberOfElements*. The return value by the
function, it's the number of elements read or -1 if there was an error.
If *offset* is 0, then will not store any read element. It only will return the
number of elements that are on the CSV file.


## Ejemplo de uso

Uso típico:

```div2
/**
 * Genera la ruta relativa a los ficheros del juego
 */
function pathResolve(file)
begin
  return (/* "\foo\bar\" + */ file);
end

/**
 * Lee un fichero CSV con datos de juego
 */
function loadData(dataFile, _offset, size)
private
  string _path;
  int _retVal = 0;
  string _msg;
begin
  _path = pathResolve(dataFile);
  _retVal = readCSVToIntArray(_path, _offset, size);
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

loadData("dat\mydata.dat", offset myArray, sizeof(myArray));
```

Determinar la cantidad de elementos en un fichero antes de cargar el contenido:

```div2
/**
 * Función que carga el contenido de un fichero CSV en un array dinamico
 (generado por malloc)
 * Devuelve un puntero al array dinamico
 */
function loadAndAllocateData(dataFile)
private
  string _path;
  int _retVal = 0;
  int _nElements = 0;
  string _msg;
  int pointer _data;
begin
  _path = pathResolve(dataFile);
  _nElements = readCSVToIntArray(_path, 0, max_int);
  if (_nElements <= 0)
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
  _data = malloc(_nElements);
  readCSVToIntArray(_path, _data, _nElements);
  return(_data);
end
```


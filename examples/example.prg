// Example program of using csv dll to read data from a CSV file
program example_csv;

// copy the propiated csv.so or csv.dll to this folder and modify the import
//import "csv.so";

private
int data[20];
begin
  loadData("data.csv", offset data, sizeof(data));

  for (y = 0; y < 2 ; y++);
    for (x = 0; x < 10; x++)
      write_int(0, x * 10, y * 10, 0, offset data[x + y*10]);
    end
  end
  loop
    frame;
    if (key(_q) || key(_esc))
      let_me_alone();
      break;
    end
  end
end

/**
 * Generates the relative path to the data files 
 */
function pathResolve(file)
begin
  return (file);
end

/**
 * Reads a CSV file with data
 */
function loadData(dataFile, _offset, size)
private
  string _path;
  int _retVal = 0;
  string _msg;
begin
  _path = pathResolve(dataFile);
  _retVal = CSV_readToIntArray(_path, _offset, size);
  if (_retVal <= 0)
    _msg = "Error reading data file: " + _path;
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
  return(_retVal);
end

/**
 * Reads a CSV file with data an allocated a dynamic array to store all the data
 * Returns a pointer to the dynamic array
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
  _nElements = CSV_readToIntArray(_path, 0, max_int);
  if (_nElements <= 0)
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
  _data = malloc(_nElements);
  CSV_readToIntArray(_path, _data, _nElements);
  return(_data);
end

/* vim: set ts=2 sw=2 tw=0 et fileencoding=iso8859-1 :*/

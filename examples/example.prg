compiler_options _use_cstyle;
// Example program of using csv dll to read data from a CSV file
program example_csv;

private
  int8 data_i8[40];
  int32 data_i32[40];
  uint32 data_u32[40];
  int tmp1;
  int tmp2;
  int tmp3;
  int caca;
begin
  mode_set(1024, 768);

  // int8 bit array
  loadData("data.csv", &data_i8, sizeof(data_i8));

  write(0, 0, y, 0, "int8 array");
  tmp1 = sizeof(data_i8) ;
  write(0, 100, y, 0, offset tmp1);
  y += 10;
  for (x = 0; x < tmp1; x++)
    write(0, (x%20)*40, y + (x/20)*10, 0, offset data_i8[x]);
  end
  y += 20;

  // int32 bit array
  loadData("data.csv", &data_i32, sizeof(data_i32));

  write(0, 0, y, 0, "int32 array");
  tmp2 = sizeof(data_i32) / sizeof(int32);
  write(0, 100, y, 0, offset tmp2);
  y += 10;
  for (x = 0; x < tmp2; x++)
    write(0, (x%20)*40, y + (x/20)*10, 0, offset data_i32[x]);
  end
  y += 30;

  // uint32 bit array
  loadData("data.csv", offset data_u32, sizeof(data_u32));

  write(0, 0, y, 0, "uint32 array");
  tmp3 = sizeof(data_u32) / sizeof(uint32);
  write(0, 100, y, 0, offset tmp3);
  y += 10;
  for (x = 0; x < tmp3; x++)
    write(0, (x%20)*40, y + (x/20)*10, 0, offset data_u32[x]);
  end
  y += 20;

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
function loadData(string dataFile, int32*_ptr, int _size)
private
  string _path;
  int _retVal = 0;
  string _msg;
begin
  _path = pathResolve(dataFile);
  _retVal = CSV_ReadToArray(_path, _ptr, _size);
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

function loadData(string dataFile, int8*_ptr, int _size)
private
  string _path;
  int _retVal = 0;
  string _msg;
begin
  _path = pathResolve(dataFile);
  _retVal = CSV_ReadToArray(_path, _ptr, _size);
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
 /*
function loadAndAllocateData(dataFile)
private
  string _path;
  int _retVal = 0;
  int _nElements = 0;
  string _msg;
  int pointer _data;
begin
  _path = pathResolve(dataFile);
  _nElements = csv_readtointarray(_path, 0, max_int);
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
  csv_readtointarray(_path, _data, _nElements);
  return(_data);
end
*/
/* vim: set ts=2 sw=2 tw=0 et fileencoding=iso8859-1 :*/

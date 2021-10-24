compiler_options _extended_conditions, _use_cstyle;
// Example program of using csv dll to read data from a CSV file
program example_csv;

typedef
  type DynArray
    int length;
    int32* data;
  end
end


private
  int8 data_i8[40];
  uint16 data_u16[40];
  int32 data_i32[40];

  int tmp1;
  int tmp2;
  int tmp3;

  DynArray dyn;
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


  // uint16 bit array
  loadData("data.csv", &data_u16, sizeof(data_u16));

  write(0, 0, y, 0, "uint16 array");
  tmp2 = sizeof(data_u16) / 2;
  write(0, 100, y, 0, offset tmp2);
  y += 10;
  for (x = 0; x < tmp2; x++)
    write(0, (x%20)*40, y + (x/20)*10, 0, offset data_u16[x]);
  end
  y += 20;

  // int32 bit array
  loadData("data.csv", &data_i32, sizeof(data_i32));

  write(0, 0, y, 0, "int32 array");
  tmp3 = sizeof(data_i32) / sizeof(int32);
  write(0, 100, y, 0, offset tmp3);
  y += 10;
  for (x = 0; x < tmp3; x++)
    write(0, (x%20)*40, y + (x/20)*10, 0, offset data_i32[x]);
  end
  y += 20;


  // Dinamico de int32
  dyn = loadAndAllocateData("data2.csv");
  write(0, 0, y, 0, "dynamic array from csv");
  write(0, 200, y, 0, offset dyn.length);
  y += 10;
  for (x = 0; x < dyn.length; x++)
    write(0, (x%20)*40, y + (x/20)*10, 0, offset dyn.data[x]);
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
function int loadData(string dataFile, int32*_ptr, int _size)
private
  string _path;
  int _retVal = 0;
  string _msg;
begin
  _path = pathResolve(dataFile);
  _retVal = CSV_ReadToArray(_path, _size, _ptr);
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


function int loadData(string dataFile, uint32*_ptr, int _size)
private
  string _path;
  int _retVal = 0;
  string _msg;
begin
  _path = pathResolve(dataFile);
  _retVal = CSV_ReadToArray(_path, _size, _ptr);
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

function int loadData(string dataFile, int16*_ptr, int _size)
private
  string _path;
  int _retVal = 0;
  string _msg;
begin
  _path = pathResolve(dataFile);
  _retVal = CSV_ReadToArray(_path, _size, _ptr);
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

function int loadData(string dataFile, uint16*_ptr, int _size)
private
  string _path;
  int _retVal = 0;
  string _msg;
begin
  _path = pathResolve(dataFile);
  _retVal = CSV_ReadToArray(_path, _size, _ptr);
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

function int loadData(string dataFile, int8*_ptr, int _size)
private
  string _path;
  int _retVal = 0;
  string _msg;
begin
  _path = pathResolve(dataFile);
  _retVal = CSV_ReadToArray(_path, _size, _ptr);
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

function int loadData(string dataFile, uint8*_ptr, int _size)
private
  string _path;
  int _retVal = 0;
  string _msg;
begin
  _path = pathResolve(dataFile);
  _retVal = CSV_ReadToArray(_path, _size, _ptr);
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

/* vim: set ts=2 sw=2 tw=0 et fileencoding=iso8859-1 :*/

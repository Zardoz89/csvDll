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
  float data_f[25];

  int xx, yy;
  int tmp1;
  int tmp2;
  int tmp3;
  int tmp4;

  DynArray dyn;
begin
  mode_set(1024, 768, 32);

  // int8 bit array
  loadData("data.csv", &data_i8, sizeof(data_i8));

  write(0, 0, yy, 0, "int8 array");
  tmp1 = sizeof(data_i8) ;
  write(0, 100, yy, 0, &tmp1);
  yy += 10;
  for (xx = 0; xx < tmp1; xx++)
    write(0, (xx%20)*40, yy + (xx/20)*10, 0, &data_i8[xx]);
  end
  y += 20;


  // uint16 bit array
  loadData("data.csv", &data_u16, sizeof(data_u16));

  write(0, 0, yy, 0, "uint16 array");
  tmp2 = sizeof(data_u16) / 2;
  write(0, 100, yy, 0, &tmp2);
  yy += 10;
  for (xx = 0; xx < tmp2; xx++)
    write(0, (xx%20)*40, yy + (xx/20)*10, 0, &data_u16[xx]);
  end
  yy += 20;

  // int32 bit array
  loadData("data.csv", &data_i32, sizeof(data_i32));

  write(0, 0, yy, 0, "int32 array");
  tmp3 = sizeof(data_i32) / sizeof(int32);
  write(0, 100, yy, 0, &tmp3);
  yy += 10;
  for (xx = 0; xx < tmp3; xx++)
    write(0, (xx%20)*40, yy + (xx/20)*10, 0, &data_i32[xx]);
  end
  yy += 20;

  // float array
  loadData("dataf.csv", &data_f, sizeof(data_f));

  write(0, 0, yy, 0, "float array");
  tmp4 = sizeof(data_f) / sizeof(float);
  write(0, 100, yy, 0, &tmp4);
  yy += 10;
  for (xx = 0; xx < tmp4; xx++)
    write(0, (xx%10)*70, yy + (xx/10)*10, 0, &data_f[xx]);
  end
  yy += 30;

  // Dinamico de int32
  dyn = loadAndAllocateData("data2.csv");
  write(0, 0, yy, 0, "dynamic array from csv");
  write(0, 200, yy, 0, &dyn.length);
  yy += 10;
  for (xx = 0; xx < dyn.length; xx++)
    write(0, (xx%20)*40, yy + (xx/20)*10, 0, &dyn.data[xx]);
  end
  yy += 20;

  loop
    frame;
    if (keydown(_q) || keydown(_esc))
      let_me_alone();
      break;
    end
  end
end


/**
 * Reads a CSV file with data
 */
function int loadData(string _path, int32*_ptr, int _size)
private
  int _retVal = 0;
  string _msg;
begin
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


function int loadData(string _path, uint32*_ptr, int _size)
private
  int _retVal = 0;
  string _msg;
begin
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

function int loadData(string _path, int16*_ptr, int _size)
private
  int _retVal = 0;
  string _msg;
begin
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

function int loadData(string _path, uint16*_ptr, int _size)
private
  int _retVal = 0;
  string _msg;
begin
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

function int loadData(string _path, int8*_ptr, int _size)
private
  int _retVal = 0;
  string _msg;
begin
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

function int loadData(string _path, uint8*_ptr, int _size)
private
  int _retVal = 0;
  string _msg;
begin
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

function int loadData(string _path, float*_ptr, int _size)
private
  int _retVal = 0;
  string _msg;
begin
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
function DynArray loadAndAllocateData(string _path)
private
  int _retVal = 0;
  string _msg;
  DynArray _data;
begin
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

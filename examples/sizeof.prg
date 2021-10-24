compiler_options _use_cstyle_matrix, _use_cstyle;
program sizeof_wtf;

private
  int8 data_i8[40];
  int32 data_i32[40];
  uint32 data_u32[40];
  int sizes[100];
  int i = 0;
begin
  mode_set(800, 600);

  write(0, 0, y, 0, "sizeof int8 array");
  sizes[i] = sizeof(data_i8);
  write(0, 200, y, 0, offset sizes[i]);
  y += 10; i++;

  write(0, 0, y, 0, "sizeof int32 array");
  sizes[i] = sizeof(data_i32);
  write(0, 200, y, 0, offset sizes[i]);
  y += 10; i++;

  write(0, 0, y, 0, "sizeof uint32 array");
  sizes[i] = sizeof(data_u32);
  write(0, 200, y, 0, offset sizes[i]);
  y += 10; i++;

  write(0, 0, y, 0, "sizeof int8");
  sizes[i] = sizeof(int8);
  write(0, 200, y, 0, offset sizes[i]);
  y += 10; i++;

  write(0, 0, y, 0, "sizeof int32");
  sizes[i] = sizeof(int32);
  write(0, 200, y, 0, offset sizes[i]);
  y += 10; i++;

  loop
    frame;
    if (key(_q) || key(_esc))
      let_me_alone();
      break;
    end
  end
end


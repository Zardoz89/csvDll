program sizeof_wtf;

private
  int8 data_i8[39];
  int32 data_i32[39];
  uint32 data_u32[39];
  int tmp1;
  int tmp2;
  int tmp3;
begin
  set_mode(m800x600);

  write(0, 0, y, 0, "sizeof int8 array");
  tmp1 = sizeof(data_i8);
  write(0, 200, y, 0, offset tmp1);
  y += 10;

  write(0, 0, y, 0, "sizeof int32 array");
  tmp2 = sizeof(data_i32);
  write(0, 200, y, 0, offset tmp2);
  y += 10;

  write(0, 0, y, 0, "sizeof uint32 array");
  tmp3 = sizeof(data_u32);
  write(0, 200, y, 0, offset tmp3);

  loop
    frame;
    if (key(_q) || key(_esc))
      let_me_alone();
      break;
    end
  end
end


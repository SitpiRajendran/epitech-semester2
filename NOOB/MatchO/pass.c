ulong gen_key(long lParm1)

{
  uint local_10;
  uint local_c;

  local_c = 0;
  local_10 = 0;
  while (*(int *)(lParm1 + (ulong)local_10 * 4) != 0) {
    local_c = *(uint *)(lParm1 + (ulong)local_10 * 4) ^ local_c ^ 0xc0feb4b3;
    local_10 = local_10 + 1;
  }
  return (ulong)local_c;
}

undefined1 * get_flag(uint uParm1)

{
  uint local_c;

  local_c = 0;
  while (local_c < 0xb) {
    *(uint *)(g_flag + (long)(int)local_c * 4) = *(uint *)(g_flag + (long)(int)local_c * 4) ^ uParm1
    ;
    local_c = local_c + 1;
  }
  return g_flag;
}

undefined8 main(int iParm1,undefined8 *puParm2)

{
  undefined8 uVar1;
  long lVar2;
  size_t sVar3;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  uint local_10;
  uint local_c;
  
  if (iParm1 < 3) {
    puts("[^] Welcom to the SakiiR KeygenMe");
    printf("[^] Usage: %s USERNAME SERIAL\n",*puParm2);
    uVar1 = 0x2a;
  }
  else {
    local_68 = 0;
    local_60 = 0;
    local_58 = 0;
    local_50 = 0;
    local_48 = 0;
    local_40 = 0;
    local_38 = 0;
    local_30 = 0;
    local_28 = 0;
    local_20 = 0;
    strncpy((char *)&local_68,(char *)puParm2[1],0x30);
    lVar2 = strtol((char *)puParm2[2],(char **)0x0,0x10);
    local_c = (uint)lVar2;
    sVar3 = strlen((char *)&local_68);
    if (sVar3 < 0x10) {
      puts("Username must be at least 0x10 char length and less than 0x30 ..");
      uVar1 = 0x2a;
    }
    else {
      local_10 = gen_key(&local_68);
      if (local_c == local_10) {
        puts("Nice Your Flag is:");
        uVar1 = get_flag((ulong)local_c);
        printf("flag{%s}\n",uVar1);
      }
      else {
        printf("Ph4il!");
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}

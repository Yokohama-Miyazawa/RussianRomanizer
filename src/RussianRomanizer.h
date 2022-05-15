#pragma once
#include <Arduino.h>

String rom[4][16] = {
  {"A", "B", "V", "G", "D", "E", "Zh", "Z", "I", "I", "K", "L", "M", "N", "O", "P"},
  {"R", "S", "T", "U", "F", "Kh", "Tc", "Ch", "Sh", "Shch", "", "Y", "", "E", "Iu", "Ia"},
  {"a", "b", "v", "g", "d", "e", "zh", "z", "i", "i", "k", "l", "m", "n", "o", "p"},
  {"r", "s", "t", "u", "f", "kh", "tc", "ch", "sh", "shch", "", "y", "", "e", "iu", "ia"}
};

String rtor(const String str)
{
  const char *rus = str.c_str();
  String result = "";
  while (*rus != '\0')
  {
    if ((*rus & 0xF0) == 0xD0)
    { // ロシア語キリル文字は0xDXXX
      int upperByte = (int)(*rus & 0xFF);
      int lowerByte = (int)(*(rus + 1) & 0xFF);
      // printf("| %X %X %03X ", upperByte, lowerByte, ((upperByte << 8) | lowerByte) & 0x0FFF);
      // printf("%02X ", (((upperByte << 8) | lowerByte) & 0x0FF0) >> 4);
      switch ((((upperByte << 8) | lowerByte) & 0x0FF0) >> 4)
      {
      case 0x09:
        result += rom[0][lowerByte & 0x0F];
        break;
      case 0x0A:
        result += rom[1][lowerByte & 0x0F];
        break;
      case 0x0B:
        result += rom[2][lowerByte & 0x0F];
        break;
      case 0x18:
        result += rom[3][lowerByte & 0x0F];
        break;
      default:
        if ((((upperByte << 8) | lowerByte) & 0x0FFF) == 0x0081)
        { // Ё
          result += "E";
        }
        else if ((((upperByte << 8) | lowerByte) & 0x0FFF) == 0x0191)
        { // ё
          result += "e";
        }
        else
        {
          result += rus[0];
          result += rus[1];
        }
        break;
      }
      rus += 2;
    }
    else
    { // 0xDXXX以外
      result += rus[0];
      rus++;
    }
  }
  return result;
}

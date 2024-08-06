#pragma once

#include <FreeImage.h>
#include <iostream>
#include <string>
#include <queue>
#include <bitset>
#include <cmath>

class ImageStego{
public:
  ImageStego(const std::string &imageName);
  ~ImageStego();
  void encode(const std::string &textEncode,const std::string &outputName);
  void decode();
private:
  FIBITMAP *image;
  FREE_IMAGE_FORMAT filetype;
  const static int diffRange[];
  const static int bitSize[];
  void refillBits(std::queue<bool> &bits, const std::string &text, int &index);
  void encodeColors(bool &encodable, int &diff, int &color1, int &color2, std::queue<bool> &bits);
};

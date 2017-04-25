#define screenWidth 640
#define screenHeight 480
#define texWidth 64
#define texHeight 64

Uint32 buffer[screenHeight][screenWidth]; // y-coordinate first because it works per scanline
 std::vector texture[8];
 for(int i = 0; i < 8; i++)
 	texture[i].resize(texWidth * texHeight);
	for(int x = 0; x < texWidth; x++)




for(int y = 0; y < texHeight; y++)
{
  loadImage(texture[7], tw, th, "pics/colorstone.png");
}

-----------------------------------------
Before while
------------------------------------------

int texNum = worldMap[mapX][mapY] - 1; //1 subtracted from it so that texture 0 can be used!

   //calculate value of wallX
   double wallX; //where exactly the wall was hit
   if (side == 0) wallX = rayPosY + perpWallDist * rayDirY;
   else           wallX = rayPosX + perpWallDist * rayDirX;
   wallX -= floor((wallX));

   //x coordinate on the texture
   int texX = int(wallX * double(texWidth));
   if(side == 0 && rayDirX > 0) texX = texWidth - texX - 1;
   if(side == 1 && rayDirY < 0) texX = texWidth - texX - 1;
   for(int y = drawStart; y<drawEnd; y++)
  {
	int d = y * 256 - h * 128 + lineHeight * 128;  //256 and 128 factors to avoid floats
	int texY = ((d * texHeight) / lineHeight) / 256;
	Uint32 color = texture[texNum][texHeight * texY + texX];
	//make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
	if(side == 1) color = (color >> 1) & 8355711;
	buffer[y][x] = color;
  }
}

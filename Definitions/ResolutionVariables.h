#ifndef __RESOLUTIONVARIABLES_H__
#define __RESOLUTIONVARIABLES_H__

const int screenResHeight = 768;
const int screenResWidth = 1280;
const int pixelSizeX = 32;
const int pixelSizeY = 32;
const int borderLeft = 0;
const int borderRight = screenResWidth - 7 * pixelSizeX;
const int borderTop = 0;
const int borderBottom = screenResHeight - pixelSizeY;
const unsigned xPixels = screenResWidth / pixelSizeX;
const unsigned yPixels = screenResHeight / pixelSizeY;
const std::string gameResPath = "res/tileset4.png";
const std::string menuResPath = "res/tileset5.png"; // decide later
const std::string gameOverResPath = "res/tileset3.png";

const int buttonSizeX = 10 * pixelSizeX;
const int buttonSizeY = 4 * pixelSizeY;

#endif

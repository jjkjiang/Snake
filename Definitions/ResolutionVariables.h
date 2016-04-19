const int screenResHeight = 768;
const int screenResWidth = 1280;
const int pixelSizeX = 32;
const int pixelSizeY = 32;
const int borderLeft = pixelSizeX;
const int borderRight = screenResWidth - pixelSizeY;
const int borderTop = pixelSizeY;
const int borderBottom = screenResHeight - pixelSizeY;
const unsigned xPixels = screenResWidth / pixelSizeX;
const unsigned yPixels = screenResHeight / pixelSizeY;
const string gameResPath = "res\\tileset2.png";
const string menuResPath; // decide later
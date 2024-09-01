#-- TODO: Write conversion software to convert bitmap images to screen-readable code
#-- TODO: Learn how to communicate with Arduino over serial connection (and maybe wifi?)
#-- TODO: Possibly write code to automatically convert any image to correct size and 1-bit color depth and push to screen

import custom_exceptions as exceptions
from PIL import Image

maxWidth = 128
maxHeight = 64
testImage = "OLEDScreen/Example Bitmaps/potato_bitmap.bmp"

class BitmapImage:
    def __init__(self, image: str, pixelData: list = []):
        self.image = image
        self.pixelData = pixelData

def get_pixel_data(bitmapPath: str):
    numberOfBits: int = 8
    bitIndex: int = 0 + numberOfBits
    startIndex: int = 0
    pixelData: list
    hexPixels: bytearray = []
    with Image.open(bitmapPath) as bitmap:
        width, height = bitmap.size
        if width > maxWidth or height > maxHeight:
            raise exceptions.TooBig("This image is too large in at least one dimension. Please make sure it is 128x64 or smaller.")
        pixelData = ["0" if pixel == 0 else "1" for pixel in bitmap.getdata()]
    while bitIndex <= len(pixelData):
        hexPixels.append(pixelData[startIndex:bitIndex])
        startIndex += numberOfBits
        bitIndex += numberOfBits
    for index, group in enumerate(hexPixels):
        hexPixels[index] = bytes(hex(int("".join(group), 2)), encoding = "utf8")
    return hexPixels

if __name__ == "__main__":
    testBitmap = BitmapImage(testImage, get_pixel_data(testImage))
    print(testBitmap.pixelData)

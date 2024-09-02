#-- TODO: Learn how to communicate with Arduino over serial connection (and maybe wifi?)
#-- TODO: Possibly write code to automatically convert any image to correct size and 1-bit color depth and push to screen

"""
A small library to automatically convert bitmap images to a format readable by the Adafruit 128x64 OLED screen.
"""

import custom_exceptions as exceptions
from PIL import Image

maxWidth = 128
maxHeight = 64
testImage = "OLEDScreen/Example Bitmaps/potato_bitmap.bmp"

class BitmapImage:
    """A bitmap image with associated pixel data."""
    def __init__(self, image: str, pixelData: bytearray = []):
        self.image = image
        self.pixelData = pixelData

def get_pixel_data(bitmapPath: str):
    """Returns the pixel data in hexidecimal bytes."""
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

def chunk_bytes(bytesToChunk: bytearray, numberOfBytesPerLine: int):
    """Breaks the bytearray into chunks the specified size of number of bytes per line."""
    arraySize: int = len(bytesToChunk)
    chunkArray: list = []
    currentIndex: int = 0
    endIndex: int = 0 + numberOfBytesPerLine
    while endIndex < arraySize:
        chunkArray.append(bytesToChunk[currentIndex:endIndex])
        currentIndex += numberOfBytesPerLine
        endIndex += numberOfBytesPerLine
    chunkArray.append(bytesToChunk[currentIndex:])
    return chunkArray

def write_bytes(bytesToWrite: bytearray, variableName: str):
    """Writes the bytes as a C++ array to use with the Adafruit 128x64 OLED screen.\n
    Will hopefully be updated to serial communication and, perhaps some day, wifi
    being able to push the image to the screen."""
    newList: list = []
    with open("bytes.txt", "a") as byteWriter:
        for chunk in bytesToWrite:
            bytes: list = [f"{hex(int(byte, 16))}" for byte in chunk]
            newList.append(",".join(bytes))
        byteString: str = ",\n  ".join(newList)
        finalString: str = f"""const unsigned char PROGMEM {variableName}[] = {{\n  {byteString}
}};"""
        byteWriter.write(finalString)

if __name__ == "__main__":
    testBitmap = BitmapImage(testImage, get_pixel_data(testImage))
    write_bytes(chunk_bytes(testBitmap.pixelData, 40), "POTATO_BMP")

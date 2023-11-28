#include <zint.h>
#include <string.h>
int main() {
struct zint_symbol *zintSymbol = ZBarcode_Create();
zintSymbol->input_mode = 2090; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1008 
unsigned char bgcolour[]={30,0,0,0,0,255,255,239,255,255,255,255,255,255,255};
memcpy(zintSymbol->bgcolour, bgcolour, 15); // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1533 
zintSymbol->output_options = -1701142111; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1539 
zintSymbol->border_width = -1701143910; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1553 
zintSymbol->option_2 = -62907747; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1572 
zintSymbol->option_3 = 1111968314; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1588 
zintSymbol->dot_size = 2; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1597 
zintSymbol->border_width = 100; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1553 
zintSymbol->eci = 45; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1617 
unsigned char fgcolour[]={125,0,161,161,0,0,12,0,0,0,0,239,0,0,0};
memcpy(zintSymbol->fgcolour, fgcolour, 15); // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1634 
zintSymbol->eci = 0; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1617 
zintSymbol->guard_descent = 0; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1684 
zintSymbol->height = 0; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1698 
zintSymbol->option_1 = 0; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1736 
zintSymbol->show_hrt = 268436224; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1750 
unsigned char primary[]={71,0,0,0,0,137,137,153,0,70,70,70,0,0,0,255,255,255,163,255,255,94,86,0,0,0,127,0,0,0,0,0,0,0,28,255,255,255,255,255,158,0,0,0,255,161,161,63,154,154,154,154,154,157,154,64,252,189,0,0,154,154,161,154,154,154,154,154,154,157,154,64,252,189,0,0,152,154,154,159,154,154,64,0,59,255,161,255,255,103,0,255,255,255,255,255,255,255,255,255,255,255,255,255,8,8,1,0,0,32,0,0,1,0,0,0,0,246,0,30,4,0,0,0,1,0,244};
memcpy(zintSymbol->primary, primary, 127); // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1754 
zintSymbol->scale = 11; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1806 
zintSymbol->text_gap = 0; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1917 
zintSymbol->debug = 0; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1925 
zintSymbol->whitespace_height = 0; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1946 
zintSymbol->warn_level = 0; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1954 
zintSymbol->symbology = 58; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1979 
zintSymbol->dpmm = 2; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:2117 
unsigned char barcodeData[]={91,93,67,67,67,67,67,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,67,67,67,67,67,67,67,67,64,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,37,37,67,37,67,37,37,37,37,37,37,37,37,37,37,37,37,37,37,76,76,76,67,67,67,67,67,67,67,67,37,37,67,37,67,37,37,37,37,37,37,37,37,37,37,37,37,37,37,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,48,48,48,48,48,48,48,51,50,56,54,49,55,49,48,42,51,56,51,53,53,54,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,49,53,53,56,49,54,49,54,50,76,76,76,76,76,67,67,37,37,67,37,67,37,37,37,37,37,37,37,37,37,37,37,37,37,37,76,76,76,67,67,67,67,67,67,67,67,37,37,67,37,67,37,37,37,37,37,37,37,37,37,37,37,37,37,37,76,76,76,76,76,76,76,76,76,76,41,33,49,54,54,49,48,53,53,55,55,55,91,55,50,51,93,84,53};
ZBarcode_Encode(zintSymbol, barcodeData, 325);
ZBarcode_Delete(zintSymbol);
return 0;
}

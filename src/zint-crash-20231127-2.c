#include <zint.h>
#include <string.h>
int main() {
struct zint_symbol *zintSymbol = ZBarcode_Create();
zintSymbol->input_mode = 0; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1008 
unsigned char bgcolour[]={0,0,0,0,107,107,107,107,107,107,107,107,107,107,107};
memcpy(zintSymbol->bgcolour, bgcolour, 15); // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1533 
zintSymbol->output_options = 40528747; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1539 
zintSymbol->border_width = -741146624; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1553 
zintSymbol->option_2 = 10; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1572 
zintSymbol->option_3 = -218959269; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1588 
zintSymbol->dot_size = 2; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1597 
zintSymbol->border_width = 0; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1553 
zintSymbol->eci = 0; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1617 
unsigned char fgcolour[]={0,0,0,0,108,0,0,0,45,0,0,0,0,0,0};
memcpy(zintSymbol->fgcolour, fgcolour, 15); // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1634 
zintSymbol->eci = 0; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1617 
zintSymbol->guard_descent = 0; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1684 
zintSymbol->height = 0; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1698 
zintSymbol->option_1 = 26368; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1736 
zintSymbol->show_hrt = 1802201856; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1750 
unsigned char primary[]={107,107,107,107,107,107,107,107,107,107,107,107,107,107,36,107,107,107,107,107,43,107,107,107,107,111,149,141,107,107,40,0,0,0,179,107,107,107,107,107,107,107,107,107,99,115,0,0,0,107,107,153,107,107,107,107,63,39,39,35,39,47,107,107,107,107,107,0,0,0,0,107,107,107,107,107,107,107,107,107,107,149,157,107,107,107,107,107,119,119,119,134,119,119,119,119,119,119,119,119,119,119,119,119,1,64,255,255,255,255,255,255,255,26,119,119,119,119,255,4,119,119,119,119,247,119,119};
memcpy(zintSymbol->primary, primary, 127); // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1754 
zintSymbol->scale = 2; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1806 
zintSymbol->text_gap = 0; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1917 
zintSymbol->debug = 0; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1925 
zintSymbol->whitespace_height = 0; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1946 
zintSymbol->warn_level = 1802201963; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1954 
zintSymbol->symbology = 141; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1979 
zintSymbol->dpmm = 0; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:2117 
unsigned char barcodeData[]={107,107,107,107,107,48,1,0,0,92,107,107,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,107,107,107,107,107,107,35,0,0,199,0,103,0,0,0,35,75,107,114,114,141,144};
ZBarcode_Encode(zintSymbol, barcodeData, 90);
ZBarcode_Delete(zintSymbol);
return 0;
}

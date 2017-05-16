#ifndef MAIN_H
#define MAIN_H

#include <stdint.h>
#include <fileioc.h>

typedef struct {
    char     outName[9];
    char     inName[9];
    
    uint8_t  nestedBlocks;
    uint8_t  amountOfUsedCRoutines;
    uint8_t  *programData;
    uint8_t  programDataData[40000];
    uint8_t  *programPtr;
    uint8_t  *programPtrBackup;
    uint8_t  *programDataPtr;
    uint8_t  messageIndex;
    uint8_t  amountOfCRoutinesUsed;
    uint8_t  CRoutinesStack[100];
    
    uint24_t *dataOffsetStack[500];
    uint24_t dataOffsetElements;
    uint24_t currentLine;
    uint24_t programSize;
    
    ti_var_t inPrgm;
    ti_var_t outPrgm;
    
    bool     gotName;
    bool     gotIconDescription;
    bool     usedCodeAfterHeader;
    bool     lastTokenIsReturn;
    
    bool     usedAlreadyRand;
    uint24_t randAddr;
    
    bool     usedAlreadyGetKeyFast;
    uint24_t getKeyFastAddr;
} ice_t;

typedef struct {
    uint8_t  numberArgument;
    uint8_t  *programPtr;
    
    bool     inString;
    bool     inFunction;
    bool     outputIsNumber;
} expr_t;

#define MESSAGE_HEIGHT       10
#define iceMessageLine       (3 + (ice.messageIndex += MESSAGE_HEIGHT))
#define iceMessageNewLine()  do { (iceMessageLine); } while(0)

extern ice_t ice;
extern expr_t expr;

void preScanProgram(ti_var_t);

void CHeaderData(void);
void CProgramHeader(void);
void MultWithNumber(uint24_t number, uint24_t *programPtr);
void RandRoutine(void);
void KeypadRoutine(void);

extern uint8_t AndOrXorData[16];

#endif


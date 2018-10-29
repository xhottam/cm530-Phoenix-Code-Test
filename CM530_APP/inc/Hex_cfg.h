/*
 * Hex_cfg.h
 *
 *  Created on: 12 Jul 2017
 *      Author: E1193262
 */

#ifndef CM530_APP_INC_HEX_CFG_H_
#define CM530_APP_INC_HEX_CFG_H_




 //--------------------------------------------------------------------
 // Define which pins(sevo IDS go with which joint

 #define cRRCoxaPin      8   //Rear Right leg Hip Horizontal
 #define cRRFemurPin     10   //Rear Right leg Hip Vertical
 #define cRRTibiaPin     12   //Rear Right leg Knee

 #define cRMCoxaPin      14  //Middle Right leg Hip Horizontal
 #define cRMFemurPin     16  //Middle Right leg Hip Vertical
 #define cRMTibiaPin     18  //Middle Right leg Knee

 #define cRFCoxaPin      2  //Front Right leg Hip Horizontal
 #define cRFFemurPin     4  //Front Right leg Hip Vertical
 #define cRFTibiaPin     6   //Front Right leg Knee

 #define cLRCoxaPin      7   //Rear Left leg Hip Horizontal
 #define cLRFemurPin     9   //Rear Left leg Hip Vertical
 #define cLRTibiaPin     11   //Rear Left leg Knee

 #define cLMCoxaPin      13   //Middle Left leg Hip Horizontal
 #define cLMFemurPin     15   //Middle Left leg Hip Vertical
 #define cLMTibiaPin     17  //Middle Left leg Knee

 #define cLFCoxaPin      1   //Front Left leg Hip Horizontal
 #define cLFFemurPin     3   //Front Left leg Hip Vertical
 #define cLFTibiaPin     5   //Front Left leg Knee


static const byte cPinTable[] = { cRRCoxaPin, cRMCoxaPin, cRFCoxaPin,
		cLRCoxaPin, cLMCoxaPin, cLFCoxaPin, cRRFemurPin, cRMFemurPin,
		cRFFemurPin, cLRFemurPin, cLMFemurPin, cLFFemurPin, cRRTibiaPin,
		cRMTibiaPin, cRFTibiaPin, cLRTibiaPin, cLMTibiaPin, cLFTibiaPin

};



#endif /* CM530_APP_INC_HEX_CFG_H_ */

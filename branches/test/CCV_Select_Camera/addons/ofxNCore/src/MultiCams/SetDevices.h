//! SetDevices.h
/*!
*  
*
*  Created by Yishi Guo on 05/31/2011.
*  Copyright 2011 NUI Group. All rights reserved.
*
*/

#ifndef SET_DEVICES_H_
#define SET_DEVICES_H_

#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "Controls/ofxGuiTypes.h"
#include "Controls/ofxgui.h"
#include "MultiCams/CamsUtils.h"

class SetDevices : public ofxGuiListener {
	//! Controls id
	enum {
		devicesListPanel,
		devicesListPanel_grid,
		devicesListPanel_arrow_up,
		devicesListPanel_arrow_down,

		cameraDisplayPanel,
		cameraDisplayPanel_info,
		cameraDisplayPanel_grid,

		informationPanel,

		settingsPanel,
		settingsPanel_reset,
		settingsPanel_save,
		settingsPanel_cancel,
	};
public:
	//! Constructor
	SetDevices();
	//! Destructor
	~SetDevices();

	/*************************************************
	 *               PUBLIC METHODS
	 *************************************************/
	// SETUP
	void setup();
	void update();

	// PASSIN
	void passInCamsUtils( CamsUtils* utils );

	// MOUSE EVENTS
	void _mousePressed( ofMouseEventArgs &e );
	void _mouseDragged( ofMouseEventArgs &e );
	void _mouseReleased( ofMouseEventArgs &e );

	// KEY EVENTS
	void _keyPressed( ofKeyEventArgs &e );
	void _keyReleased( ofKeyEventArgs &e );

	// GUI
	void handleGui( int parameterId, int task, void* data, int length );
	void setupControls();
	void addPanels();
	void addPanel( int parameterId );
	void removePanels();
	void removePanel( int parameterId );
	void showInterface( bool bShow = true );

	// DRAWING
	void draw();

	// XML
	void LoadXMLSettings();
	void SaveXMLSettings();
	/*************************************************
	 *               PUBLIC STUFF
	 *************************************************/
public:
	//! Controls
	ofxGui* controls;

	//! Device list control
	ofxGuiGrid* devGrid;

	//! Show interface
	bool	bShowInterface;


	/*************************************************
	 *               PRIVATE STUFF
	 *************************************************/
private:

	////////////////
	// TEST STUFF
	int testInt;
	ofTrueTypeFont testFont;

	//! CamsUtils
	CamsUtils* utils;

};

#endif
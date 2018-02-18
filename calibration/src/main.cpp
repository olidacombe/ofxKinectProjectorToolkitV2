#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	//ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

    ofGLFWWindowSettings settings;

    settings.width = 1024;
    settings.height = 768;
    shared_ptr<ofAppBaseWindow> monitorWindow = ofCreateWindow(settings);
    settings.shareContextWith = monitorWindow;
    shared_ptr<ofAppBaseWindow> projectorWindow = ofCreateWindow(settings);
    projectorWindow->setVerticalSync(false);

    shared_ptr<ofApp> mainApp(new ofApp);
    //mainApp->setupGui();
    ofAddListener(monitorWindow->events().draw, mainApp.get(), &ofApp::drawMonitor);

    ofRunApp(projectorWindow, mainApp);
    ofRunMainLoop();


    
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	//ofRunApp(new ofApp());

}

#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	//ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

    ofGLFWWindowSettings settings;

    settings.width = PROJECTOR_RESOLUTION_X;
    settings.height = PROJECTOR_RESOLUTION_Y;
    shared_ptr<ofAppBaseWindow> projectorWindow = ofCreateWindow(settings);
    settings.shareContextWith = projectorWindow;
    shared_ptr<ofAppBaseWindow> monitorWindow = ofCreateWindow(settings);
    monitorWindow->setVerticalSync(false);

    shared_ptr<ofApp> mainApp(new ofApp);
    ofAddListener(projectorWindow->events().draw, mainApp.get(), &ofApp::drawProjector);

    ofRunApp(monitorWindow, mainApp);
    ofRunMainLoop();

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	//ofRunApp(new ofApp());

}

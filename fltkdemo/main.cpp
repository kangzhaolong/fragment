
#include <iostream>
using namespace std;

#include "cmainapp.h"

int main (int argc, char *argv[])
{ 
	CMainApp* app = CMainApp::GetInstance();
    app->Init();
    app->Create();
    app->Run();
    app->Destroy();
    delete app;
    app = NULL;
}

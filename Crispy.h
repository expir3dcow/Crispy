#include <string>
#include <string.h>
#include <jni.h>
#include <android/log.h>
#include <dlfcn.h>
#include "mcpelauncher.h"

string version_name = "Crispy v1.0";

static string (*Name_Real)(void *p);

string versionNameHook(){
  return version_name;
}


//Defined functions



namespace Crispy{

  void setVersionName(String version);
  
  void setVersionName(String version){
    version_name = version;
    void* handle = dlsym(RTLD_DEFAULT,"_ZN6Common20getGameVersionStringEv");
    mcpelauncher_hook(handle,(void*)&versionNameHook,(void**)&Name_Real);
  }

}

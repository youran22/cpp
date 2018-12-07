#include <jni.h>
#include <errno.h>
#include <dlfcn.h>

#include <android_native_app_glue.h>

void android_main(struct android_app* state) {

    // Make sure glue isn't stripped.
    app_dummy();

    void* soAdd = dlopen("/data/data/com.example.native_activity/lib/libfkAdd.so",RTLD_NOW);
    void* soMain = dlopen("/data/data/com.example.native_activity/lib/libmain.so",RTLD_NOW);

    void (*fp_android_main)(struct android_app*) =
    		(void (*)(struct android_app*))dlsym(soMain,"android_main");

    fp_android_main(state);

    dlclose(soMain);
    dlclose(soAdd);
}

#include <jni.h>
#include <string>

extern "C" {
extern int p_main(int argc, const char *argv[]);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_zhufk_bsdiff_BsPatcher_bsPatch(JNIEnv *env, jclass type,jstring oldApk_, jstring patch_,jstring output_) {
    const char *oldApk = env->GetStringUTFChars(oldApk_, 0);
    const char *patch = env->GetStringUTFChars(patch_, 0);
    const char *output = env->GetStringUTFChars(output_, 0);

    // bspatch, oldfile, newfile, patchfile
    const char *argv[] = {"", oldApk, output, patch};
    p_main(4, argv);

    env->ReleaseStringUTFChars(oldApk_, oldApk);
    env->ReleaseStringUTFChars(patch_, patch);
    env->ReleaseStringUTFChars(output_, output);
}




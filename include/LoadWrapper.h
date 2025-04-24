#pragma once
#include <PVRTModelPOD.h>

#ifdef _WIN32
    #define EXPORT __declspec(dllexport)
#else
    #define EXPORT __attribute__((visibility("default")))
#endif

SPODScene* LoadPod(char* path);

extern "C"
{
    EXPORT struct SPODScene* load_pod(char* path);

    EXPORT struct SPODScene* load_pod_deinterleaved(char* path);

    EXPORT void destroy_pod(SPODScene* scene);
}
#include <LoadWrapper.h>

SPODScene* LoadPod(char* path)
{
    CPVRTModelPOD* model = new CPVRTModelPOD();
    model->ReadFromFile(path, NULL, 0, NULL, 0);

    return (SPODScene*)model;
}

SPODScene* LoadPodDeinterleaved(char* path)
{
    CPVRTModelPOD* model = new CPVRTModelPOD();
    model->ReadFromFile(path, NULL, 0, NULL, 0);

    for (unsigned int i = 0; i < model->nNumMesh; i++)
    {
        if (model->pMesh[i].pInterleaved)
        {
            PVRTModelPODToggleInterleaved(model->pMesh[i]);
        }
    }

    return (SPODScene*)model;
}

void DestroyPod(SPODScene* scene)
{
    CPVRTModelPOD* model = (CPVRTModelPOD*)scene;
    model->Destroy();
}

extern "C"
{
    struct SPODScene* load_pod(char* path)
    {
        return LoadPod(path);
    }

    struct SPODScene* load_pod_deinterleaved(char* path)
    {
        return LoadPodDeinterleaved(path);
    }

    void destroy_pod(SPODScene* scene)
    {
        DestroyPod(scene);
    }
}